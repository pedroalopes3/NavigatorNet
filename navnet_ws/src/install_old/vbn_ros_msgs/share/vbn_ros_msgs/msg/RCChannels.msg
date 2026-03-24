### Message associated with the MAVLINK msg RC_CHANNELS. See https://mavlink.io/en/messages/common.html#RC_CHANNELS

# The PPM values of the RC channels received. The standard PPM modulation is as follows: 1000 microseconds: 0%, 2000 microseconds: 100%. 
# A value of UINT16_MAX implies the channel is unused. Individual receivers/transmitters might violate this specification.


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint32 time_boot_ms # [ms] Timestamp (time since system boot).
uint8 chancount    # Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available.
uint16 chan1_raw
uint16 chan2_raw
uint16 chan3_raw
uint16 chan4_raw
uint16 chan5_raw
uint16 chan6_raw
uint16 chan7_raw
uint16 chan8_raw
uint16 chan9_raw
uint16 chan10_raw
uint16 chan11_raw
uint16 chan12_raw
uint16 chan13_raw
uint16 chan14_raw
uint16 chan15_raw
uint16 chan16_raw
uint16 chan17_raw
uint16 chan18_raw
uint8 rssi         # Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown.