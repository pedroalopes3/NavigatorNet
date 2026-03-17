import cv2
import numpy as np
import math
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory

# --- USER CONFIGURATION ---
INPUT_FILE = "sample_techinnov_01.mcap"
TOPIC_IMAGE = "/image/compressed"

# PREENCHA ESTES TÓPICOS COM OS NOMES EXATOS DO SEU ROSBAG
TOPIC_GPS = "/global_position_int" 
TOPIC_ATTITUDE = "/attitude"

# Matriz Intrínseca Original (K)
K_original = np.array([
    [896.602173, 0.0,        1003.954285],
    [0.0,        881.922974, 451.323334],
    [0.0,        0.0,        1.0]
])

# Coeficientes de Distorção (D)
D = np.array([
    1.771178e+00, 3.254712e+00, 4.790912e-03, -3.419381e-03, 
    2.092365e-01, 2.054499e+00, 3.929369e+00, 1.042681e+00
])

ALPHA = 0.2
camera_pitch_offset_deg = 27
camera_roll_offset_deg = -4
EARTH_RADIUS = 6378137.0 # metros

def calculate_incidence_point(lat, lon, alt_m, heading_deg, drone_pitch_rad):
    """
    Calcula o ponto de incidência do centro da câmera no solo.
    Devolve: (inc_lat, inc_lon, angle_from_vertical)
    """
    heading_rad = math.radians(heading_deg)
    camera_pitch_rad = math.radians(camera_pitch_offset_deg)
    
    total_pitch_rad = drone_pitch_rad + camera_pitch_rad
    angle_from_vertical = (math.pi / 2.0) - total_pitch_rad
    
    # Evitar projeção no infinito se a câmera olhar acima do horizonte
    if angle_from_vertical >= math.pi / 2.0:
        return None, None, angle_from_vertical
        
    d = alt_m * math.tan(angle_from_vertical)
    
    dy = d * math.cos(heading_rad)
    dx = d * math.sin(heading_rad)
    
    delta_lat = (dy / EARTH_RADIUS) * (180.0 / math.pi)
    delta_lon = (dx / (EARTH_RADIUS * math.cos(math.radians(lat)))) * (180.0 / math.pi)
    
    inc_lat = lat + delta_lat
    inc_lon = lon + delta_lon
    
    return inc_lat, inc_lon, angle_from_vertical

def main():
    print(f"A processar {INPUT_FILE}...")
    
    mapx, mapy = None, None
    f_final = None # Guardar a distância focal final após calibração
    
    telemetry = {
        'lat': 0.0,
        'lon': 0.0,
        'alt_m': 0.0,
        'heading_deg': 0.0,
        'pitch_rad': 0.0
    }

    with open(INPUT_FILE, "rb") as f:
        reader = make_reader(f, decoder_factories=[DecoderFactory()])
        
        for schema, channel, message, ros_msg in reader.iter_decoded_messages(topics=[TOPIC_IMAGE, TOPIC_GPS, TOPIC_ATTITUDE]):
            
            if channel.topic == TOPIC_GPS:
                telemetry['lat'] = ros_msg.lat * 1e-7
                telemetry['lon'] = ros_msg.lon * 1e-7
                telemetry['alt_m'] = ros_msg.relative_alt * 1e-3 
                telemetry['heading_deg'] = ros_msg.hdg * 1e-2 
                continue
                
            elif channel.topic == TOPIC_ATTITUDE:
                telemetry['pitch_rad'] = ros_msg.pitch 
                continue

            elif channel.topic == TOPIC_IMAGE:
                np_arr = np.frombuffer(ros_msg.data, np.uint8)
                raw_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

                if raw_img is None:
                    continue
                
                # Calibração inicial 
                if mapx is None:
                    h, w = raw_img.shape[:2]
                    f_mean = (K_original[0,0] + K_original[1,1]) / 2
                    K_square = K_original.copy()
                    K_square[0,0] = K_square[1,1] = f_mean
                    
                    new_K, roi = cv2.getOptimalNewCameraMatrix(K_square, D, (w, h), ALPHA, (w, h))
                    
                    # Guardar a distância focal corrigida globalmente
                    f_final = (new_K[0,0] + new_K[1,1]) / 2
                    new_K[0,0] = new_K[1,1] = f_final

                    mapx, mapy = cv2.initUndistortRectifyMap(K_square, D, None, new_K, (w, h), cv2.CV_32FC1)

                calibrated_img = cv2.remap(raw_img, mapx, mapy, cv2.INTER_CUBIC)

                inc_lat, inc_lon, angle_vert = calculate_incidence_point(
                    telemetry['lat'], 
                    telemetry['lon'], 
                    telemetry['alt_m'], 
                    telemetry['heading_deg'], 
                    telemetry['pitch_rad']
                )

                # --- CÁLCULO DO PPM ---
                current_ppm = 0.0
                if inc_lat is not None and telemetry['alt_m'] > 0 and f_final is not None:
                    # Distância inclinada do drone ao ponto central no solo
                    slant_distance = telemetry['alt_m'] / math.cos(angle_vert)
                    # Pixels por metro
                    current_ppm = f_final / slant_distance

                # Overlay no ecrã
                overlay_text = [
                    f"Alt: {telemetry['alt_m']:.2f} m",
                    f"Heading: {telemetry['heading_deg']:.1f} deg",
                    f"Drone Lat/Lon: {telemetry['lat']:.6f}, {telemetry['lon']:.6f}"
                ]
                
                if inc_lat is not None:
                    overlay_text.append(f"Incidence: {inc_lat:.6f}, {inc_lon:.6f}")
                    overlay_text.append(f"PPM: {current_ppm:.2f} px/m")
                else:
                    overlay_text.append("Incidence: N/A (Looking up)")
                    overlay_text.append("PPM: N/A")

                for i, text in enumerate(overlay_text):
                    cv2.putText(calibrated_img, text, (20, 40 + i*35), 
                                cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)

                # --- VISUALIZAÇÃO ---
                display_scale = 0.5
                small_raw = cv2.resize(raw_img, None, fx=display_scale, fy=display_scale, interpolation=cv2.INTER_AREA)
                small_calib = cv2.resize(calibrated_img, None, fx=display_scale, fy=display_scale, interpolation=cv2.INTER_AREA)
                
                comparison = np.hstack((small_raw, small_calib))
                cv2.imshow("Calibracao e Telemetria", comparison)
                
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()