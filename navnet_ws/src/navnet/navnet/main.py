import math
import os
import sys

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image
from vbn_ros_msgs.msg import Attitude, GPSRawInt

from navnet.image_preprocessing import CameraCalibrator
from navnet.map_manager import MapRepoManager
from navnet.matcher import SPGlueMatcher


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

        self.map_manager = MapRepoManager("/workspace/tiles_output")
        self.map_manager.analyze()

        try:
            self.matcher = SPGlueMatcher()
            self.get_logger().info("Redes SuperPoint e SuperGlue iniciadas com sucesso!")
        except Exception as e:
            self.get_logger().error(f"Falha ao carregar a IA: {e}")

    # ==========================================
    # FUNÇÃO DE DESENHO DOS MATCHES (OpenCV)
    # ==========================================
    def draw_matches(self, img1, img2, kp1, kp2):
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

    # ==========================================
    # CALLBACKS
    # ==========================================
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

    # ==========================================
    # CALLBACK DA CAMARA
    # ==========================================
    def image_callback(self, msg: CompressedImage):
        msg_time = self.get_clock().now().nanoseconds

        if not self.gps_buffer or not self.att_buffer:
            return

        target_time = msg_time - self.CAMERA_DELAY_NS
        best_gps = min(self.gps_buffer, key=lambda x: abs(x[0] - target_time))[1]
        best_att = min(self.att_buffer, key=lambda x: abs(x[0] - target_time))[1]

        lat_deg = best_gps.lat * 1e-7
        lon_deg = best_gps.lon * 1e-7
        alt_m = best_gps.alt * 1e-3
        heading_deg = math.degrees(best_att.yaw)
        if heading_deg < 0:
            heading_deg += 360.0

        pitch_rad = best_att.pitch
        roll_rad = best_att.roll

        # Passar dados limpos (float) para o gestor de mapas
        self.map_manager.update_gps(lat_deg, lon_deg, alt_m, heading_deg)
        self.map_manager.update_attitude(pitch_rad, roll_rad)
        # ----------------------------------------------------

        raw_image, calibrated_image = self.calibrator.process_frame(msg.data)
        if calibrated_image is None:
            return

        sec = int(msg_time // 1e9)
        nanosec = int(msg_time % 1e9)

        if self.calibrator.f_final is not None and self.map_manager.current_telemetry["lat"] != 0.0:
            map_img, map_info = self.map_manager.get_map_for_telemetry(
                f_final=self.calibrator.f_final
            )

            if map_img is not None:
                map_image_msg = self.bridge.cv2_to_imgmsg(map_img, encoding="bgr8")
                map_image_msg.header.stamp.sec = sec
                map_image_msg.header.stamp.nanosec = nanosec
                map_image_msg.header.frame_id = "camera_link"
                self.map_pub.publish(map_image_msg)

                try:
                    kp1, kp2 = self.matcher.match(calibrated_image, map_img)
                    self.get_logger().info(f"Encontrados {kp1.shape[1]} matches com o SuperGlue!")

                    if kp1.shape[1] > 0:
                        matches_img = self.draw_matches(calibrated_image, map_img, kp1, kp2)
                        m_este, m_norte = self.map_manager.get_matches_in_meters(kp2, map_info)
                        num_pontos = kp1.shape[1]
                        media_este = np.mean(m_este)
                        media_norte = np.mean(m_norte)

                        self.get_logger().info(
                            f"\n--- MATCHES MÉTRICOS --- \n"
                            f"Total Encontrados: {num_pontos}\n"
                            f"Match #0: Este {m_este[0]:.2f}m | Norte {m_norte[0]:.2f}m\n"
                            f"Centroide (Média): Este {media_este:.2f}m | Norte {media_norte:.2f}m"
                        )

                        matches_msg = self.bridge.cv2_to_imgmsg(matches_img, encoding="bgr8")
                        matches_msg.header.stamp.sec = sec
                        matches_msg.header.stamp.nanosec = nanosec
                        matches_msg.header.frame_id = "camera_link"
                        self.matches_pub.publish(matches_msg)

                except Exception as e:
                    self.get_logger().error(f"Erro a processar a frame na IA: {e}")

        # Publicar imagens da câmara normais
        calibrated_image_msg = self.bridge.cv2_to_imgmsg(calibrated_image, encoding="bgr8")
        calibrated_image_msg.header.stamp.sec = sec
        calibrated_image_msg.header.stamp.nanosec = nanosec
        calibrated_image_msg.header.frame_id = "camera_link"
        self.image_pub.publish(calibrated_image_msg)

        raw_image_msg = self.bridge.cv2_to_imgmsg(raw_image, encoding="bgr8")
        raw_image_msg.header.stamp.sec = sec
        raw_image_msg.header.stamp.nanosec = nanosec
        raw_image_msg.header.frame_id = "camera_link"
        self.raw_image_pub.publish(raw_image_msg)


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
