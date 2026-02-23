### Custom message to store the attitude


# Header - this will contain the ROS timestamp
std_msgs/Header header

float32 roll        # [rad] Roll angle (-pi..+pi)
float32 pitch       # [rad] Pitch angle (-pi..+pi)
float32 yaw         # [rad] Yaw angle (-pi..+pi)
bool degrees        # Boolean defining whether the data is in degrees
string sequence     # Euler angle sequence. Uppercase for extrinsic and lowercase for intrinsic.