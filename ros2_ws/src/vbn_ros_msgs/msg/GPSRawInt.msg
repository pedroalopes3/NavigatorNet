### Message associated with the MAVLINK msg GPS_RAW_INT. See https://mavlink.io/en/messages/common.html#GPS_RAW_INT
# Definition adapted from MAVROS (see "https://github.com/mavlink/mavros/blob/ros2/mavros_msgs/msg/GPSRAW.msg")

# The global position, as returned by the Global Positioning System (GPS). 
# This is NOT the global position estimate of the system, but rather a RAW sensor value.

# Header - this will contain the ROS timestamp
std_msgs/Header header

# This is the timestamp from the Mavlink msg.
uint64 time_usec    # [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.

## GPS_FIX_TYPE enum
uint8 GPS_FIX_TYPE_NO_GPS     = 0    # No GPS connected
uint8 GPS_FIX_TYPE_NO_FIX     = 1    # No position information, GPS is connected
uint8 GPS_FIX_TYPE_2D_FIX     = 2    # 2D position
uint8 GPS_FIX_TYPE_3D_FIX     = 3    # 3D position
uint8 GPS_FIX_TYPE_DGPS       = 4    # DGPS/SBAS aided 3D position
uint8 GPS_FIX_TYPE_RTK_FLOAT  = 5    # RTK float, 3D position
uint8 GPS_FIX_TYPE_RTK_FIXED  = 6    # RTK Fixed, 3D position
uint8 GPS_FIX_TYPE_STATIC     = 7    # Static fixed, typically used for base stations
uint8 GPS_FIX_TYPE_PPP        = 8    # PPP, 3D position
uint8 fix_type      # [GPS_FIX_TYPE] GPS fix type

int32 lat           # [degE7] Latitude (WGS84, EGM96 ellipsoid)
int32 lon           # [degE7] Longitude (WGS84, EGM96 ellipsoid)
int32 alt           # [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
uint16 eph          # GPS HDOP horizontal dilution of position (unitless * 100). If unknown, set to: UINT16_MAX
uint16 epv          # GPS VDOP vertical dilution of position (unitless * 100). If unknown, set to: UINT16_MAX
uint16 vel          # [cm/s] GPS ground speed. If unknown, set to: UINT16_MAX
uint16 cog          # [cdeg] Course over ground (NOT heading, but direction of movement), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
uint8 satellites_visible # Number of satellites visible. If unknown, set to 255

# -*- only available with MAVLink v2.0 and GPS_RAW_INT messages -*-
int32 alt_ellipsoid # [mm] Altitude (above WGS84, EGM96 ellipsoid). Positive for up.
uint32 h_acc        # [mm] Position uncertainty. Positive for up.
uint32 v_acc        # [mm] Altitude uncertainty. Positive for up.
uint32 vel_acc      # [mm] Speed uncertainty. Positive for up.
uint32 hdg_acc     # [degE5] Heading / track uncertainty
uint16 yaw          # [cdeg] Yaw in earth frame from north.