import os

from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
from launch_ros.actions import Node

from launch import LaunchDescription


def generate_launch_description():

    navnet_node = Node(
        package="navnet", executable="navnet_node", name="navnet_node", output="screen"
    )

    # Launch do Rosbridge na porta 9090
    rosbridge_launch_dir = os.path.join(get_package_share_directory("rosbridge_server"), "launch")
    rosbridge_server = IncludeLaunchDescription(
        AnyLaunchDescriptionSource(
            os.path.join(rosbridge_launch_dir, "rosbridge_websocket_launch.xml")
        )
    )

    return LaunchDescription([rosbridge_server, navnet_node])
