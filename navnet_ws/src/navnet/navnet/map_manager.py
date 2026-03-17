import json
import math
import os


class MapRepoManager:
    def __init__(self, repo_path):
        self.repo_path = repo_path  # path para a dir onde estao os tiles
        # Guarda os zooms e se são high_res (importante para o cálculo exato)
        self.zoom_info = {}
        self.global_bbox = {
            "west": float("inf"),
            "south": float("inf"),
            "east": float("-inf"),
            "north": float("-inf"),
        }
        self.analyzed = False

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
                        base_ppm = data.get("ppm", 0.0)
                        high_res = data.get("high_res", False)

                        self.zoom_info[zoom] = {"base_ppm": base_ppm, "high_res": high_res}

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
        """Calcula o PPM exato para uma latitude e zoom específicos."""
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

        # Itera sobre todos os zooms disponíveis para encontrar a correspondência mais próxima
        for zoom, info in self.zoom_info.items():
            # 1. Calcula o PPM exato do mapa na latitude atual do drone
            calculated_ppm = self.calculate_theoretical_ppm(
                current_latitude, zoom, info["high_res"]
            )

            # 2. Vê a diferença entre o mapa e a imagem do drone
            diff = abs(calculated_ppm - target_ppm)

            if diff < min_diff:
                min_diff = diff
                best_zoom = zoom
                best_calculated_ppm = calculated_ppm

        return best_zoom, best_calculated_ppm

    def calculate_incidence_point(self, lat, lon, alt_m, heading_deg, drone_pitch_rad):
        """
        Calcula onde o centro da câmera está a olhar no solo.
        """
        heading_rad = math.radians(heading_deg)
        camera_pitch_rad = math.radians(self.camera_pitch_offset_deg)

        total_pitch_rad = drone_pitch_rad + camera_pitch_rad
        angle_from_vertical = (math.pi / 2.0) - total_pitch_rad

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

    def get_map_for_telemetry(self, lat, lon, alt_m, heading_deg, drone_pitch_rad, f_final):
        """
        Função principal que faz a ponte: Telemetria -> Ponto de Incidência -> Tile Correto.
        Devolve a imagem do mapa (numpy array) e um dicionário com os metadados.
        """
        # 1. Calcular o Ponto de Incidência
        inc_lat, inc_lon, angle_vert = self.calculate_incidence_point(
            lat, lon, alt_m, heading_deg, drone_pitch_rad
        )

        if inc_lat is None:
            print("[MapManager] A câmara está a olhar para o céu (acima do horizonte).")
            return None, None

        # 2. Calcular o PPM atual do drone
        slant_distance = alt_m / math.cos(angle_vert) if math.cos(angle_vert) != 0 else float("inf")
        drone_ppm = f_final / slant_distance if slant_distance > 0 else 0

        # 3. Descobrir o Melhor Zoom
        best_zoom, map_ppm = self.get_best_zoom(drone_ppm, inc_lat)
        if best_zoom is None:
            return None, None

        # 4. Descobrir o Tile X e Y usando a biblioteca mercantile
        target_tile = mercantile.tile(inc_lon, inc_lat, best_zoom)

        # 5. Carregar a Imagem do Disco
        filename = f"{best_zoom}_{target_tile.x}_{target_tile.y}.jpg"
        filepath = os.path.join(self.repo_path, str(best_zoom), filename)

        map_img = None
        if os.path.exists(filepath):
            map_img = cv2.imread(filepath)
        else:
            print(f"[MapManager] Aviso: O Tile {filename} não existe na tua pasta!")

        # 6. Agrupar os resultados num dicionário para usares no main.py
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
