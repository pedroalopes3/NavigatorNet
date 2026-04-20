import cv2
import numpy as np


class PnPSolver:
    def __init__(self, camera_matrix, dist_coeffs, reproj_err, conf, min_points, interationscount):
        """
        Inicializa o solver com as matrizes intrínsecas da lente da câmara.
        """
        self.K = np.array(camera_matrix, dtype=np.float32)
        self.D = np.array(dist_coeffs, dtype=np.float32)
        self.r_error = reproj_err
        self.conf = conf
        self.min_points = min_points
        self.interationscount = interationscount

    def solve(self, image_points_2d, object_x_m, object_y_m):

        num_matches = image_points_2d.shape[1]
        if num_matches < self.min_points:
            return False, None, None

        object_points = np.zeros((num_matches, 3), dtype=np.float32)
        object_points[:, 0] = object_x_m
        object_points[:, 1] = object_y_m
        object_points[:, 2] = 0.0  # Por enquanto assumimos que o chao do mapa é plano

        image_points = image_points_2d.T.astype(np.float32)

        sucesso, rvec, tvec, inliers = cv2.solvePnPRansac(
            objectPoints=object_points,
            imagePoints=image_points,
            cameraMatrix=self.K,
            distCoeffs=self.D,
            reprojectionError=self.r_error,
            confidence=self.conf,
            iterationsCount=int(self.interationscount),
            flags=cv2.SOLVEPNP_SQPNP,
        )

        if not sucesso or inliers is None or len(inliers) < 6:
            return False, None, None

        # refine with inliers only
        inlier_obj = object_points[inliers[:, 0]]
        inlier_img = image_points[inliers[:, 0]]
        _, rvec, tvec = cv2.solvePnP(
            inlier_obj,
            inlier_img,
            self.K,
            self.D,
            rvec=rvec,
            tvec=tvec,
            useExtrinsicGuess=True,
            flags=cv2.SOLVEPNP_ITERATIVE,
        )

        # Inverte a matriz para obter a posição da camara no mundo (C_mundo = -R^T * tvec)
        R, _ = cv2.Rodrigues(rvec)
        # Camera position in world: C = -R^T * t
        camera_position_world = -R.T @ tvec

        # Extrair as coordenadas finais em metros
        drone_x_este = camera_position_world[0][0]
        drone_y_norte = camera_position_world[1][0]
        drone_z_alt = camera_position_world[2][0]

        # no negative alt admited for the final estimation
        if drone_z_alt < 0:
            drone_z_alt = abs(drone_z_alt)

        return True, (drone_x_este, drone_y_norte, drone_z_alt), inliers
