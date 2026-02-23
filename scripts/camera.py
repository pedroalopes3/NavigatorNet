"""
=============================================================================
MCAP Drone Camera Lens Calibration & Undistortion
=============================================================================

Description:
    This script reads compressed raw image frames from a ROS2 MCAP bag file
    and corrects severe lens distortion (e.g., fisheye/barrel distortion) 
    using OpenCV. 
    
    In addition to flattening the curved image using the camera's original 
    intrinsic matrix (K) and distortion coefficients (D), it forces a square 
    pixel aspect ratio. It achieves this by averaging the horizontal and 
    vertical focal lengths (fx and fy) to create a unified focal length, 
    preventing the final image from appearing stretched.

Key Features:
    - MCAP Parsing: Reads raw drone footage from `/image/compressed`.
    - Square Pixel Correction: Calculates a uniform focal length to fix 
      aspect ratio stretching.
    - Optimal Camera Matrix: Dynamically computes a new K matrix to crop 
      invalid pixels while preserving the corrected field of view.
    - Real-Time Undistortion: Generates remap matrices and applies a cubic 
      interpolation for smooth, high-quality lens correction.
    - Side-by-Side Visualizer: Scales and displays the raw distorted image 
      next to the flattened, calibrated image for immediate comparison.
=============================================================================
"""
import cv2
import numpy as np
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory

# --- USER CONFIGURATION ---
INPUT_FILE = "sample_techinnov_01.mcap"
TOPIC_NAME = "/image/compressed"

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

def main():
    print(f"A processar {INPUT_FILE} com correção de aspeto de píxel...")
    
    mapx, mapy = None, None

    with open(INPUT_FILE, "rb") as f:
        reader = make_reader(f, decoder_factories=[DecoderFactory()])
        
        for schema, channel, message, ros_msg in reader.iter_decoded_messages(topics=[TOPIC_NAME]):
            np_arr = np.frombuffer(ros_msg.data, np.uint8)
            raw_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

            if raw_img is None:
                continue
            
            if mapx is None:
                h, w = raw_img.shape[:2]
                
                # --- CORREÇÃO DE PÍXEIS QUADRADOS ---
                # 1. Calculamos a média das distâncias focais (f_x e f_y)
                f_mean = (K_original[0,0] + K_original[1,1]) / 2
                
                # 2. Criamos uma nova matriz K onde f_x = f_y (Píxeis Quadrados)
                K_square = K_original.copy()
                K_square[0,0] = f_mean
                K_square[1,1] = f_mean
                
                # 3. Geramos a matriz de saída (new_K) garantindo que mantemos f_x = f_y
                # O parâmetro '0' no final ajuda a manter o aspeto
                new_K, roi = cv2.getOptimalNewCameraMatrix(K_square, D, (w, h), 0, (w, h))
                
                # Forçamos novamente f_x = f_y na matriz final para segurança absoluta
                f_final = (new_K[0,0] + new_K[1,1]) / 2
                new_K[0,0] = f_final
                new_K[1,1] = f_final

                # Criar mapas de retificação
                mapx, mapy = cv2.initUndistortRectifyMap(K_square, D, None, new_K, (w, h), cv2.CV_32FC1)
                print(f"Focal original: fx={K_original[0,0]}, fy={K_original[1,1]}")
                print(f"Focal corrigida (Média): {f_final}")

            # Aplicar a retificação com interpolação suave
            calibrated_img = cv2.remap(raw_img, mapx, mapy, cv2.INTER_CUBIC)

            # --- VISUALIZAÇÃO ---
            display_scale = 0.5
            small_raw = cv2.resize(raw_img, None, fx=display_scale, fy=display_scale, interpolation=cv2.INTER_AREA)
            small_calib = cv2.resize(calibrated_img, None, fx=display_scale, fy=display_scale, interpolation=cv2.INTER_AREA)
            
            comparison = np.hstack((small_raw, small_calib))
            cv2.imshow("Pixels Corrigidos (Quadrados)", comparison)
            
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()