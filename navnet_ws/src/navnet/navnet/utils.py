import math
import cv2
import numpy as np


# ==========================================
# Função que calcula o erro
# ==========================================
def calculate_distance_meters(lat1, lon1, lat2, lon2):
    """Calcula a distância entre dois pontos GPS em metros usando a Fórmula de Haversine."""
    R = 6371000.0  # Raio da Terra em metros

    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)

    a = (
        math.sin(delta_phi / 2.0) ** 2
        + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2.0) ** 2
    )

    c = 2.0 * math.atan2(math.sqrt(a), math.sqrt(1.0 - a))

    return R * c


# ==========================================
# Função de desenho dos matches (OpenCV)    
# ==========================================
def draw_matches(img1, img2, kp1, kp2):
    """Desenha as linhas ligando os keypoints entre a imagem da câmara e o mapa."""
    h1, w1 = img1.shape[:2]
    h2, w2 = img2.shape[:2]

    h_max = max(h1, h2)
    w_sum = w1 + w2
    out_img = np.zeros((h_max, w_sum, 3), dtype=np.uint8)

    if len(img1.shape) == 2:
        img1 = cv2.cvtColor(img1, cv2.COLOR_GRAY2BGR)
    if len(img2.shape) == 2:
        img2 = cv2.cvtColor(img2, cv2.COLOR_GRAY2BGR)

    out_img[:h1, :w1] = img1
    out_img[:h2, w1 : w1 + w2] = img2

    for i in range(kp1.shape[1]):
        x1, y1 = int(kp1[0, i]), int(kp1[1, i])
        x2, y2 = int(kp2[0, i]) + w1, int(kp2[1, i])

        cv2.line(out_img, (x1, y1), (x2, y2), (0, 255, 0), 1)
        cv2.circle(out_img, (x1, y1), 3, (0, 0, 255), -1)
        cv2.circle(out_img, (x2, y2), 3, (255, 0, 0), -1)

    return out_img
