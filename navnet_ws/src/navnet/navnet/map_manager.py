import json
import math
import os

import cv2
import mercantile
import numpy as np


class MapRepoManager:
    def __init__(self, repo_path):
        self.repo_path = repo_path

        self.zoom_info = {}
        self.global_bbox = {
            "west": float("inf"),
            "south": float("inf"),
            "east": float("-inf"),
            "north": float("-inf"),
        }
        self.analyzed = False

        self.EARTH_RADIUS = 6378137.0
        self.camera_pitch_offset_deg = 27.0
        self.camera_roll_offset_deg = -4.0

        self.current_telemetry = {
            "lat": 0.0,
            "lon": 0.0,
            "alt_m": 0.0,
            "heading_deg": 0.0,
            "pitch_rad": 0.0,
            "roll_rad": 0.0,
        }

    # ==========================================
    # NOVAS FUNÇÕES (Sem dependência de mensagens ROS)
    # ==========================================
    def update_gps(self, lat_deg, lon_deg, alt_m, heading_deg):
        self.current_telemetry["lat"] = lat_deg
        self.current_telemetry["lon"] = lon_deg
        self.current_telemetry["alt_m"] = alt_m
        self.current_telemetry["heading_deg"] = heading_deg

    def update_attitude(self, pitch_rad, roll_rad):
        self.current_telemetry["pitch_rad"] = pitch_rad
        self.current_telemetry["roll_rad"] = roll_rad

    def analyze(self):
        if not os.path.exists(self.repo_path):
            print(f"Erro: O diretório '{self.repo_path}' não existe.")
            return

        for item in os.listdir(self.repo_path):
            zoom_dir = os.path.join(self.repo_path, item)

            if os.path.isdir(zoom_dir) and item.isdigit():
                metadata_path = os.path.join(zoom_dir, "metadata.json")

                if os.path.exists(metadata_path):
                    with open(metadata_path, "r") as f:
                        data = json.load(f)

                        zoom = data.get("zoom", int(item))
                        high_res = data.get("high_res", False)

                        temp_west, temp_south = float("inf"), float("inf")
                        temp_east, temp_north = float("-inf"), float("-inf")

                        for tile in data.get("tiles", []):
                            bounds = tile.get("bounds", {})
                            if bounds:
                                self.global_bbox["west"] = min(
                                    self.global_bbox["west"], bounds["west"]
                                )
                                self.global_bbox["south"] = min(
                                    self.global_bbox["south"], bounds["south"]
                                )
                                self.global_bbox["east"] = max(
                                    self.global_bbox["east"], bounds["east"]
                                )
                                self.global_bbox["north"] = max(
                                    self.global_bbox["north"], bounds["north"]
                                )

                                temp_west = min(temp_west, bounds["west"])
                                temp_south = min(temp_south, bounds["south"])
                                temp_east = max(temp_east, bounds["east"])
                                temp_north = max(temp_north, bounds["north"])

                        center_lat = (temp_south + temp_north) / 2.0
                        real_ppm = self.calculate_theoretical_ppm(center_lat, zoom, high_res)

                        self.zoom_info[zoom] = {"base_ppm": real_ppm, "high_res": high_res}

        self.analyzed = True
        self._print_summary()

    def _print_summary(self):
        print("\n" + "=" * 45)
        print("RESUMO DO REPOSITÓRIO DE MAPAS")
        print("=" * 45)
        print(f"Diretório: {self.repo_path}\n")

        if self.global_bbox["west"] != float("inf"):
            print("Bounding Box Global:")
            print(f"  West:  {self.global_bbox['west']:.6f}")
            print(f"  South: {self.global_bbox['south']:.6f}")
            print(f"  East:  {self.global_bbox['east']:.6f}")
            print(f"  North: {self.global_bbox['north']:.6f}\n")
        else:
            print("Bounding Box Global: Sem dados.\n")

        print("Níveis de Zoom Disponíveis:")
        if not self.zoom_info:
            print("  Nenhum zoom encontrado.")
        else:
            for zoom in sorted(self.zoom_info.keys()):
                info = self.zoom_info[zoom]
                print(
                    f"  Zoom {zoom} | PPM Base: {info['base_ppm']:.4f} px/m | High-Res: {info['high_res']}"
                )
        print("=" * 45 + "\n")

    @staticmethod
    def calculate_theoretical_ppm(latitude, zoom, high_res=False):
        C = 40075016.686
        lat_rad = math.radians(latitude)
        exponent = 9 if high_res else 8
        meters_per_pixel = (C * math.cos(lat_rad)) / (2 ** (zoom + exponent))
        return 1.0 / meters_per_pixel

    def get_best_zoom(self, target_ppm, current_latitude):
        if not self.analyzed:
            self.analyze()

        if not self.zoom_info:
            print("Erro: Não há níveis de zoom carregados.")
            return None, None

        best_zoom = None
        best_calculated_ppm = None
        min_diff = float("inf")

        for zoom, info in self.zoom_info.items():
            calculated_ppm = self.calculate_theoretical_ppm(
                current_latitude, zoom, info["high_res"]
            )

            diff = abs(calculated_ppm - target_ppm)

            if diff < min_diff:
                min_diff = diff
                best_zoom = zoom
                best_calculated_ppm = calculated_ppm

        return best_zoom, best_calculated_ppm

    def calculate_incidence_point(
        self, lat, lon, alt_m, heading_deg, drone_pitch_rad, drone_roll_rad
    ):
        pitch = drone_pitch_rad - math.radians(self.camera_pitch_offset_deg)
        roll = drone_roll_rad + math.radians(self.camera_roll_offset_deg)
        yaw = math.radians(heading_deg)

        Rz = np.array(
            [[math.cos(yaw), -math.sin(yaw), 0], [math.sin(yaw), math.cos(yaw), 0], [0, 0, 1]]
        )
        Ry = np.array(
            [
                [math.cos(pitch), 0, math.sin(pitch)],
                [0, 1, 0],
                [-math.sin(pitch), 0, math.cos(pitch)],
            ]
        )
        Rx = np.array(
            [[1, 0, 0], [0, math.cos(roll), -math.sin(roll)], [0, math.sin(roll), math.cos(roll)]]
        )

        R = Rz @ Ry @ Rx

        v_cam = np.array([1.0, 0.0, 0.0])
        v_world = R @ v_cam
        v_x, v_y, v_z = v_world

        if v_z <= 0.0:
            return None, None, float("inf")

        t = alt_m / v_z

        dx = v_x * t
        dy = v_y * t

        delta_lat = (dx / self.EARTH_RADIUS) * (180.0 / math.pi)
        delta_lon = (dy / (self.EARTH_RADIUS * math.cos(math.radians(lat)))) * (180.0 / math.pi)

        inc_lat = lat + delta_lat
        inc_lon = lon + delta_lon

        slant_distance = math.sqrt(dx**2 + dy**2 + alt_m**2)

        return inc_lat, inc_lon, slant_distance

    def get_stitched_map(self, target_tile, zoom, inc_lat, inc_lon):
        info = self.zoom_info.get(zoom, {})
        high_res = info.get("high_res", False)
        tile_size = 512 if high_res else 256

        bounds = mercantile.bounds(target_tile)
        center_lat = (bounds.north + bounds.south) / 2.0
        center_lon = (bounds.east + bounds.west) / 2.0

        dir_x = 1 if inc_lon >= center_lon else -1
        dir_y = 1 if inc_lat <= center_lat else -1

        mosaic = np.zeros((2 * tile_size, 2 * tile_size, 3), dtype=np.uint8)

        for dy in [0, dir_y]:
            for dx in [0, dir_x]:
                nx = (target_tile.x + dx) % (2**zoom)
                ny = target_tile.y + dy

                col_pos = dx if dir_x == 1 else dx + 1
                row_pos = dy if dir_y == 1 else dy + 1

                y_start = row_pos * tile_size
                x_start = col_pos * tile_size

                if 0 <= ny < (2**zoom):
                    filepath = os.path.join(self.repo_path, str(zoom), f"{zoom}_{nx}_{ny}.jpg")
                    if os.path.exists(filepath):
                        img = cv2.imread(filepath)
                        if img is not None:
                            mosaic[y_start : y_start + tile_size, x_start : x_start + tile_size] = (
                                img
                            )

        return mosaic, tile_size

    def get_map_for_telemetry(self, f_final):
        alt_m = max(self.current_telemetry["alt_m"], 1.0)

        lat = self.current_telemetry["lat"]
        lon = self.current_telemetry["lon"]
        heading_deg = self.current_telemetry["heading_deg"]
        drone_pitch_rad = self.current_telemetry["pitch_rad"]
        drone_roll_rad = self.current_telemetry["roll_rad"]

        inc_lat, inc_lon, slant_distance = self.calculate_incidence_point(
            lat, lon, alt_m, heading_deg, drone_pitch_rad, drone_roll_rad
        )

        if inc_lat is None:
            return None, None

        drone_ppm = f_final / slant_distance if slant_distance > 0 else 0

        best_zoom, map_ppm = self.get_best_zoom(drone_ppm, inc_lat)
        if best_zoom is None:
            return None, None

        target_tile = mercantile.tile(inc_lon, inc_lat, best_zoom)

        map_img, tile_size = self.get_stitched_map(target_tile, best_zoom, inc_lat, inc_lon)

        info = {
            "inc_lat": inc_lat,
            "inc_lon": inc_lon,
            "zoom": best_zoom,
            "drone_ppm": drone_ppm,
            "map_ppm": map_ppm,
            "tile_x": target_tile.x,
            "tile_y": target_tile.y,
            "mosaic_size": map_img.shape if map_img is not None else None,
            "base_tile_size": tile_size,
        }

        return map_img, info
