import math
import os
import sys

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image, NavSatFix
from std_msgs.msg import String
from vbn_ros_msgs.msg import Attitude, GPSRawInt

from navnet.image_preprocessing import CameraCalibrator
from navnet.map_manager import MapRepoManager
from navnet.matcher import SPGlueMatcher
from navnet.pnp import PnPSolver
from navnet.utils import calculate_distance_meters, draw_matches


class NavNetNode(Node):
    def __init__(self) -> None:
        super().__init__("navnet_node")
        self.get_logger().info("NavNet node started")

        # caso o yaml falhe usa estes parametros default

        # camara
        self.declare_parameter(
            "camera.matrix_k", [1000.0, 0.0, 960.0, 0.0, 1000.0, 540.0, 0.0, 0.0, 1.0]
        )
        self.declare_parameter("camera.dist_coeffs", [0.0, 0.0, 0.0, 0.0])
        self.declare_parameter("camera.alpha_calibration", 0.2)

        # pnp
        self.declare_parameter("pnp.reprojection_error", 5.0)
        self.declare_parameter("pnp.confidence", 0.99)
        self.declare_parameter("pnp.interationscount", 2000.0)
        self.declare_parameter("pnp.min_points", 6.0)

        # modelos
        self.declare_parameter("models.scale_cam", 1.0)
        self.declare_parameter("models.scale_map", 1.0)
        self.declare_parameter("models.superpoint.nms_radius", 4)
        self.declare_parameter("models.superpoint.keypoint_threshold", 0.005)
        self.declare_parameter("models.superpoint.max_keypoints", 1024)
        self.declare_parameter("models.superglue.weights", "outdoor")
        self.declare_parameter("models.superglue.sinkhorn_iterations", 20)
        self.declare_parameter("models.superglue.match_threshold", 0.2)

        # carregar
        k_flat = self.get_parameter("camera.matrix_k").value
        d_flat = self.get_parameter("camera.dist_coeffs").value
        alpha_calib = self.get_parameter("camera.alpha_calibration").value

        self.scale_cam = self.get_parameter("models.scale_cam").value
        self.scale_map = self.get_parameter("models.scale_map").value
        self.pnp_reproj_error = self.get_parameter("pnp.reprojection_error").value
        self.confidence = self.get_parameter("pnp.confidence").value
        self.interationscount = self.get_parameter("pnp.interationscount").value
        self.min_points = self.get_parameter("pnp.min_points").value

        self.K_MATRIX = np.array(k_flat, dtype=np.float32).reshape((3, 3))
        self.D_COEFFS = np.array(d_flat, dtype=np.float32)

        ai_config = {
            "superpoint": {
                "nms_radius": self.get_parameter("models.superpoint.nms_radius").value,
                "keypoint_threshold": self.get_parameter(
                    "models.superpoint.keypoint_threshold"
                ).value,
                "max_keypoints": self.get_parameter("models.superpoint.max_keypoints").value,
            },
            "superglue": {
                "weights": self.get_parameter("models.superglue.weights").value,
                "sinkhorn_iterations": self.get_parameter(
                    "models.superglue.sinkhorn_iterations"
                ).value,
                "match_threshold": self.get_parameter("models.superglue.match_threshold").value,
            },
        }

        # Replace your old log line with this:
        self.get_logger().info(
            f"\n{'=' * 50}\n"
            f"Parameters in use in the pipeline\n"
            f"{'=' * 50}\n"
            f"Camera: \n"
            f"  Alpha Calibration: {alpha_calib}\n"
            f"  K Matrix:\n{self.K_MATRIX}\n"
            f"  D Coefficients: {self.D_COEFFS}\n\n"
            f"Models\n"
            f"  Camera Scale: {self.scale_cam}x\n"
            f"  Map Scale:    {self.scale_map}x\n"
            f"  NMS Radius:         {ai_config['superpoint']['nms_radius']}\n"
            f"  Keypoint Threshold: {ai_config['superpoint']['keypoint_threshold']}\n"
            f"  Max Keypoints:      {ai_config['superpoint']['max_keypoints']}\n"
            f"  Weights:             {ai_config['superglue']['weights']}\n"
            f"  Sinkhorn Iterations: {ai_config['superglue']['sinkhorn_iterations']}\n"
            f"  Match Threshold:     {ai_config['superglue']['match_threshold']}\n\n"
            f"PNP/Ransac\n"
            f"  Reprojection Error:  {self.pnp_reproj_error} px\n"
            f"  Confidence:          {self.confidence * 100}%\n"
            f"  Interations count:   {self.interationscount}\n"
            f"  Min points:          {self.min_points}\n"
            f"{'=' * 50}"
        )

        self.bridge = CvBridge()

        # BUFFERS
        self.gps_buffer = []
        self.att_buffer = []
        self.CAMERA_DELAY_NS = 0

        # PUBLISHERS
        self.image_pub = self.create_publisher(CompressedImage, "/camera/image_calibrated", 10)
        self.raw_image_pub = self.create_publisher(CompressedImage, "/camera/image_raw", 10)
        self.map_pub = self.create_publisher(CompressedImage, "/camera/map_tile", 10)
        self.matches_pub = self.create_publisher(CompressedImage, "/camera/matches", 10)
        self.norm_matches_pub = self.create_publisher(String, "/matches_normalized", 10)
        self.gps_map_pub = self.create_publisher(NavSatFix, "/map/gps_raw", 10)
        self.vision_map_pub = self.create_publisher(NavSatFix, "/map/navnet_estimation", 10)

        # SUBSCRIBERS
        self.create_subscription(GPSRawInt, "/gps_raw_int", self.gps_callback, 10)
        self.create_subscription(Attitude, "/attitude", self.att_callback, 10)
        self.create_subscription(CompressedImage, "/image/compressed", self.image_callback, 10)

        # garbage
        # # INICIALIZAÇÃO DOS COMPONENTES
        # K = [[896.602173, 0.0, 1003.954285], [0.0, 881.922974, 451.323334], [0.0, 0.0, 1.0]]
        # D = [
        #     1.771178e00,
        #     3.254712e00,
        #     4.790912e-03,
        #     -3.419381e-03,
        #     2.092365e-01,
        #     2.054499e00,
        #     3.929369e00,
        #     1.042681e00,
        # ]
        # self.calibrator = CameraCalibrator(K_matrix=K, D_coeffs=D, alpha=0.2)
        # self.pnp_solver = PnPSolver(K, D)

        #############################
        # init dos modulos
        self.calibrator = CameraCalibrator(self.K_MATRIX, self.D_COEFFS, alpha=alpha_calib)
        self.matcher = SPGlueMatcher(custom_config=ai_config)
        self.pnp_solver = PnPSolver(
            self.K_MATRIX,
            self.D_COEFFS,
            self.pnp_reproj_error,
            self.confidence,
            self.min_points,
            self.interationscount,
        )

        self.map_manager = MapRepoManager("/workspace/tiles_output")
        self.map_manager.analyze()

        ###################################

        try:
            self.matcher = SPGlueMatcher()
            self.get_logger().info("Redes SuperPoint e SuperGlue iniciadas com sucesso!")
        except Exception as e:
            self.get_logger().error(f"Falha ao carregar a IA: {e}")

    # =========================================================================
    # CALLBACK SENSORES
    # =========================================================================
    def gps_callback(self, msg: GPSRawInt):
        t = self.get_clock().now().nanoseconds
        self.gps_buffer.append((t, msg))
        if len(self.gps_buffer) > 500:
            self.gps_buffer.pop(0)

    def att_callback(self, msg: Attitude):
        t = self.get_clock().now().nanoseconds
        self.att_buffer.append((t, msg))
        if len(self.att_buffer) > 500:
            self.att_buffer.pop(0)

    # =========================================================================
    # FUNÇÕES AUXILIARES (depois meter no utils)
    # =========================================================================
    def _sync_telemetry(self, target_time):
        best_gps = min(self.gps_buffer, key=lambda x: abs(x[0] - target_time))[1]
        best_att = min(self.att_buffer, key=lambda x: abs(x[0] - target_time))[1]

        lat_deg = best_gps.lat * 1e-7
        lon_deg = best_gps.lon * 1e-7
        alt_m = best_gps.alt * 1e-3

        heading_deg = math.degrees(best_att.yaw)
        if heading_deg < 0:
            heading_deg += 360.0

        return lat_deg, lon_deg, alt_m, heading_deg, best_att.pitch, best_att.roll

    def _meters_to_lat_lon(self, drone_x_este, drone_y_norte):
        lat_origem = self.map_manager.map_origin_lat
        lon_origem = self.map_manager.map_origin_lon
        raio_terra = self.map_manager.EARTH_RADIUS

        delta_lat_rad = drone_y_norte / raio_terra
        delta_lon_rad = drone_x_este / (raio_terra * math.cos(math.radians(lat_origem)))

        calc_lat = lat_origem - math.degrees(delta_lat_rad)
        calc_lon = lon_origem + math.degrees(delta_lon_rad)

        return calc_lat, calc_lon

    ## publisher for image topics
    def _publish_cv2_image(self, publisher, cv_image, sec, nanosec, frame_id="camera_link"):
        if cv_image is None:
            return
        img_msg = self.bridge.cv2_to_compressed_imgmsg(cv_image, dst_format="jpg")
        img_msg.header.stamp.sec = sec
        img_msg.header.stamp.nanosec = nanosec
        img_msg.header.frame_id = frame_id
        publisher.publish(img_msg)

    # =========================================================================
    # CALLBACK PRINCIPAL DA IMAGEM
    # =========================================================================
    def image_callback(self, msg: CompressedImage):
        msg_time = self.get_clock().now().nanoseconds

        if not self.gps_buffer or not self.att_buffer:
            return

        # Sincronizar e Atualizar telemtria
        target_time = msg_time - self.CAMERA_DELAY_NS
        lat_deg, lon_deg, alt_m, heading_deg, pitch_rad, roll_rad = self._sync_telemetry(
            target_time
        )

        self.map_manager.update_gps(lat_deg, lon_deg, alt_m, heading_deg)
        self.map_manager.update_attitude(pitch_rad, roll_rad)

        # Processar a Imagem
        raw_image, calibrated_image = self.calibrator.process_frame(msg.data)
        if calibrated_image is None:
            return

        sec = int(msg_time // 1e9)
        nanosec = int(msg_time % 1e9)

        # Lógica Principal de Navegação Visual
        if self.calibrator.f_final is not None and self.map_manager.current_telemetry["lat"] != 0.0:
            self.pnp_solver.K = self.calibrator.new_K
            self.pnp_solver.D = np.zeros((4, 1), dtype=np.float32)

            map_img, map_info = self.map_manager.get_map_for_telemetry(
                f_final=self.calibrator.f_final
            )

            if map_img is not None:
                self._publish_cv2_image(self.map_pub, map_img, sec, nanosec)

                try:
                    scale_cam, scale_map = self.scale_cam, self.scale_map
                    h_cam, w_cam = calibrated_image.shape[:2]
                    h_map, w_map = map_img.shape[:2]

                    cam_leve = cv2.resize(
                        calibrated_image, (int(w_cam / scale_cam), int(h_cam / scale_cam))
                    )
                    map_leve = cv2.resize(map_img, (int(w_map / scale_map), int(h_map / scale_map)))

                    kp1_small, kp2_small = self.matcher.match(cam_leve, map_leve)
                    num_pontos = kp1_small.shape[1]

                    if num_pontos > 0:
                        kp1 = kp1_small * scale_cam
                        kp2 = kp2_small * scale_map

                        m_este, m_norte = self.map_manager.get_matches_in_meters(kp2, map_info)

                        matches_img = draw_matches(calibrated_image, map_img, kp1, kp2)

                        if num_pontos >= self.min_points:
                            sucesso, posicao_drone, inliers = self.pnp_solver.solve(
                                kp1, m_este, m_norte
                            )

                            if sucesso:
                                drone_x_este, drone_y_norte, drone_z_alt = posicao_drone

                                calc_lat, calc_lon = self._meters_to_lat_lon(
                                    drone_x_este, drone_y_norte
                                )

                                erro_metros = calculate_distance_meters(
                                    lat_deg, lon_deg, calc_lat, calc_lon
                                )

                                self.get_logger().info(
                                    f"\n Pnp ransac\n"
                                    f"Inliers do RANSAC: {len(inliers)}/{num_pontos}\n"
                                    f"GPS Sensor: Lat {lat_deg:.6f}, Lon {lon_deg:.6f}\n"
                                    f"Estimativa: Lat {calc_lat:.6f}, Lon {calc_lon:.6f}\n"
                                    f"Erro de Posição: {erro_metros:.1f} metros\n"
                                    f"Altitude Visual: {drone_z_alt:.1f}m\n"
                                )

                                # gps raw map topic for foxglove ()
                                gps_msg = NavSatFix()
                                gps_msg.header.stamp.sec = sec
                                gps_msg.header.stamp.nanosec = nanosec
                                gps_msg.header.frame_id = "earth"
                                gps_msg.latitude = float(lat_deg)
                                gps_msg.longitude = float(lon_deg)
                                gps_msg.altitude = float(
                                    self.map_manager.current_telemetry["alt_m"]
                                )
                                self.gps_map_pub.publish(gps_msg)

                                # navnet estimation map topic for foxglove ()
                                vision_msg = NavSatFix()
                                vision_msg.header.stamp.sec = sec
                                vision_msg.header.stamp.nanosec = nanosec
                                vision_msg.header.frame_id = "earth"
                                vision_msg.latitude = float(calc_lat)
                                vision_msg.longitude = float(calc_lon)
                                vision_msg.altitude = float(drone_z_alt)
                                self.vision_map_pub.publish(vision_msg)

                            else:
                                self.get_logger().warn(
                                    "Aviso: RANSAC rejeitou a geometria. Posição não resolvida."
                                )
                        else:
                            self.get_logger().warn(
                                f"Aviso: Apenas {num_pontos} matches. O PnP exige >= {self.min_points:.1f}"
                            )

                        self._publish_cv2_image(self.matches_pub, matches_img, sec, nanosec)

                except Exception as e:
                    self.get_logger().error(f"Erro a processar a frame na IA: {e}")

        # 4. Publicar fluxos de imagem base
        self._publish_cv2_image(self.image_pub, calibrated_image, sec, nanosec)
        self._publish_cv2_image(self.raw_image_pub, raw_image, sec, nanosec)


def main(args=None) -> None:
    rclpy.init(args=args)
    node = NavNetNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
