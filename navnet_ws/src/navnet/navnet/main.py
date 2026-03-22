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
        with open(input_file, "rb") as f:
            reader = make_reader(f, decoder_factories=[DecoderFactory()])
            iterator = reader.iter_decoded_messages(topics=[topic_image, topic_gps, topic_attitude])

            # 1. CRIAR BUFFERS DE HISTÓRICO
            gps_buffer = []
            att_buffer = []

            # Ex: Se a câmara estiver 100ms atrasada em relação ao IMU, metes 100_000_000
            CAMERA_DELAY_NS = 0

            for schema, channel, message, ros_msg in iterator:
                if not rclpy.ok():
                    break

                msg_time = message.log_time

                # 2. ALIMENTAR OS BUFFERS
                if channel.topic == topic_gps:
                    gps_buffer.append((msg_time, ros_msg))
                    if len(gps_buffer) > 500:
                        gps_buffer.pop(0)  # Manter apenas as últimas 50
                    continue

                if channel.topic == topic_attitude:
                    att_buffer.append((msg_time, ros_msg))
                    if len(att_buffer) > 500:
                        att_buffer.pop(0)
                    continue

                # 3. PROCESSAR A IMAGEM COM SINCRONIZAÇÃO PERFEITA
                if channel.topic == topic_image:
                    if not gps_buffer or not att_buffer:
                        continue  # Espera até termos telemetria

                    # Encontrar a telemetria mais próxima do tempo da imagem
                    target_time = msg_time - CAMERA_DELAY_NS

                    best_gps = min(gps_buffer, key=lambda x: abs(x[0] - target_time))[1]
                    best_att = min(att_buffer, key=lambda x: abs(x[0] - target_time))[1]

                    # Atualizar o manager APENAS com a telemetria sincronizada
                    node.map_manager.update_telemetry_from_msg(topic_gps, best_gps)
                    node.map_manager.update_telemetry_from_msg(topic_attitude, best_att)

                    raw_image, calibrated_image = node.calibrator.process_frame(ros_msg.data)

                    if calibrated_image is None:
                        continue

                    sec = int(msg_time // 1e9)
                    nanosec = int(msg_time % 1e9)

                    # --- LÓGICA DO MAPA ---
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

                    node.image_pub.publish(calibrated_image_msg)

                    # (O resto do teu código para a raw_image e o spin...)
                    raw_image_msg = node.bridge.cv2_to_imgmsg(raw_image, encoding="bgr8")
                    raw_image_msg.header.stamp.sec = sec
                    raw_image_msg.header.stamp.nanosec = nanosec
                    raw_image_msg.header.frame_id = "camera_link"
                    node.raw_image_pub.publish(raw_image_msg)

                    rclpy.spin_once(node, timeout_sec=0.001)

    except FileNotFoundError:
        node.get_logger().error(f"Ficheiro não encontrado: {input_file}")
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
