### Message associated with the MAVLINK msg AHRS. See https://mavlink.io/en/messages/ardupilotmega.html#AHRS

# Status of DCM attitude estimator.


# Header - this will contain the ROS timestamp
std_msgs/Header header

float32 omega_ix       # [rad/s] X gyro drift estimate.
float32 omega_iy       # [rad/s] Y gyro drift estimate.
float32 omega_iz       # [rad/s] Z gyro drift estimate.
float32 accel_weight  # Average accel_weight.
float32 renorm_val    # Average renormalisation value.
float32 error_rp      # Average error_roll_pitch value.
float32 error_yaw     # Average error_yaw value.