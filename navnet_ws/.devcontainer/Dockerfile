FROM ros:humble-ros-base

COPY --from=ghcr.io/astral-sh/uv:latest /uv /uvx /bin/

# Frontend não interativo 
ENV DEBIAN_FRONTEND=noninteractive

# Dependências (apt)
RUN apt-get update && apt-get install -y \
    python3.10 \
    python3.10-dev \
    python3-pip \
    python3-opencv \
    ros-humble-rosbag2 \
    ros-humble-rosbag2-storage-default-plugins \
    ros-humble-cv-bridge \
    ros-humble-sensor-msgs-py \
    ros-humble-rosbag2-storage-mcap \
    ros-humble-foxglove-bridge \
    nano \
    && rm -rf /var/lib/apt/lists/*


RUN uv pip install --system --no-cache \
    numpy \
    mypy \
    ruff \
    pytest

WORKDIR /workspace

# ~/.bashrc para dar source do ROS 2 e o workspace automaticamente
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc && \
    echo "if [ -f /workspace/install/setup.bash ]; then source /workspace/install/setup.bash; fi" >> ~/.bashrc

CMD ["/bin/bash"]