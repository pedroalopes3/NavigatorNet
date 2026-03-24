### Message associated with the MAVLINK msg ATTITUDE. See https://mavlink.io/en/messages/common.html#ATTITUDE

# The attitude in the aeronautical frame (right-handed, Z-down, Y-right, X-front, ZYX, intrinsic).


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint32 time_boot_ms # [ms] Timestamp (time since system boot).
float32 roll          # [rad] Roll angle (-pi..+pi)
float32 pitch         # [rad] Pitch angle (-pi..+pi)
float32 yaw           # [rad] Yaw angle (-pi..+pi)
float32 rollspeed     # [rad/s] Roll angular speed
float32 pitchspeed    # [rad/s] Pitch angular speed
float32 yawspeed      # [rad/s] Yaw angular speed