import json
import math
import os

import cv2
import mercantile
import numpy as np


class MapRepoManager:
    def __init__(self, repo_path):
        self.repo_path = repo_path  # Caminho para o diretório onde estão os tiles

        # Guarda os zooms e se são high_res (importante para o cálculo exato)
        self.zoom_info = {}
        self.global_bbox = {
            "west": float("inf"),
            "south": float("inf"),
            "east": float("-inf"),
            "north": float("-inf"),
        }
        self.analyzed = False

        # Variáveis constantes físicas e da câmara
        self.EARTH_RADIUS = 6378137.0
        self.camera_pitch_offset_deg = 27.0
        self.camera_roll_offset_deg = -4.0

        # Tópicos e Memória de Telemetria Interna
        self.TOPIC_GPS = "/global_position_int"
        self.TOPIC_ATTITUDE = "/attitude"

        self.current_telemetry = {
            "lat": 0.0,
            "lon": 0.0,
            "alt_m": 0.0,
            "heading_deg": 0.0,
            "pitch_rad": 0.0,
        }

    def update_telemetry_from_msg(self, topic, ros_msg):
        """
        Recebe a mensagem bruta do ROS e extrai os valores para a memória interna.
        Faz a conversão de inteiros para graus ou metros (1e-7, 1e-3, etc).
        """
        if topic == self.TOPIC_GPS:
            self.current_telemetry["lat"] = ros_msg.lat * 1e-7
            self.current_telemetry["lon"] = ros_msg.lon * 1e-7
            self.current_telemetry["alt_m"] = ros_msg.relative_alt * 1e-3
            self.current_telemetry["heading_deg"] = ros_msg.hdg * 1e-2

        elif topic == self.TOPIC_ATTITUDE:
            self.current_telemetry["pitch_rad"] = ros_msg.pitch

    def analyze(self):
        """Lê os metadados do diretório, extrai a Bounding Box global e lista os Zooms."""
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

                        # Primeiro, extraímos os limites para calcular a latitude média
                        temp_west, temp_south = float("inf"), float("inf")
                        temp_east, temp_north = float("-inf"), float("-inf")

                        for tile in data.get("tiles", []):
                            bounds = tile.get("bounds", {})
                            if bounds:
                                # Atualiza a Bounding Box Global do Manager
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

                                # Limites temporários para este zoom específico
                                temp_west = min(temp_west, bounds["west"])
                                temp_south = min(temp_south, bounds["south"])
                                temp_east = max(temp_east, bounds["east"])
                                temp_north = max(temp_north, bounds["north"])

                        # CALCULO DO PPM REAL:
                        # Usamos a latitude central desta zona para dar um valor informativo no resumo
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
        """Calcula o PPM exato para uma latitude e zoom específicos usando projeção Web Mercator."""
        C = 40075016.686
        lat_rad = math.radians(latitude)
        exponent = 9 if high_res else 8
        meters_per_pixel = (C * math.cos(lat_rad)) / (2 ** (zoom + exponent))
        return 1.0 / meters_per_pixel

    def get_best_zoom(self, target_ppm, current_latitude):
        """
        Recebe o PPM do drone e a latitude atual.
        Recalcula o PPM exato de todos os zooms disponíveis para essa latitude,
        e devolve o zoom com a escala mais próxima à do drone.
        """
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

    def calculate_incidence_point(self, lat, lon, alt_m, heading_deg, drone_pitch_rad):
        """
        Calcula onde o centro da câmara está a olhar no solo usando trigonometria esférica básica.
        """
        heading_rad = math.radians(heading_deg)
        camera_pitch_rad = math.radians(self.camera_pitch_offset_deg)

        total_pitch_rad = drone_pitch_rad + camera_pitch_rad
        angle_from_vertical = (math.pi / 2.0) - total_pitch_rad

        # Evitar projeção no infinito se a câmara olhar acima do horizonte
        if angle_from_vertical >= math.pi / 2.0:
            return None, None, angle_from_vertical

        d = alt_m * math.tan(angle_from_vertical)
        dy = d * math.cos(heading_rad)
        dx = d * math.sin(heading_rad)

        delta_lat = (dy / self.EARTH_RADIUS) * (180.0 / math.pi)
        delta_lon = (dx / (self.EARTH_RADIUS * math.cos(math.radians(lat)))) * (180.0 / math.pi)

        inc_lat = lat + delta_lat
        inc_lon = lon + delta_lon

        return inc_lat, inc_lon, angle_from_vertical

    def get_map_for_telemetry(self, f_final):
        """
        Função principal que faz a ponte: Telemetria Interna -> Ponto de Incidência -> Tile Correto.
        Devolve a imagem do mapa (numpy array) e um dicionário com os metadados.
        """
        lat = self.current_telemetry["lat"]
        lon = self.current_telemetry["lon"]
        alt_m = self.current_telemetry["alt_m"]
        heading_deg = self.current_telemetry["heading_deg"]
        drone_pitch_rad = self.current_telemetry["pitch_rad"]

        inc_lat, inc_lon, angle_vert = self.calculate_incidence_point(
            lat, lon, alt_m, heading_deg, drone_pitch_rad
        )

        if inc_lat is None:
            # A câmara está a olhar para o céu (acima do horizonte)
            return None, None

        slant_distance = alt_m / math.cos(angle_vert) if math.cos(angle_vert) != 0 else float("inf")
        drone_ppm = f_final / slant_distance if slant_distance > 0 else 0

        best_zoom, map_ppm = self.get_best_zoom(drone_ppm, inc_lat)
        if best_zoom is None:
            return None, None

        target_tile = mercantile.tile(inc_lon, inc_lat, best_zoom)

        filename = f"{best_zoom}_{target_tile.x}_{target_tile.y}.jpg"
        filepath = os.path.join(self.repo_path, str(best_zoom), filename)

        map_img = None
        if os.path.exists(filepath):
            map_img = cv2.imread(filepath)
        else:
            # Opcional: Descomentar para debug
            print(f"[MapManager] Aviso: O Tile {filename} não existe na pasta!")
            pass

        info = {
            "inc_lat": inc_lat,
            "inc_lon": inc_lon,
            "zoom": best_zoom,
            "drone_ppm": drone_ppm,
            "map_ppm": map_ppm,
            "tile_x": target_tile.x,
            "tile_y": target_tile.y,
            "filename": filename,
        }

        return map_img, info

    def get_available_tiles(self):
        """Retorna uma lista de tuplos (Z, X, Y) com todos os tiles disponíveis na pasta."""
        tiles_list = []
        for z_folder in os.listdir(self.repo_path):
            if not z_folder.isdigit():
                continue
            z = int(z_folder)
            zoom_path = os.path.join(self.repo_path, z_folder)

            for file in os.listdir(zoom_path):
                if file.endswith(".jpg"):
                    parts = file.replace(".jpg", "").split("_")
                    if len(parts) == 3:
                        x, y = int(parts[1]), int(parts[2])
                        tiles_list.append((z, x, y))
        return tiles_list

    def __contains__(self, tile_tuple):
        """
        Permite usar a sintaxe 'if (z, x, y) in map_manager:'.
        Verifica rapidamente se o ficheiro existe no disco.
        """
        z, x, y = tile_tuple
        filepath = os.path.join(self.repo_path, str(z), f"{z}_{x}_{y}.jpg")
        return os.path.exists(filepath)

    def get_image(self, z, x, y):
        """Lê e retorna a imagem do tile (Z, X, Y) usando OpenCV."""
        if (z, x, y) not in self:
            return None
        filepath = os.path.join(self.repo_path, str(z), f"{z}_{x}_{y}.jpg")
        return cv2.imread(filepath)

    def get_affine_transform(self, z, x, y, image_size=256, epsg=4326):
        """
        Retorna a matriz de transformação afim 3x3 para um dado tile.
        epsg=4326 (Latitude/Longitude) ou epsg=3857 (Metros Web Mercator).
        """
        tile = mercantile.Tile(x, y, z)

        if epsg == 4326:
            bounds = mercantile.bounds(tile)
            min_x, max_x = bounds.west, bounds.east
            min_y, max_y = bounds.south, bounds.north
        elif epsg == 3857:
            bounds = mercantile.xy_bounds(tile)
            min_x, max_x = bounds.left, bounds.right
            min_y, max_y = bounds.bottom, bounds.top
        else:
            raise ValueError("EPSG não suportado. Usa 4326 ou 3857.")

        pixel_width = (max_x - min_x) / image_size
        pixel_height = (min_y - max_y) / image_size

        transform = np.array(
            [[pixel_width, 0.0, min_x], [0.0, pixel_height, max_y], [0.0, 0.0, 1.0]]
        )

        return transform
