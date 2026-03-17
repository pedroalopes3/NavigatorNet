import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node

# Import dependencias
from sensor_msgs.msg import Image

from navnet.image_preprocessing import CameraCalibrator  # Import do calibrator class
from navnet.map_manager import MapRepoManager  # Import do map class


class NavNetNode(Node):
    def __init__(self) -> None:
        super().__init__("navnet_node")
        self.get_logger().info("NavNet node started")

        # Cria a ponte para converter imagens OpenCV para ROS
        self.bridge = CvBridge()

        # Criaçao dos Publishers para a imagem calibrada e para a raw
        self.image_pub = self.create_publisher(Image, "/camera/image_calibrated", 10)
        self.raw_image_pub = self.create_publisher(Image, "/camera/image_raw", 10)

        # Definaçao das matrizes
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

        self.calibrator = CameraCalibrator(
            input_file="bags/sample_techinnov_01.mcap",
            topic_name="/image/compressed",
            K_matrix=K,
            D_coeffs=D,
            alpha=0.2,
        )

        self.calibrator.open()  # Abre o ficheiro MCAP


def main(args: list[str] | None = None) -> None:
    rclpy.init(args=args)
    node = NavNetNode()

    try:
        while rclpy.ok():
            # undistort da imagem e publish
            timestamp_ns, raw_image, calibrated_image = node.calibrator.get_next_frame()

            if calibrated_image is None:
                node.get_logger().info("Fim do ficheiro MCAP atingido.")
                break

            calibrated_image_msg = node.bridge.cv2_to_imgmsg(calibrated_image, encoding="bgr8")
            raw_image_msg = node.bridge.cv2_to_imgmsg(raw_image, encoding="bgr8")

            # addicionar timestamps a ambas as mensagens
            sec = int(timestamp_ns // 1e9)
            nanosec = int(timestamp_ns % 1e9)

            calibrated_image_msg.header.stamp.sec = sec
            calibrated_image_msg.header.stamp.nanosec = nanosec
            calibrated_image_msg.header.frame_id = "camera_link"

            raw_image_msg.header.stamp.sec = sec
            raw_image_msg.header.stamp.nanosec = nanosec
            raw_image_msg.header.frame_id = "camera_link"

            node.image_pub.publish(calibrated_image_msg)
            node.raw_image_pub.publish(raw_image_msg)

            rclpy.spin_once(node, timeout_sec=0.5)

    except KeyboardInterrupt:
        pass
    finally:
        node.calibrator.close()  # fechar o baggYyyyyyy
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
