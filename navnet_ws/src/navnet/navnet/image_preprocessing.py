import cv2
import numpy as np


class CameraCalibrator:
    def __init__(self, K_matrix, D_coeffs, alpha=0.2):
        self.K_original = np.array(K_matrix)
        self.D = np.array(D_coeffs)
        self.alpha = alpha

        # Estado interno da calibração
        self.mapx = None
        self.mapy = None
        self.f_final = None

    def _initialize_calibration(self, h, w):
        """Calcula os mapas de retificação na primeira vez que recebe uma imagem."""
        f_mean = (self.K_original[0, 0] + self.K_original[1, 1]) / 2

        K_square = self.K_original.copy()
        K_square[0, 0] = K_square[1, 1] = f_mean

        new_K, roi = cv2.getOptimalNewCameraMatrix(K_square, self.D, (w, h), self.alpha, (w, h))

        self.f_final = (new_K[0, 0] + new_K[1, 1]) / 2
        new_K[0, 0] = new_K[1, 1] = self.f_final

        self.new_K = new_K

        self.mapx, self.mapy = cv2.initUndistortRectifyMap(
            K_square, self.D, None, new_K, (w, h), cv2.CV_32FC1
        )
        print(f"[Calibrator] Inicializado. Resolução: {w}x{h} | Focal Final: {self.f_final:.2f} px")

    def process_frame(self, raw_img_data):
        """Recebe os dados brutos da imagem e devolve a imagem calibrada."""
        np_arr = np.frombuffer(raw_img_data, np.uint8)
        raw_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        if raw_img is None:
            return None, None

        if self.mapx is None:
            h, w = raw_img.shape[:2]
            self._initialize_calibration(h, w)

        calibrated_img = cv2.remap(raw_img, self.mapx, self.mapy, cv2.INTER_CUBIC)

        return raw_img, calibrated_img
