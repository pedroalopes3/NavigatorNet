#!/usr/bin/env python3
"""
NavNet KPI Analyser
===================
Reads a ROS 2 bag (MCAP format) and produces:
  - KPI summary  →  kpi_summary.txt
  - Error-over-time plot
  - Error histogram
  - Trajectory map (GPS vs NavNet, on OpenStreetMap tiles)
  - Altitude comparison plot
  - CDF of position error
  - Inlier-rate proxy (estimation availability)

Usage:
    python3 analyse_bag.py <path_to_bag_dir_or_mcap_file> [--out ./results]

Dependencies:
    pip install rosbags matplotlib numpy scipy contextily geopandas shapely pandas
"""

import argparse
import math
import os
import sys
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import matplotlib.ticker as mticker
import numpy as np
import pandas as pd
from matplotlib.collections import LineCollection
from matplotlib.colors import Normalize

# ── optional deps (graceful fallback) ─────────────────────────────────────────
try:
    import contextily as cx
    HAS_CONTEXTILY = True
except ImportError:
    HAS_CONTEXTILY = False

try:
    import geopandas as gpd
    from shapely.geometry import LineString, Point
    HAS_GEO = True
except ImportError:
    HAS_GEO = False

from rosbags.highlevel import AnyReader
from rosbags.typesys import Stores, get_typestore

# ── constants ──────────────────────────────────────────────────────────────────
GPS_TOPIC    = "/map/gps_raw"
VISION_TOPIC = "/map/navnet_estimation"
FALSE_POS_THRESHOLD_M = 50.0   # metres — estimation further than this = false positive
EARTH_R = 6_371_000.0


# ══════════════════════════════════════════════════════════════════════════════
# Helpers
# ══════════════════════════════════════════════════════════════════════════════

def haversine(lat1, lon1, lat2, lon2):
    phi1, phi2 = math.radians(lat1), math.radians(lat2)
    dphi  = math.radians(lat2 - lat1)
    dlam  = math.radians(lon2 - lon1)
    a = math.sin(dphi/2)**2 + math.cos(phi1)*math.cos(phi2)*math.sin(dlam/2)**2
    return EARTH_R * 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))


def stamp_to_sec(stamp):
    return stamp.sec + stamp.nanosec * 1e-9


def read_bag(bag_path: Path):
    typestore = get_typestore(Stores.ROS2_HUMBLE)
    gps_rows, vis_rows = [], []

    with AnyReader([bag_path], default_typestore=typestore) as reader:
        connections = [c for c in reader.connections
                       if c.topic in (GPS_TOPIC, VISION_TOPIC)]
        for conn, timestamp, rawdata in reader.messages(connections=connections):
            msg = reader.deserialize(rawdata, conn.msgtype)
            t   = stamp_to_sec(msg.header.stamp)
            row = (t, msg.latitude, msg.longitude, msg.altitude)
            if conn.topic == GPS_TOPIC:
                gps_rows.append(row)
            else:
                vis_rows.append(row)

    gps = pd.DataFrame(gps_rows, columns=["t","lat","lon","alt"]).sort_values("t")
    vis = pd.DataFrame(vis_rows, columns=["t","lat","lon","alt"]).sort_values("t")
    return gps, vis


def sync_nearest(gps: pd.DataFrame, vis: pd.DataFrame, max_dt=1.0):
    """For each vision estimate find the nearest GPS stamp within max_dt seconds."""
    rows = []
    gps_t = gps["t"].values
    for _, v in vis.iterrows():
        idx = np.argmin(np.abs(gps_t - v.t))
        dt  = abs(gps_t[idx] - v.t)
        if dt <= max_dt:
            g = gps.iloc[idx]
            rows.append({
                "t":        v.t,
                "gps_lat":  g.lat,  "gps_lon":  g.lon,  "gps_alt":  g.alt,
                "vis_lat":  v.lat,  "vis_lon":  v.lon,  "vis_alt":  v.alt,
                "error_m":  haversine(g.lat, g.lon, v.lat, v.lon),
                "alt_err_m": abs(v.alt - g.alt),
            })
    return pd.DataFrame(rows)


# ══════════════════════════════════════════════════════════════════════════════
# KPI computation
# ══════════════════════════════════════════════════════════════════════════════

def compute_kpis(df: pd.DataFrame, n_gps: int, fp_threshold: float = FALSE_POS_THRESHOLD_M):
    fp_mask    = df["error_m"] > fp_threshold
    n_est      = len(df)
    n_fp       = fp_mask.sum()
    good       = df[~fp_mask]["error_m"]

    duration   = df["t"].max() - df["t"].min() if n_est > 1 else 0.0
    hz         = n_est / duration if duration > 0 else float("nan")

    kpis = {
        "total_gps_samples":        n_gps,
        "total_estimations":        n_est,
        "estimation_rate_hz":       hz,
        "false_positives":          int(n_fp),
        "false_positive_pct":       100.0 * n_fp / n_est if n_est else 0.0,
        "mean_error_m":             good.mean()   if len(good) else float("nan"),
        "median_error_m":           good.median() if len(good) else float("nan"),
        "std_error_m":              good.std()    if len(good) else float("nan"),
        "min_error_m":              good.min()    if len(good) else float("nan"),
        "max_error_m":              good.max()    if len(good) else float("nan"),
        "p90_error_m":              float(np.percentile(good, 90)) if len(good) else float("nan"),
        "p95_error_m":              float(np.percentile(good, 95)) if len(good) else float("nan"),
        "rmse_m":                   float(np.sqrt((good**2).mean())) if len(good) else float("nan"),
        "mean_alt_error_m":         df["alt_err_m"].mean(),
        "fp_threshold_m":           fp_threshold,
        "duration_s":               duration,
    }
    return kpis, fp_mask


def write_txt(kpis: dict, out_dir: Path):
    lines = [
        "╔══════════════════════════════════════════════════╗",
        "║          NavNet — KPI Summary Report             ║",
        "╚══════════════════════════════════════════════════╝",
        "",
        f"  Run duration          : {kpis['duration_s']:.1f} s",
        f"  GPS samples           : {kpis['total_gps_samples']}",
        f"  NavNet estimations    : {kpis['total_estimations']}",
        f"  Estimation rate       : {kpis['estimation_rate_hz']:.2f} Hz",
        "",
        "── Position Error (inliers only) ─────────────────",
        f"  Mean error            : {kpis['mean_error_m']:.2f} m",
        f"  Median error          : {kpis['median_error_m']:.2f} m",
        f"  Std deviation         : {kpis['std_error_m']:.2f} m",
        f"  RMSE                  : {kpis['rmse_m']:.2f} m",
        f"  Min error             : {kpis['min_error_m']:.2f} m",
        f"  Max error             : {kpis['max_error_m']:.2f} m",
        f"  P90 error             : {kpis['p90_error_m']:.2f} m",
        f"  P95 error             : {kpis['p95_error_m']:.2f} m",
        "",
        "── Altitude ──────────────────────────────────────",
        f"  Mean altitude error   : {kpis['mean_alt_error_m']:.2f} m",
        "",
        "── False Positives ───────────────────────────────",
        f"  Threshold             : {kpis['fp_threshold_m']:.0f} m",
        f"  Count                 : {kpis['false_positives']}",
        f"  Percentage            : {kpis['false_positive_pct']:.1f} %",
        "",
    ]
    path = out_dir / "kpi_summary.txt"
    path.write_text("\n".join(lines))
    print(f"[✓] KPI summary  → {path}")


# ══════════════════════════════════════════════════════════════════════════════
# Plots
# ══════════════════════════════════════════════════════════════════════════════

STYLE = {
    "bg":       "#0f1117",
    "panel":    "#1a1d27",
    "accent1":  "#00e5ff",
    "accent2":  "#ff4081",
    "accent3":  "#69ff47",
    "text":     "#e0e0e0",
    "grid":     "#2a2d3a",
    "fp":       "#ff6b35",
}

def _apply_style(fig, axes):
    fig.patch.set_facecolor(STYLE["bg"])
    for ax in (axes if hasattr(axes, "__iter__") else [axes]):
        ax.set_facecolor(STYLE["panel"])
        ax.tick_params(colors=STYLE["text"], labelsize=8)
        ax.xaxis.label.set_color(STYLE["text"])
        ax.yaxis.label.set_color(STYLE["text"])
        if ax.get_title():
            ax.title.set_color(STYLE["text"])
        for spine in ax.spines.values():
            spine.set_edgecolor(STYLE["grid"])
        ax.grid(color=STYLE["grid"], linewidth=0.5, linestyle="--", alpha=0.6)


# ── 1. Error over time ────────────────────────────────────────────────────────
def plot_error_time(df: pd.DataFrame, fp_mask, out_dir: Path):
    t0   = df["t"].min()
    t_s  = df["t"] - t0
    good = ~fp_mask

    fig, ax = plt.subplots(figsize=(12, 4))
    ax.fill_between(t_s[good], 0, df["error_m"][good],
                    alpha=0.25, color=STYLE["accent1"])
    ax.plot(t_s[good], df["error_m"][good],
            color=STYLE["accent1"], linewidth=1.2, label="Position error (m)")
    if fp_mask.any():
        ax.scatter(t_s[fp_mask], df["error_m"][fp_mask],
                   color=STYLE["fp"], zorder=5, s=30, label="False positive")

    # rolling mean
    roll = df["error_m"][good].rolling(window=20, min_periods=1).mean()
    ax.plot(t_s[good], roll, color=STYLE["accent2"],
            linewidth=1.5, linestyle="--", label="Rolling mean (20)")

    ax.axhline(df["error_m"][good].mean(), color=STYLE["accent3"],
               linewidth=1, linestyle=":", label=f"Mean = {df['error_m'][good].mean():.1f} m")

    ax.set_xlabel("Time (s)")
    ax.set_ylabel("Error (m)")
    ax.set_title("Position Error Over Time")
    ax.legend(fontsize=8, facecolor=STYLE["panel"], labelcolor=STYLE["text"])
    _apply_style(fig, ax)
    fig.tight_layout()
    p = out_dir / "error_time.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Error/time plot → {p}")


# ── 2. Error histogram ────────────────────────────────────────────────────────
def plot_histogram(df: pd.DataFrame, fp_mask, kpis, out_dir: Path):
    good_err = df["error_m"][~fp_mask]

    fig, ax = plt.subplots(figsize=(8, 5))
    n, bins, patches = ax.hist(good_err, bins=40,
                                color=STYLE["accent1"], alpha=0.8, edgecolor=STYLE["bg"])

    # colour bars by magnitude
    norm = Normalize(vmin=bins[0], vmax=bins[-1])
    cmap = plt.cm.plasma
    for patch, left in zip(patches, bins[:-1]):
        patch.set_facecolor(cmap(norm(left)))

    for label, val, color in [
        ("Mean",   kpis["mean_error_m"],   STYLE["accent2"]),
        ("Median", kpis["median_error_m"], STYLE["accent3"]),
        ("P90",    kpis["p90_error_m"],    STYLE["fp"]),
    ]:
        ax.axvline(val, color=color, linewidth=1.5, linestyle="--",
                   label=f"{label} = {val:.1f} m")

    ax.set_xlabel("Position Error (m)")
    ax.set_ylabel("Count")
    ax.set_title("Error Distribution Histogram")
    ax.legend(fontsize=8, facecolor=STYLE["panel"], labelcolor=STYLE["text"])
    _apply_style(fig, ax)
    fig.tight_layout()
    p = out_dir / "error_histogram.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Histogram      → {p}")


# ── 3. CDF ────────────────────────────────────────────────────────────────────
def plot_cdf(df: pd.DataFrame, fp_mask, kpis, out_dir: Path):
    good_err = np.sort(df["error_m"][~fp_mask].values)
    cdf = np.arange(1, len(good_err)+1) / len(good_err)

    fig, ax = plt.subplots(figsize=(8, 5))
    ax.plot(good_err, cdf * 100, color=STYLE["accent1"], linewidth=2)
    ax.fill_between(good_err, 0, cdf * 100, alpha=0.15, color=STYLE["accent1"])

    for pct, color in [(50, STYLE["accent3"]), (90, STYLE["fp"]), (95, STYLE["accent2"])]:
        val = np.percentile(good_err, pct)
        ax.axvline(val, color=color, linewidth=1.2, linestyle="--",
                   label=f"P{pct} = {val:.1f} m")
        ax.axhline(pct, color=color, linewidth=0.6, linestyle=":", alpha=0.5)

    ax.set_xlabel("Position Error (m)")
    ax.set_ylabel("Cumulative %")
    ax.set_title("Cumulative Distribution of Position Error")
    ax.set_ylim(0, 101)
    ax.legend(fontsize=8, facecolor=STYLE["panel"], labelcolor=STYLE["text"])
    _apply_style(fig, ax)
    fig.tight_layout()
    p = out_dir / "error_cdf.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] CDF plot       → {p}")


# ── 4. Altitude comparison ────────────────────────────────────────────────────
def plot_altitude(df: pd.DataFrame, out_dir: Path):
    t0  = df["t"].min()
    t_s = df["t"] - t0

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 6), sharex=True)

    ax1.plot(t_s, df["gps_alt"], color=STYLE["accent1"],
             linewidth=1.2, label="GPS altitude (m)")
    ax1.plot(t_s, df["vis_alt"], color=STYLE["accent2"],
             linewidth=1.2, linestyle="--", label="NavNet altitude (m)")
    ax1.set_ylabel("Altitude (m)")
    ax1.set_title("Altitude Comparison")
    ax1.legend(fontsize=8, facecolor=STYLE["panel"], labelcolor=STYLE["text"])

    ax2.fill_between(t_s, 0, df["alt_err_m"],
                     alpha=0.4, color=STYLE["accent3"])
    ax2.plot(t_s, df["alt_err_m"], color=STYLE["accent3"], linewidth=1)
    ax2.set_xlabel("Time (s)")
    ax2.set_ylabel("Altitude error (m)")
    ax2.set_title("Altitude Error")

    _apply_style(fig, [ax1, ax2])
    fig.tight_layout()
    p = out_dir / "altitude.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Altitude plot  → {p}")


# ── 5. Trajectory map ─────────────────────────────────────────────────────────
def plot_trajectory(df: pd.DataFrame, fp_mask, out_dir: Path):
    fig, ax = plt.subplots(figsize=(10, 10))

    gps_lons = df["gps_lon"].values
    gps_lats = df["gps_lat"].values
    vis_lons  = df["vis_lon"].values
    vis_lats  = df["vis_lat"].values

    if HAS_GEO and HAS_CONTEXTILY:
        # reproject to WebMercator for contextily basemap
        gdf_gps = gpd.GeoDataFrame(
            geometry=[Point(lo, la) for lo, la in zip(gps_lons, gps_lats)],
            crs="EPSG:4326"
        ).to_crs("EPSG:3857")
        gdf_vis = gpd.GeoDataFrame(
            geometry=[Point(lo, la) for lo, la in zip(vis_lons, vis_lats)],
            crs="EPSG:4326"
        ).to_crs("EPSG:3857")

        xs_g = [p.x for p in gdf_gps.geometry]
        ys_g = [p.y for p in gdf_gps.geometry]
        xs_v = [p.x for p in gdf_vis.geometry]
        ys_v = [p.y for p in gdf_vis.geometry]

        ax.plot(xs_g, ys_g, color=STYLE["accent1"], linewidth=2,
                label="GPS (ground truth)", zorder=3)
        ax.plot(xs_v, ys_v, color=STYLE["accent2"], linewidth=1.5,
                linestyle="--", label="NavNet estimation", zorder=3, alpha=0.85)

        # false positives
        if fp_mask.any():
            fp_gdf = gdf_vis[fp_mask.values]
            ax.scatter([p.x for p in fp_gdf.geometry],
                       [p.y for p in fp_gdf.geometry],
                       color=STYLE["fp"], zorder=5, s=25, label="False positive")

        # start/end markers
        ax.scatter(xs_g[0],  ys_g[0],  color=STYLE["accent3"], s=80, zorder=6, marker="^")
        ax.scatter(xs_g[-1], ys_g[-1], color=STYLE["accent2"], s=80, zorder=6, marker="s")

        try:
            cx.add_basemap(ax, crs="EPSG:3857",
                           source=cx.providers.OpenStreetMap.Mapnik,
                           zoom="auto", alpha=0.6)
        except Exception:
            pass  # offline — no tiles

        ax.set_xlabel("Easting (m)")
        ax.set_ylabel("Northing (m)")

    else:
        # pure matplotlib fallback (lat/lon degrees)
        ax.plot(gps_lons, gps_lats, color=STYLE["accent1"],
                linewidth=2, label="GPS (ground truth)")
        ax.plot(vis_lons, vis_lats, color=STYLE["accent2"],
                linewidth=1.5, linestyle="--", label="NavNet estimation", alpha=0.85)
        if fp_mask.any():
            ax.scatter(vis_lons[fp_mask], vis_lats[fp_mask],
                       color=STYLE["fp"], s=25, zorder=5, label="False positive")
        ax.set_xlabel("Longitude (°)")
        ax.set_ylabel("Latitude (°)")
        ax.set_aspect("equal")

    ax.set_title("Drone Trajectory: GPS vs NavNet", color=STYLE["text"])
    ax.legend(fontsize=9, facecolor=STYLE["panel"], labelcolor=STYLE["text"])
    _apply_style(fig, ax)
    fig.tight_layout()
    p = out_dir / "trajectory_map.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Trajectory map → {p}")


# ── 6. Error vector field (lat/lon bias) ──────────────────────────────────────
def plot_error_vectors(df: pd.DataFrame, fp_mask, out_dir: Path):
    good = df[~fp_mask].copy()
    # error components in degrees (small angle ok)
    dlat = good["vis_lat"] - good["gps_lat"]
    dlon = good["vis_lon"] - good["gps_lon"]

    fig, axes = plt.subplots(1, 2, figsize=(12, 5))

    t0 = good["t"].min()
    t_s = good["t"] - t0

    axes[0].plot(t_s, dlat * 111_000, color=STYLE["accent1"],
                 linewidth=1, label="ΔLat (m)")
    axes[0].plot(t_s, dlon * 111_000 * np.cos(np.radians(good["gps_lat"].mean())),
                 color=STYLE["accent2"], linewidth=1, label="ΔLon (m)")
    axes[0].axhline(0, color=STYLE["grid"], linewidth=0.8)
    axes[0].set_xlabel("Time (s)")
    axes[0].set_ylabel("Error component (m)")
    axes[0].set_title("Lat / Lon Error Components Over Time")
    axes[0].legend(fontsize=8, facecolor=STYLE["panel"], labelcolor=STYLE["text"])

    axes[1].scatter(dlon * 111_000, dlat * 111_000,
                    c=t_s, cmap="plasma", s=8, alpha=0.7)
    axes[1].axhline(0, color=STYLE["grid"], linewidth=0.8)
    axes[1].axvline(0, color=STYLE["grid"], linewidth=0.8)
    axes[1].set_xlabel("ΔLon error (m)")
    axes[1].set_ylabel("ΔLat error (m)")
    axes[1].set_title("Error Scatter (Lon vs Lat bias)")
    axes[1].set_aspect("equal")

    _apply_style(fig, axes)
    fig.tight_layout()
    p = out_dir / "error_components.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Error vectors  → {p}")


# summary card
def plot_dashboard(kpis: dict, df: pd.DataFrame, fp_mask, out_dir: Path):
    fig = plt.figure(figsize=(16, 9))
    fig.patch.set_facecolor(STYLE["bg"])

    gs = gridspec.GridSpec(2, 3, figure=fig, hspace=0.45, wspace=0.35)

    # erro/time 
    ax1 = fig.add_subplot(gs[0, :2])
    t0 = df["t"].min()
    t_s = df["t"] - t0
    good = ~fp_mask
    ax1.fill_between(t_s[good], 0, df["error_m"][good],
                     alpha=0.2, color=STYLE["accent1"])
    ax1.plot(t_s[good], df["error_m"][good],
             color=STYLE["accent1"], linewidth=1)
    ax1.axhline(kpis["mean_error_m"], color=STYLE["accent2"],
                linewidth=1.2, linestyle="--")
    ax1.set_title("Error Over Time", fontsize=10)
    ax1.set_xlabel("Time (s)", fontsize=8)
    ax1.set_ylabel("Error (m)", fontsize=8)

    # histograma
    ax2 = fig.add_subplot(gs[0, 2])
    ax2.hist(df["error_m"][good], bins=25,
             color=STYLE["accent1"], alpha=0.8, edgecolor=STYLE["bg"])
    ax2.axvline(kpis["mean_error_m"], color=STYLE["accent2"],
                linewidth=1.2, linestyle="--")
    ax2.set_title("Error Distribution", fontsize=10)
    ax2.set_xlabel("Error (m)", fontsize=8)

    
    ax3 = fig.add_subplot(gs[1, 0])
    ax3.axis("off")
    kpi_lines = [
        ("Estimations",     f"{kpis['total_estimations']}"),
        ("Mean error",      f"{kpis['mean_error_m']:.1f} m"),
        ("Median error",    f"{kpis['median_error_m']:.1f} m"),
        ("RMSE",            f"{kpis['rmse_m']:.1f} m"),
        ("P90 error",       f"{kpis['p90_error_m']:.1f} m"),
        ("Max error",       f"{kpis['max_error_m']:.1f} m"),
        ("False positives", f"{kpis['false_positives']} ({kpis['false_positive_pct']:.1f}%)"),
        ("Rate",            f"{kpis['estimation_rate_hz']:.2f} Hz"),
        ("Duration",        f"{kpis['duration_s']:.0f} s"),
    ]
    for i, (label, val) in enumerate(kpi_lines):
        y = 0.95 - i * 0.105
        ax3.text(0.02, y, label, transform=ax3.transAxes,
                 fontsize=9, color=STYLE["text"], alpha=0.7)
        ax3.text(0.98, y, val, transform=ax3.transAxes,
                 fontsize=9, color=STYLE["accent1"], ha="right", fontweight="bold")
    ax3.set_title("KPI Summary", fontsize=10, color=STYLE["text"])
    ax3.set_facecolor(STYLE["panel"])
    for spine in ax3.spines.values():
        spine.set_edgecolor(STYLE["grid"])

    # ── CDF ──
    ax4 = fig.add_subplot(gs[1, 1])
    good_err = np.sort(df["error_m"][good].values)
    cdf = np.arange(1, len(good_err)+1) / len(good_err)
    ax4.plot(good_err, cdf * 100, color=STYLE["accent1"], linewidth=1.5)
    ax4.fill_between(good_err, 0, cdf * 100, alpha=0.15, color=STYLE["accent1"])
    ax4.axhline(90, color=STYLE["fp"], linewidth=0.8, linestyle="--", alpha=0.7)
    ax4.set_title("Error CDF", fontsize=10)
    ax4.set_xlabel("Error (m)", fontsize=8)
    ax4.set_ylabel("Cumulative %", fontsize=8)
    ax4.set_ylim(0, 101)

    # ── altitude ──
    ax5 = fig.add_subplot(gs[1, 2])
    ax5.plot(t_s, df["gps_alt"], color=STYLE["accent1"],
             linewidth=1, label="GPS alt")
    ax5.plot(t_s, df["vis_alt"], color=STYLE["accent2"],
             linewidth=1, linestyle="--", label="NavNet alt")
    ax5.set_title("Altitude", fontsize=10)
    ax5.set_xlabel("Time (s)", fontsize=8)
    ax5.set_ylabel("Alt (m)", fontsize=8)
    ax5.legend(fontsize=7, facecolor=STYLE["panel"], labelcolor=STYLE["text"])

    _apply_style(fig, [ax1, ax2, ax3, ax4, ax5])

    fig.suptitle("NavNet — Run Dashboard", fontsize=14,
                 color=STYLE["text"], y=1.01, fontweight="bold")

    p = out_dir / "dashboard.png"
    fig.savefig(p, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[✓] Dashboard      → {p}")



def main():
    parser = argparse.ArgumentParser(description="NavNet KPI Analyser")
    parser.add_argument("bag", help="Path to MCAP bag file or bag directory")
    parser.add_argument("--out", default="./navnet_results",
                        help="Output directory (default: ./navnet_results)")
    parser.add_argument("--fp-threshold", type=float, default=FALSE_POS_THRESHOLD_M,
                        help=f"False-positive threshold in metres (default: {FALSE_POS_THRESHOLD_M})")
    args = parser.parse_args()

    fp_threshold = args.fp_threshold

    bag_path = Path(args.bag)
    if not bag_path.exists():
        print(f"[✗] Bag not found: {bag_path}")
        sys.exit(1)

    out_dir = Path(args.out)
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"\n{'='*55}")
    print(f"  NavNet KPI Analyser")
    print(f"  Bag  : {bag_path}")
    print(f"  Out  : {out_dir}")
    print(f"{'='*55}\n")

    print("[…] Reading bag …")
    gps_df, vis_df = read_bag(bag_path)
    print(f"    GPS messages    : {len(gps_df)}")
    print(f"    Vision messages : {len(vis_df)}")

    if vis_df.empty:
        print(f"[✗] No messages on {VISION_TOPIC}. Nothing to analyse.")
        sys.exit(1)

    print("[…] Synchronising …")
    df = sync_nearest(gps_df, vis_df)
    print(f"    Synced pairs    : {len(df)}")

    print("[…] Computing KPIs …")
    kpis, fp_mask = compute_kpis(df, n_gps=len(gps_df), fp_threshold=fp_threshold)

    write_txt(kpis, out_dir)

    print("[…] Generating plots …")
    plot_error_time(df, fp_mask, out_dir)
    plot_histogram(df, fp_mask, kpis, out_dir)
    plot_cdf(df, fp_mask, kpis, out_dir)
    plot_altitude(df, out_dir)
    plot_trajectory(df, fp_mask, out_dir)
    plot_error_vectors(df, fp_mask, out_dir)
    plot_dashboard(kpis, df, fp_mask, out_dir)

    print(f"\n{'='*55}")
    print(f"  Done. Results in: {out_dir}/")
    print(f"{'='*55}\n")


if __name__ == "__main__":
    main()