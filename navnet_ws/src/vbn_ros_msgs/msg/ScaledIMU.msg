### Message associated with the MAVLINK msg SCALED_IMU. See https://mavlink.io/en/messages/common.html#SCALED_IMU

# The RAW IMU readings for 9DOF sensor setup. This message should contain the scaled values to the described units


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint64 time_boot_ms # [ms] Timestamp (time since system boot).
int16 xacc          # [mG] X acceleration
int16 yacc          # [mG] Y acceleration
int16 zacc          # [mG] Z acceleration
int16 xgyro         # [mrad/s] Angular speed around X axis
int16 ygyro         # [mrad/s] Angular speed around Y axis
int16 zgyro         # [mrad/s] Angular speed around Z axis
int16 xmag          # [mgauss] X Magnetic field
int16 ymag          # [mgauss] Y Magnetic field
int16 zmag          # [mgauss] Z Magnetic field
int16 temperature   # [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).