### Message associated with the MAVLINK msg RAW_IMU. See https://mavlink.io/en/messages/common.html#RAW_IMU

# The RAW IMU readings for a 9DOF sensor, which is identified by the id (default IMU1).
# This message should always contain the true raw values without any scaling to allow data capture and system debugging.


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint64 time_usec    # [us] Timestamp (UNIX Epoch time or time since system boot).
int16 xacc          # X acceleration (raw)
int16 yacc          # Y acceleration (raw)
int16 zacc          # Z acceleration (raw)
int16 xgyro         # Angular speed around X axis (raw)
int16 ygyro         # Angular speed around Y axis (raw)
int16 zgyro         # Angular speed around Z axis (raw)
int16 xmag          # X Magnetic field (raw)
int16 ymag          # Y Magnetic field (raw)
int16 zmag          # Z Magnetic field (raw)
uint8 id            # IMU Id. Ids are numbered from 0 and map to IMUs numbered from 1.
int16 temperature   # [cdegC] Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).