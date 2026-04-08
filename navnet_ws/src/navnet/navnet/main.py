import math
import os
import sys

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image
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

        self.bridge = CvBridge()

        # BUFFERS
        self.gps_buffer = []
        self.att_buffer = []
        self.CAMERA_DELAY_NS = 0

        # PUBLISHERS
        self.image_pub = self.create_publisher(Image, "/camera/image_calibrated", 10)
        self.raw_image_pub = self.create_publisher(Image, "/camera/image_raw", 10)
        self.map_pub = self.create_publisher(Image, "/camera/map_tile", 10)
        self.matches_pub = self.create_publisher(Image, "/camera/matches", 10)
        self.norm_matches_pub = self.create_publisher(String, "/matches_normalized", 10)

        # SUBSCRIBERS
        self.create_subscription(GPSRawInt, "/gps_raw_int", self.gps_callback, 10)
        self.create_subscription(Attitude, "/attitude", self.att_callback, 10)
        self.create_subscription(CompressedImage, "/image/compressed", self.image_callback, 10)

        # INICIALIZAÇÃO DOS COMPONENTES
        K = [[896.602173, 0.0, 1003.954285], [0.0, 881.922974, 451.323334], [0.0, 0.0, 1.0]]
        D = [
            1.771178e00,
            3.254712e00,
            4.790912e-03,
            -3.419381e-03,
            2.092365e-01,
            2.054499e00,
            3.929369e00,
            1.042681e00,
        ]
        self.calibrator = CameraCalibrator(K_matrix=K, D_coeffs=D, alpha=0.2)
        self.pnp_solver = PnPSolver(K, D)

        self.map_manager = MapRepoManager("/workspace/tiles_output")
        self.map_manager.analyze()

        try:
            self.matcher = SPGlueMatcher()
            self.get_logger().info("Redes SuperPoint e SuperGlue iniciadas com sucesso!")
        except Exception as e:
            self.get_logger().error(f"Falha ao carregar a IA: {e}")

    # =========================================================================
    # CALLBACKS DOS SENSORES (Tem de ficar aqui porque usam o self.buffer)
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
    # FUNÇÕES AUXILIARES DO ROS (Tem de ficar aqui porque acedem ao self)
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

        calc_lat = lat_origem + math.degrees(delta_lat_rad)
        calc_lon = lon_origem + math.degrees(delta_lon_rad)

        return calc_lat, calc_lon

    def _publish_cv2_image(self, publisher, cv_image, sec, nanosec, frame_id="camera_link"):
        if cv_image is None:
            return
        img_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
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

        # 1. Sincronizar e Atualizar Telemetria
        target_time = msg_time - self.CAMERA_DELAY_NS
        lat_deg, lon_deg, alt_m, heading_deg, pitch_rad, roll_rad = self._sync_telemetry(
            target_time
        )

        self.map_manager.update_gps(lat_deg, lon_deg, alt_m, heading_deg)
        self.map_manager.update_attitude(pitch_rad, roll_rad)

        # 2. Processar a Imagem
        raw_image, calibrated_image = self.calibrator.process_frame(msg.data)
        if calibrated_image is None:
            return

        sec = int(msg_time // 1e9)
        nanosec = int(msg_time % 1e9)

        # 3. Lógica Principal de Navegação Visual
        if self.calibrator.f_final is not None and self.map_manager.current_telemetry["lat"] != 0.0:
            self.pnp_solver.K = self.calibrator.new_K
            self.pnp_solver.D = np.zeros((4, 1), dtype=np.float32)

            map_img, map_info = self.map_manager.get_map_for_telemetry(
                f_final=self.calibrator.f_final
            )

            if map_img is not None:
                self._publish_cv2_image(self.map_pub, map_img, sec, nanosec)

                try:
                    scale_cam, scale_map = 1.0, 1.0
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

                        if num_pontos >= 4:
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

                            else:
                                self.get_logger().warn(
                                    "Aviso: RANSAC rejeitou a geometria. Posição não resolvida."
                                )
                        else:
                            self.get_logger().warn(
                                f"Aviso: Apenas {num_pontos} matches. O PnP exige >= 4."
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
