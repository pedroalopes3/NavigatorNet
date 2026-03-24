import os
import sys

import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image
from vbn_ros_msgs.msg import Attitude, GlobalPositionInt

from navnet.image_preprocessing import CameraCalibrator
from navnet.map_manager import MapRepoManager
from navnet.matcher import SPGlueMatcher


class NavNetNode(Node):
    def __init__(self) -> None:
        super().__init__("navnet_node")
        self.get_logger().info("NavNet node started (Online/Subscriber Mode)")

        self.bridge = CvBridge()

        # --- 1. BUFFERS DE TELEMETRIA ---
        self.gps_buffer = []
        self.att_buffer = []
        self.CAMERA_DELAY_NS = 0

        # --- 2. PUBLISHERS ---
        self.image_pub = self.create_publisher(Image, "/camera/image_calibrated", 10)
        self.raw_image_pub = self.create_publisher(Image, "/camera/image_raw", 10)
        self.map_pub = self.create_publisher(Image, "/camera/map_tile", 10)

        # --- 3. SUBSCRIBERS ---
        # Agora o nó "ouve" o ROS em vez de ler o disco!
        self.create_subscription(GlobalPositionInt, "/global_position_int", self.gps_callback, 10)
        self.create_subscription(Attitude, "/attitude", self.att_callback, 10)
        self.create_subscription(CompressedImage, "/image/compressed", self.image_callback, 10)

        # --- 4. INICIALIZAÇÃO DOS COMPONENTES ---
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
    # CALLBACKS DE TELEMETRIA
    # ==========================================
    def gps_callback(self, msg: GlobalPositionInt):
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
    # CALLBACK DA CÂMARA (O Cérebro do Nó)
    # ==========================================
    def image_callback(self, msg: CompressedImage):
        msg_time = self.get_clock().now().nanoseconds

        # 1. Garantir que já temos telemetria antes de tentar alinhar o mapa
        if not self.gps_buffer or not self.att_buffer:
            return

        # 2. Encontrar a telemetria sincronizada mais próxima no tempo
        target_time = msg_time - self.CAMERA_DELAY_NS
        best_gps = min(self.gps_buffer, key=lambda x: abs(x[0] - target_time))[1]
        best_att = min(self.att_buffer, key=lambda x: abs(x[0] - target_time))[1]

        self.map_manager.update_telemetry_from_msg("/global_position_int", best_gps)
        self.map_manager.update_telemetry_from_msg("/attitude", best_att)

        # 3. Processar a Imagem Raw
        raw_image, calibrated_image = self.calibrator.process_frame(msg.data)
        if calibrated_image is None:
            return

        sec = int(msg_time // 1e9)
        nanosec = int(msg_time % 1e9)

        # 4. Ir buscar o Mapa e passar pela IA
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
                except Exception as e:
                    self.get_logger().error(f"Erro a processar a frame na IA: {e}")

        # 5. Publicar imagens da câmara (Raw e Calibrada)
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

    # Em vez de ler do disco, o nó fica a girar (spin) num ciclo infinito
    # à espera que algum publisher (como o rosbag) dispare os Callbacks!
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
