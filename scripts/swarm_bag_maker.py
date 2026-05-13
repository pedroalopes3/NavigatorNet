or#!/usr/bin/env python3
"""
generate_swarm_bags.py
======================
Takes a real NavNet MCAP bag (which has /map/gps_raw with the main drone's
GPS trajectory) and generates N synthetic "swarm drone" bags, each containing:

  /gps/fix          [sensor_msgs/NavSatFix]   — ground-truth GPS of that drone
  /uwb/range        [sensor_msgs/Range]        — UWB distance TO the main drone
  /uwb/range_swarm  [sensor_msgs/Range[]]      — UWB distances to all other
                                                  swarm drones (consistent)

Placement rules
───────────────
  • Each swarm drone is placed at a random offset from the main drone at
    every GPS timestamp.
  • Absolute distance from main drone : uniform in [MIN_DIST, MAX_DIST] metres.
  • Offsets are smooth (low-pass filtered random walk) so the drones don't
    teleport frame to frame.
  • Cross-drone UWB distances are computed from the generated positions, so
    they are fully consistent with each other and with /uwb/range.

Usage
─────
  python3 generate_swarm_bags.py <source.mcap> [options]

  --drones   N        number of swarm drones  (default: 3)
  --min-dist D        minimum distance in m   (default: 2)
  --max-dist D        maximum distance in m   (default: 200)
  --noise    σ        UWB range noise std dev  (default: 0.1 m)
  --out-dir  PATH     output directory         (default: ./swarm_bags)
  --seed     S        random seed for repro    (default: 42)

Output
──────
  swarm_bags/
    drone_1/drone_1_0.mcap
    drone_2/drone_2_0.mcap
    ...

Dependencies
────────────
  pip install rosbags numpy
"""

import argparse
import math
import os
import struct
import sys
import time
import shutil
from pathlib import Path

import numpy as np
from rosbags.highlevel import AnyReader
from rosbags.rosbag2 import Writer
from rosbags.typesys import Stores, get_typestore
from rosbags.typesys.stores.ros2_humble import (
    builtin_interfaces__msg__Time as Time,
    geometry_msgs__msg__Vector3 as Vector3,
    sensor_msgs__msg__NavSatFix as NavSatFix,
    sensor_msgs__msg__NavSatStatus as NavSatStatus,
    sensor_msgs__msg__Range as Range,
    std_msgs__msg__Header as Header,
    std_msgs__msg__Float32MultiArray as Float32MultiArray,
    std_msgs__msg__MultiArrayDimension as MultiArrayDimension,
    std_msgs__msg__MultiArrayLayout as MultiArrayLayout,
)

# ── constants ──────────────────────────────────────────────────────────────────
GPS_TOPIC   = "/map/gps_raw"          # main drone ground-truth GPS in source bag
EARTH_R     = 6_378_137.0             # metres

# ── helpers ────────────────────────────────────────────────────────────────────

def stamp_to_ns(stamp) -> int:
    return int(stamp.sec) * 10**9 + int(stamp.nanosec)

def ns_to_stamp(ns: int) -> Time:
    return Time(sec=int(ns // 10**9), nanosec=int(ns % 10**9))

def haversine(lat1, lon1, lat2, lon2) -> float:
    phi1, phi2 = math.radians(lat1), math.radians(lat2)
    dphi = math.radians(lat2 - lat1)
    dlam = math.radians(lon2 - lon1)
    a = math.sin(dphi/2)**2 + math.cos(phi1)*math.cos(phi2)*math.sin(dlam/2)**2
    return EARTH_R * 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))

def offset_to_latlon(lat, lon, dx_m, dy_m):
    """Apply metric east/north offset to a lat/lon."""
    dlat = math.degrees(dy_m / EARTH_R)
    dlon = math.degrees(dx_m / (EARTH_R * math.cos(math.radians(lat))))
    return lat + dlat, lon + dlon


# ── position generator ─────────────────────────────────────────────────────────

class SmoothSwarmPositionGenerator:
    """
    Generates smooth random offsets (dx, dy) in metres for each drone relative
    to the main drone, constrained to [min_dist, max_dist] absolute distance.

    Uses a random-walk that is low-pass filtered so positions evolve smoothly
    between timestamps (no teleportation).
    """

    def __init__(self, n_drones: int, min_dist: float, max_dist: float,
                 rng: np.random.Generator):
        self.n   = n_drones
        self.mn  = min_dist
        self.mx  = max_dist
        self.rng = rng

        # initialise each drone at a random valid position
        angles = rng.uniform(0, 2*math.pi, n_drones)
        dists  = rng.uniform(min_dist, max_dist, n_drones)
        self.dx = dists * np.cos(angles)   # east  (m)
        self.dy = dists * np.sin(angles)   # north (m)

        # random-walk velocity (m/s equivalent, will be scaled per dt)
        self.vx = np.zeros(n_drones)
        self.vy = np.zeros(n_drones)

    def step(self, dt: float):
        """
        Advance positions by dt seconds.
        Returns (dx_array, dy_array) shape (n_drones,)
        """
        # random acceleration
        ax = self.rng.normal(0, 2.0, self.n)
        ay = self.rng.normal(0, 2.0, self.n)

        # low-pass: damp velocity toward zero + add impulse
        alpha = 0.85
        self.vx = alpha * self.vx + (1-alpha) * ax
        self.vy = alpha * self.vy + (1-alpha) * ay

        self.dx += self.vx * dt
        self.dy += self.vy * dt

        # constrain to [min_dist, max_dist] ring
        dists = np.sqrt(self.dx**2 + self.dy**2)
        for i in range(self.n):
            d = dists[i]
            if d < self.mn:
                scale = self.mn / max(d, 1e-6)
                self.dx[i] *= scale
                self.dy[i] *= scale
                # reflect velocity outward
                self.vx[i] = abs(self.vx[i]) * (self.dx[i] / self.mn)
                self.vy[i] = abs(self.vy[i]) * (self.dy[i] / self.mn)
            elif d > self.mx:
                scale = self.mx / d
                self.dx[i] *= scale
                self.dy[i] *= scale
                self.vx[i] *= scale
                self.vy[i] *= scale

        return self.dx.copy(), self.dy.copy()


# ── bag reading ────────────────────────────────────────────────────────────────

def read_main_gps(bag_path: Path, typestore) -> list[dict]:
    """Read all NavSatFix messages from GPS_TOPIC."""
    records = []
    with AnyReader([bag_path], default_typestore=typestore) as reader:
        conns = [c for c in reader.connections if c.topic == GPS_TOPIC]
        if not conns:
            raise RuntimeError(
                f"Topic '{GPS_TOPIC}' not found in bag.\n"
                f"Available topics: {[c.topic for c in reader.connections]}"
            )
        for conn, ts, raw in reader.messages(connections=conns):
            msg = reader.deserialize(raw, conn.msgtype)
            records.append({
                "ts_ns": stamp_to_ns(msg.header.stamp),
                "lat":   msg.latitude,
                "lon":   msg.longitude,
                "alt":   msg.altitude,
            })
    records.sort(key=lambda r: r["ts_ns"])
    return records


# ── bag writing ───────────────────────────────────────────────────────────────

def make_header(ts_ns: int, frame_id: str) -> Header:
    return Header(stamp=ns_to_stamp(ts_ns), frame_id=frame_id)


def make_navsatfix(ts_ns: int, lat: float, lon: float, alt: float,
                   drone_id: int) -> NavSatFix:
    status = NavSatStatus(
        status=NavSatStatus.STATUS_FIX,
        service=NavSatStatus.SERVICE_GPS,
    )
    cov = np.zeros(9, dtype=np.float64)
    cov[0] = cov[4] = cov[8] = 1.0   # 1 m² diagonal — simulated GPS
    return NavSatFix(
        header=make_header(ts_ns, "earth"),
        status=status,
        latitude=lat,
        longitude=lon,
        altitude=alt,
        position_covariance=cov,
        position_covariance_type=NavSatFix.COVARIANCE_TYPE_DIAGONAL_KNOWN,
    )


def make_range(ts_ns: int, distance_m: float, noise_std: float,
               rng: np.random.Generator, frame_id: str) -> Range:
    noisy = float(distance_m + rng.normal(0, noise_std))
    noisy = max(0.01, noisy)
    return Range(
        header=make_header(ts_ns, frame_id),
        radiation_type=Range.ULTRASOUND,   # UWB modelled as ULTRASOUND type
        field_of_view=float(2 * math.pi),  # UWB is omnidirectional
        min_range=0.01,
        max_range=250.0,
        range=noisy,
    )


def make_swarm_ranges(ts_ns: int, distances: list[float], noise_std: float,
                      rng: np.random.Generator) -> Float32MultiArray:
    """
    Pack inter-swarm distances into a Float32MultiArray.
    distances[j] = distance from this drone to swarm drone j
    (nan for self-distance).
    """
    data = np.array(
        [float(d + rng.normal(0, noise_std)) if not math.isnan(d) else float("nan")
         for d in distances],
        dtype=np.float32,
    )
    dim = MultiArrayDimension(
        label="swarm_drone_index",
        size=len(data),
        stride=len(data),
    )
    layout = MultiArrayLayout(dim=[dim], data_offset=0)
    return Float32MultiArray(layout=layout, data=data)


def write_drone_bag(out_dir: Path, drone_id: int, records: list[dict],
                    all_positions: np.ndarray,   # shape (N_drones, N_ts, 2) [dx,dy]
                    noise_std: float, rng: np.random.Generator,
                    typestore, main_gps: list[dict]):
    """
    Write one swarm drone bag.

    all_positions[drone_id, :, :] = this drone's offsets
    all_positions[other, :, :]    = other drones' offsets (for cross-range)
    """

    bag_dir = out_dir / f"drone_{drone_id + 1}"
    if bag_dir.exists():
        shutil.rmtree(bag_dir)
    #bag_dir.mkdir(parents=True, exist_ok=True)

    n_drones = all_positions.shape[0]

    with Writer(str(bag_dir), version=2) as writer:
        # register connection types
        gps_conn = writer.add_connection(
            "/gps/fix",
            "sensor_msgs/msg/NavSatFix",
            typestore=typestore,
        )
        uwb_main_conn = writer.add_connection(
            "/uwb/range_to_main",
            "sensor_msgs/msg/Range",
            typestore=typestore,
        )
        uwb_swarm_conn = writer.add_connection(
            "/uwb/range_to_swarm",
            "std_msgs/msg/Float32MultiArray",
            typestore=typestore,
        )

        for ts_idx, rec in enumerate(records):
            ts_ns = rec["ts_ns"]

            # ── this drone's GPS ──────────────────────────────────────────────
            dx = all_positions[drone_id, ts_idx, 0]
            dy = all_positions[drone_id, ts_idx, 1]
            lat, lon = offset_to_latlon(rec["lat"], rec["lon"], dx, dy)
            alt = rec["alt"]   # keep same altitude (flat swarm assumption)

            gps_msg = make_navsatfix(ts_ns, lat, lon, alt, drone_id)
            writer.write(gps_conn, ts_ns,
                         typestore.serialize_cdr(gps_msg, "sensor_msgs/msg/NavSatFix"))

            # ── UWB range to main drone ───────────────────────────────────────
            dist_to_main = math.sqrt(dx**2 + dy**2)
            range_msg = make_range(ts_ns, dist_to_main, noise_std, rng,
                                   frame_id=f"drone_{drone_id+1}_uwb")
            writer.write(uwb_main_conn, ts_ns,
                         typestore.serialize_cdr(range_msg, "sensor_msgs/msg/Range"))

            # ── UWB ranges to all other swarm drones ─────────────────────────
            swarm_dists = []
            for other_id in range(n_drones):
                if other_id == drone_id:
                    swarm_dists.append(float("nan"))
                else:
                    odx = all_positions[other_id, ts_idx, 0]
                    ody = all_positions[other_id, ts_idx, 1]
                    d = math.sqrt((dx - odx)**2 + (dy - ody)**2)
                    swarm_dists.append(d)

            swarm_msg = make_swarm_ranges(ts_ns, swarm_dists, noise_std, rng)
            writer.write(uwb_swarm_conn, ts_ns,
                         typestore.serialize_cdr(swarm_msg,
                                                 "std_msgs/msg/Float32MultiArray"))

    print(f"  [✓] drone_{drone_id+1}  →  {bag_dir}/")


# ── main ──────────────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(
        description="Generate synthetic swarm UWB bags from a NavNet MCAP bag."
    )
    parser.add_argument("bag",         help="Source MCAP file or bag directory")
    parser.add_argument("--drones",    type=int,   default=3,    help="Number of swarm drones")
    parser.add_argument("--min-dist",  type=float, default=2.0,  help="Min distance from main (m)")
    parser.add_argument("--max-dist",  type=float, default=200.0,help="Max distance from main (m)")
    parser.add_argument("--noise",     type=float, default=0.1,  help="UWB range noise σ (m)")
    parser.add_argument("--out-dir",   default="./swarm_bags",   help="Output directory")
    parser.add_argument("--seed",      type=int,   default=42,   help="Random seed")
    args = parser.parse_args()

    rng = np.random.default_rng(args.seed)
    typestore = get_typestore(Stores.ROS2_HUMBLE)

    bag_path = Path(args.bag)
    if not bag_path.exists():
        print(f"[✗] Bag not found: {bag_path}")
        sys.exit(1)

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    print(f"\n{'='*60}")
    print(f"  NavNet → Swarm UWB Bag Generator")
    print(f"  Source  : {bag_path}")
    print(f"  Drones  : {args.drones}")
    print(f"  Dist    : [{args.min_dist}, {args.max_dist}] m")
    print(f"  Noise σ : {args.noise} m")
    print(f"  Seed    : {args.seed}")
    print(f"  Output  : {out_dir}")
    print(f"{'='*60}\n")

    # 1. Read main drone trajectory
    print("[1/3] Reading source bag …")
    main_gps = read_main_gps(bag_path, typestore)
    n_ts = len(main_gps)
    print(f"      {n_ts} GPS samples over "
          f"{(main_gps[-1]['ts_ns'] - main_gps[0]['ts_ns']) / 1e9:.1f} s")

    # 2. Generate smooth positions for all drones across all timestamps
    print(f"\n[2/3] Generating {args.drones} drone trajectories …")
    gen = SmoothSwarmPositionGenerator(
        args.drones, args.min_dist, args.max_dist, rng
    )

    # all_positions[drone, ts, (dx,dy)]
    all_positions = np.zeros((args.drones, n_ts, 2), dtype=np.float64)
    all_positions[:, 0, 0] = gen.dx.copy()
    all_positions[:, 0, 1] = gen.dy.copy()

    for ts_idx in range(1, n_ts):
        dt = (main_gps[ts_idx]["ts_ns"] - main_gps[ts_idx-1]["ts_ns"]) / 1e9
        dt = min(dt, 5.0)   # cap large gaps (e.g. bag pauses) to 5 s
        dx, dy = gen.step(dt)
        all_positions[:, ts_idx, 0] = dx
        all_positions[:, ts_idx, 1] = dy

    # sanity check distances
    dists = np.sqrt(all_positions[:,:,0]**2 + all_positions[:,:,1]**2)
    print(f"      Distance stats (all drones, all timestamps):")
    print(f"        min={dists.min():.1f} m  "
          f"mean={dists.mean():.1f} m  "
          f"max={dists.max():.1f} m")

    # cross-drone distances
    cross = []
    for i in range(args.drones):
        for j in range(i+1, args.drones):
            d = np.sqrt(
                (all_positions[i,:,0]-all_positions[j,:,0])**2 +
                (all_positions[i,:,1]-all_positions[j,:,1])**2
            )
            cross.append(d)
    cross = np.concatenate(cross)
    print(f"      Cross-drone distances:")
    print(f"        min={cross.min():.1f} m  "
          f"mean={cross.mean():.1f} m  "
          f"max={cross.max():.1f} m")

    # 3. Write one bag per drone
    print(f"\n[3/3] Writing bags …")
    for drone_id in range(args.drones):
        write_drone_bag(
            out_dir, drone_id,
            main_gps, all_positions,
            args.noise, rng, typestore, main_gps
        )

    # 4. Write a README alongside the bags
    readme = out_dir / "README.md"
    readme.write_text(f"""# Synthetic Swarm UWB Bags

Generated from: `{bag_path.name}`

## Configuration
| Parameter | Value |
|---|---|
| Source bag | `{bag_path.name}` |
| Swarm drones | {args.drones} |
| Distance range | [{args.min_dist}, {args.max_dist}] m |
| UWB noise σ | {args.noise} m |
| Random seed | {args.seed} |
| GPS samples | {n_ts} |

## Topics per drone bag

| Topic | Type | Description |
|---|---|---|
| `/gps/fix` | `sensor_msgs/NavSatFix` | Ground-truth GPS of this drone |
| `/uwb/range_to_main` | `sensor_msgs/Range` | UWB distance to the main drone |
| `/uwb/range_to_swarm` | `std_msgs/Float32MultiArray` | UWB distances to all other swarm drones (index = drone number, NaN = self) |

## Consistency guarantees
- All cross-drone distances are computed from the **same generated positions**,
  so `/uwb/range_to_swarm[i]` on drone A equals `/uwb/range_to_main` on drone B
  (up to independent noise draws).
- Absolute distance from main drone is always within [{args.min_dist}, {args.max_dist}] m.
- Trajectories are smooth (low-pass random walk, no teleportation).
- UWB range noise is Gaussian with σ = {args.noise} m, independent per measurement.

## Distance stats
- Main-to-drone:  min={dists.min():.1f} m  mean={dists.mean():.1f} m  max={dists.max():.1f} m
- Cross-drone:    min={cross.min():.1f} m  mean={cross.mean():.1f} m  max={cross.max():.1f} m
""")
    print(f"\n  [✓] README  →  {readme}")

    print(f"\n{'='*60}")
    print(f"  Done. {args.drones} bags in: {out_dir}/")
    print(f"{'='*60}\n")


if __name__ == "__main__":
    main()