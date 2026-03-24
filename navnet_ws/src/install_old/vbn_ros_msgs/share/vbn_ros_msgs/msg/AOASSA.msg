### Message associated with the MAVLINK msg AOA_SSA. See https://mavlink.io/en/messages/ardupilotmega.html#AOA_SSA

# Angle of Attack and Side Slip Angle.


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint64 time_usec    # [us] Timestamp (since boot or Unix epoch).
float32 aoa           # [deg] Angle of Attack.
float32 ssa           # [deg] Side Slip Angle.