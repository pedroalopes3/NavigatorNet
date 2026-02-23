"""
=============================================================================
MCAP Drone Telemetry & Satellite Imagery Viewer
=============================================================================

Description:
    This script reads a ROS2 MCAP bag file containing drone flight data and 
    synchronizes the onboard camera feed with live satellite imagery. 
    
    It extracts GPS coordinates and compressed images from the MCAP file, 
    calculates the corresponding Google Maps XYZ tiles (using the Mercator 
    projection), and fetches a 3x3 grid of high-resolution satellite tiles. 
    The raw drone camera view and the stitched satellite map are displayed 
    side-by-side using OpenCV.

Key Features:
    - MCAP Parsing: Reads `/image/compressed` and `/global_position_int`.
    - 3x3 Grid Stitching: Downloads and stitches 9 Google Maps tiles 
      to provide a wide, high-definition satellite view of the surroundings.
    - Bandwidth Optimization: Calculates distance between frames and only 
      requests new map tiles if the drone has moved more than 10 meters.
    - Live HUD: Overlays real-time latitude and longitude on the video feed.

Note:
    The map fetching relies on direct XYZ tile access for development 
    purposes. Map updates may cause minor visual pauses in playback as 
    HTTP requests are processed.
=============================================================================
"""

import cv2
import numpy as np
import requests
import io
import math
from PIL import Image
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory

# --- CONFIGURATION ---
INPUT_FILE = "sample_techinnov_01.mcap"
IMAGE_TOPIC = "/image/compressed"
GPS_TOPIC = "/global_position_int"

def deg2num(lat_deg, lon_deg, zoom):
    """ Converte Latitude/Longitude num tile XYZ da Google (Projeção de Mercator) """
    lat_rad = math.radians(lat_deg)
    n = 2.0 ** zoom
    xtile = int((lon_deg + 180.0) / 360.0 * n)
    ytile = int((1.0 - math.asinh(math.tan(lat_rad)) / math.pi) / 2.0 * n)
    return xtile, ytile

def get_google_satellite_tile(lat, lon, zoom=19, size=640):
    """ Fetches a 3x3 grid of satellite tiles centered on the drone and stitches them together """
    center_x, center_y = deg2num(lat, lon, zoom)
    
    headers = {"User-Agent": "Mozilla/5.0"}
    grid_radius = 1 # A radius of 1 means -1, 0, +1 (a 3x3 grid)
    
    rows = []
    
    # Loop through the Y axis (Rows)
    for dy in range(-grid_radius, grid_radius + 1):
        row_tiles = []
        
        # Loop through the X axis (Columns)
        for dx in range(-grid_radius, grid_radius + 1):
            tile_x = center_x + dx
            tile_y = center_y + dy
            
            url = f"https://mt1.google.com/vt/lyrs=s&x={tile_x}&y={tile_y}&z={zoom}"
            
            try:
                response = requests.get(url, headers=headers, timeout=5)
                if response.status_code == 200:
                    img = Image.open(io.BytesIO(response.content)).convert('RGB')
                    np_img = cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR)
                else:
                    # If a single tile fails, insert a black square so the grid doesn't break
                    np_img = np.zeros((256, 256, 3), dtype=np.uint8)
            except Exception as e:
                print(f"Tile request failed: {e}")
                np_img = np.zeros((256, 256, 3), dtype=np.uint8)
                
            row_tiles.append(np_img)
            
        # Stitch the 3 tiles of this row horizontally
        stitched_row = np.hstack(row_tiles)
        rows.append(stitched_row)
        
    # Stitch the 3 rows vertically
    stitched_map = np.vstack(rows)
    
    # The stitched map is 768x768. We resize it to your preferred window size (640x640)
    return cv2.resize(stitched_map, (size, size))

def dist_metros(lat1, lon1, lat2, lon2):
    """ Calcula a distância aproximada em metros entre dois pontos GPS """
    d_lat = (lat2 - lat1) * 111000
    d_lon = (lon2 - lon1) * 111000 * math.cos(math.radians(lat1))
    return math.sqrt(d_lat**2 + d_lon**2)

def main():
    drone_gps = {"lat": None, "lon": None}
    
    print(f"A ler {INPUT_FILE}...")
    print("-" * 40)

    # Variáveis de controlo para não "spammar" a Google
    last_map_lat = 0
    last_map_lon = 0
    current_map_img = None
    
    with open(INPUT_FILE, "rb") as f:
        reader = make_reader(f, decoder_factories=[DecoderFactory()])
        
        for schema, channel, message, ros_msg in reader.iter_decoded_messages(topics=[IMAGE_TOPIC, GPS_TOPIC]):
            
            # 1. Atualizar GPS
            if channel.topic == GPS_TOPIC:
                drone_gps["lat"] = ros_msg.lat * 1e-7
                drone_gps["lon"] = ros_msg.lon * 1e-7
                continue 

            # 2. Processar Imagem e Mapa
            if channel.topic == IMAGE_TOPIC:
                if drone_gps["lat"] is not None:
                    
                    # Verifica a distância movida desde o último mapa
                    dist = dist_metros(last_map_lat, last_map_lon, drone_gps["lat"], drone_gps["lon"])
                    
                    # Atualiza o mapa apenas se o drone se moveu mais de 10 metros
                    if dist > 10 or current_map_img is None:
                        print(f"📍 GPS: Lat {drone_gps['lat']:.5f}, Lon {drone_gps['lon']:.5f} (Moveu-se {dist:.1f}m - A descarregar Satélite...)")
                        current_map_img = get_google_satellite_tile(drone_gps["lat"], drone_gps["lon"])
                        last_map_lat = drone_gps["lat"]
                        last_map_lon = drone_gps["lon"]
                    
                    # Descodifica a imagem do Drone
                    np_arr = np.frombuffer(ros_msg.data, np.uint8)
                    drone_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

                    # Se temos ambas as imagens, junta e mostra
                    if current_map_img is not None and drone_img is not None:
                        drone_small = cv2.resize(drone_img, (640, 640))
                        combined = np.hstack((drone_small, current_map_img))
                        
                        cv2.putText(combined, f"Lat: {drone_gps['lat']:.5f} Lon: {drone_gps['lon']:.5f}", 
                                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                        
                        cv2.imshow("Drone (Esquerda) vs Google Satelite (Direita)", combined)
                
                # Pressiona 'q' para sair
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    print("A sair...")
                    break

    cv2.destroyAllWindows()
    print("Leitura do MCAP terminada.")

if __name__ == "__main__":
    main()