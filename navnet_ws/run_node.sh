#!/bin/bash
# Clean environment and run the navn node

# Clear old ROS environment variables
unset AMENT_PREFIX_PATH CMAKE_PREFIX_PATH LD_LIBRARY_PATH ROS_PACKAGE_PATH PYTHONPATH COLCON_PREFIX_PATH

# Change to workspace and source clean setup
cd /workspace
source install/setup.bash

# Run the node
/workspace/install/n*/lib/n*/n*_node "$@"
