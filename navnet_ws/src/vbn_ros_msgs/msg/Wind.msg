### Message associated with the MAVLINK msg WIND. See https://mavlink.io/en/messages/ardupilotmega.html#WIND

# Wind estimation.


# Header - this will contain the ROS timestamp
std_msgs/Header header

float32 direction # [deg] Wind direction (that wind is coming from).
float32 speed     # [m/s] Wind speed in ground plane.
float32 speed_z   # [m/s] Vertical wind speed.