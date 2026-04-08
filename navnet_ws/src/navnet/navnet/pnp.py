import cv2
import numpy as np


class PnPSolver:
    def __init__(self, camera_matrix, dist_coeffs):
        """
        Inicializa o solver com as matrizes intrínsecas da lente da câmara.
        """
        self.K = np.array(camera_matrix, dtype=np.float32)
        self.D = np.array(dist_coeffs, dtype=np.float32)

    def solve(self, image_points_2d, object_x_m, object_y_m):

        # Calcula a pose 3D do drone no mundo usando PnP RANSAC.

        num_matches = image_points_2d.shape[1]

        # PNP precisa de pelo menos 4 pontos para 3 dimensoes!
        if num_matches < 4:
            return False, None, None

        object_points = np.zeros((num_matches, 3), dtype=np.float32)
        object_points[:, 0] = object_x_m
        object_points[:, 1] = object_y_m
        object_points[:, 2] = 0.0  # Assumimos que o chao do mapa é plano

        image_points = image_points_2d.T.astype(np.float32)

        sucesso, rvec, tvec, inliers = cv2.solvePnPRansac(
            objectPoints=object_points,
            imagePoints=image_points,
            cameraMatrix=self.K,
            distCoeffs=self.D,
            reprojectionError=5.0,  # Se um ponto fugir mais de 5 píxeis e rejeitado, experimentar umanetar para dar mais hits
            confidence=0.99,
            flags=cv2.SOLVEPNP_IPPE,
        )

        if not sucesso or inliers is None:
            return False, None, None

        # Inverte a matriz para obter a posição da camara no mundo (C_mundo = -R^T * tvec)
        R, _ = cv2.Rodrigues(rvec)
        R_inv = np.transpose(R)
        camera_position_world = -np.dot(R_inv, tvec)

        # Extrair as coordenadas finais em metros
        drone_x_este = camera_position_world[0][0]
        drone_y_norte = camera_position_world[1][0]
        drone_z_alt = camera_position_world[2][0]

        return True, (drone_x_este, drone_y_norte, drone_z_alt), inliers
