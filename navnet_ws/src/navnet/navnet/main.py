import sys

import rclpy
from cv_bridge import CvBridge
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory
from rclpy.node import Node
from sensor_msgs.msg import Image

from navnet.image_preprocessing import CameraCalibrator
from navnet.map_manager import MapRepoManager


class NavNetNode(Node):
    def __init__(self) -> None:
        super().__init__("navnet_node")
        self.get_logger().info("NavNet node started")

        self.bridge = CvBridge()
        self.image_pub = self.create_publisher(Image, "/camera/image_calibrated", 10)
        self.raw_image_pub = self.create_publisher(Image, "/camera/image_raw", 10)
        self.map_pub = self.create_publisher(Image, "/camera/map_tile", 10)

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

        # Inicializa o calibrador sem abrir ficheiros
        self.calibrator = CameraCalibrator(K_matrix=K, D_coeffs=D, alpha=0.2)

        # Inicializa o mapa
        self.map_manager = MapRepoManager("/workspace/tiles_output")
        self.map_manager.analyze()


def main(args: list[str] | None = None) -> None:
    rclpy.init(args=args)
    node = NavNetNode()

    input_file = "/workspace/bags/sample_techinnov_01.mcap"
    topic_image = "/image/compressed"
    topic_gps = "/global_position_int"
    topic_attitude = "/attitude"

    try:
        # O main.py é que abre o ficheiro agora!
        with open(input_file, "rb") as f:
            reader = make_reader(f, decoder_factories=[DecoderFactory()])
            iterator = reader.iter_decoded_messages(topics=[topic_image, topic_gps, topic_attitude])

            for schema, channel, message, ros_msg in iterator:
                if not rclpy.ok():
                    break

                # 1. Atualizar Telemetria
                if channel.topic in [topic_gps, topic_attitude]:
                    node.map_manager.update_telemetry_from_msg(channel.topic, ros_msg)
                    continue  # Volta para o topo do loop e procura a próxima mensagem

                # 2. Processar Imagem e Mapa (Apenas quando aparece uma imagem do drone)
                if channel.topic == topic_image:
                    timestamp_ns = message.log_time
                    raw_image, calibrated_image = node.calibrator.process_frame(ros_msg.data)

                    if calibrated_image is None:
                        continue

                    # Calcular tempos
                    sec = int(timestamp_ns // 1e9)
                    nanosec = int(timestamp_ns % 1e9)

                    # --- LÓGICA DO MAPA ---
                    # Apenas pede o mapa se o calibrador já tiver calculado o f_final
                    if (
                        node.calibrator.f_final is not None
                        and node.map_manager.current_telemetry["lat"] != 0.0
                    ):
                        map_img, map_info = node.map_manager.get_map_for_telemetry(
                            f_final=node.calibrator.f_final
                        )

                        if map_img is not None:
                            map_image_msg = node.bridge.cv2_to_imgmsg(map_img, encoding="bgr8")
                            map_image_msg.header.stamp.sec = sec
                            map_image_msg.header.stamp.nanosec = nanosec
                            map_image_msg.header.frame_id = "camera_link"
                            node.map_pub.publish(map_image_msg)

                    # --- LÓGICA DA CÂMARA ---
                    calibrated_image_msg = node.bridge.cv2_to_imgmsg(
                        calibrated_image, encoding="bgr8"
                    )
                    calibrated_image_msg.header.stamp.sec = sec
                    calibrated_image_msg.header.stamp.nanosec = nanosec
                    calibrated_image_msg.header.frame_id = "camera_link"

                    raw_image_msg = node.bridge.cv2_to_imgmsg(raw_image, encoding="bgr8")
                    raw_image_msg.header.stamp.sec = sec
                    raw_image_msg.header.stamp.nanosec = nanosec
                    raw_image_msg.header.frame_id = "camera_link"

                    node.image_pub.publish(calibrated_image_msg)
                    node.raw_image_pub.publish(raw_image_msg)

                    rclpy.spin_once(
                        node, timeout_sec=0.01
                    )  # Um timeout curto para não parar o vídeo

            node.get_logger().info("Fim do ficheiro MCAP atingido.")

    except FileNotFoundError:
        node.get_logger().error(f"Ficheiro não encontrado: {input_file}")
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
