import cv2
import numpy as np
import requests
import io
import math
import threading
import mercantile  # <--- New Dependency
from concurrent.futures import ThreadPoolExecutor
from PIL import Image
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory

# --- CONFIGURATION ---
INPUT_FILE = "sample_techinnov_01.mcap"
IMAGE_TOPIC = "/image/compressed"
GPS_TOPIC = "/global_position_int"
TARGET_FPS = 30 

# --- CAMERA CALIBRATION DATA ---
K_ORIGINAL = np.array([
    [896.602173, 0.0,        1003.954285],
    [0.0,        881.922974, 451.323334],
    [0.0,        0.0,        1.0]
])

D_COEFFS = np.array([
    1.771178e+00, 3.254712e+00, 4.790912e-03, -3.419381e-03, 
    2.092365e-01, 2.054499e+00, 3.929369e+00, 1.042681e+00
])

http_session = requests.Session()
http_session.headers.update({"User-Agent": "Mozilla/5.0"})

map_state = {
    "image": None,
    "is_downloading": False,
    "last_lat": 0,
    "last_lon": 0
}

def fetch_single_tile(tile):
    """ Fetches a tile using mercantile Tile object. """
    url = f"https://mt1.google.com/vt/lyrs=s&x={tile.x}&y={tile.y}&z={tile.z}"
    try:
        response = http_session.get(url, timeout=3)
        if response.status_code == 200:
            img = Image.open(io.BytesIO(response.content)).convert('RGB')
            return cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR)
    except Exception: pass
    return np.zeros((256, 256, 3), dtype=np.uint8)

def get_google_satellite_tile(lat, lon, zoom=17, size=640):
    # 1. Use mercantile to find the center tile
    center_tile = mercantile.tile(lon, lat, zoom)
    
    # 2. Generate a 3x3 grid of tiles
    tile_grid = []
    for y in range(center_tile.y - 1, center_tile.y + 2):
        for x in range(center_tile.x - 1, center_tile.x + 2):
            tile_grid.append(mercantile.Tile(x, y, zoom))
            
    # 3. Parallel download
    with ThreadPoolExecutor(max_workers=9) as executor:
        results = list(executor.map(fetch_single_tile, tile_grid))
        
    # 4. Stitch (3 rows of 3 tiles)
    rows = [np.hstack(results[i*3:(i+1)*3]) for i in range(3)]
    stitched_map = np.vstack(rows)
    return cv2.resize(stitched_map, (size, size))

def background_map_updater(lat, lon):
    map_state["is_downloading"] = True
    try:
        new_map = get_google_satellite_tile(lat, lon)
        map_state["image"] = new_map
        map_state["last_lat"], map_state["last_lon"] = lat, lon
    finally:
        map_state["is_downloading"] = False

def dist_metros(lat1, lon1, lat2, lon2):
    if lat1 == 0: return 999
    # Using a slightly more accurate Mercator approximation
    d_lat = (lat2 - lat1) * 111320 
    d_lon = (lon2 - lon1) * 111320 * math.cos(math.radians(lat1))
    return math.sqrt(d_lat**2 + d_lon**2)

def main():
    frame_delay = int(1000 / TARGET_FPS) 
    drone_gps = {"lat": None, "lon": None}
    mapx, mapy = None, None

    with open(INPUT_FILE, "rb") as f:
        reader = make_reader(f, decoder_factories=[DecoderFactory()])
        for schema, channel, message, ros_msg in reader.iter_decoded_messages(topics=[IMAGE_TOPIC, GPS_TOPIC]):
            
            if channel.topic == GPS_TOPIC:
                drone_gps["lat"] = ros_msg.lat * 1e-7
                drone_gps["lon"] = ros_msg.lon * 1e-7
                continue 

            if channel.topic == IMAGE_TOPIC:
                np_arr = np.frombuffer(ros_msg.data, np.uint8)
                drone_raw = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
                if drone_raw is None: continue

                # --- SQUARE PIXEL CALIBRATION ---
                if mapx is None:
                    h, w = drone_raw.shape[:2]
                    f_mean = (K_ORIGINAL[0,0] + K_ORIGINAL[1,1]) / 2
                    K_square = K_ORIGINAL.copy()
                    K_square[0,0] = K_square[1,1] = f_mean
                    
                    new_K, _ = cv2.getOptimalNewCameraMatrix(K_square, D_COEFFS, (w, h), 0, (w, h))
                    
                    f_final = (new_K[0,0] + new_K[1,1]) / 2
                    new_K[0,0] = new_K[1,1] = f_final
                    
                    mapx, mapy = cv2.initUndistortRectifyMap(K_square, D_COEFFS, None, new_K, (w, h), cv2.CV_32FC1)
                    print(f"✅ Calibrado com Mercantile. Focal: {f_final:.2f}")

                drone_fixed = cv2.remap(drone_raw, mapx, mapy, cv2.INTER_CUBIC)

                # --- MAP LOGIC ---
                if drone_gps["lat"] is not None:
                    if map_state["image"] is None:
                        map_state["image"] = get_google_satellite_tile(drone_gps["lat"], drone_gps["lon"])
                        map_state["last_lat"], map_state["last_lon"] = drone_gps["lat"], drone_gps["lon"]

                    dist = dist_metros(map_state["last_lat"], map_state["last_lon"], drone_gps["lat"], drone_gps["lon"])
                    
                    if dist > 10 and not map_state["is_downloading"]:
                        threading.Thread(target=background_map_updater, 
                                         args=(drone_gps["lat"], drone_gps["lon"]), 
                                         daemon=True).start()
                    
                    if map_state["image"] is not None:
                        drone_display = cv2.resize(drone_fixed, (640, 640))
                        combined = np.hstack((drone_display, map_state["image"]))
                        cv2.imshow("Drone Telemetry - Mercantile Powered", combined)
                
                if cv2.waitKey(frame_delay) & 0xFF == ord('q'): break

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()