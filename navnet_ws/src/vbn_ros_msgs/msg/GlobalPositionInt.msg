### Message associated with the MAVLINK msg GLOBAL_POSITION_INT . See https://mavlink.io/en/messages/common.html#GLOBAL_POSITION_INT

# The filtered global position (e.g. fused GPS and accelerometers). The position is in GPS-frame (right-handed, Z-up). 
# It is designed as scaled integer message since the resolution of float is not sufficient.

# Header - this will contain the ROS timestamp
std_msgs/Header header

# This is the timestamp from the Mavlink msg.
uint32 time_boot_ms    # [ms] Timestamp (time since system boot).

int32 lat           # [degE7] Latitude (WGS84, EGM96 ellipsoid)
int32 lon           # [degE7] Longitude (WGS84, EGM96 ellipsoid)
int32 alt           # [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
int32 relative_alt  # [mm] Altitude above home
int16 vx            # [cm/s] Ground X Speed (Latitude, positive north)
int16 vy            # [cm/s] Ground Y Speed (Longitude, positive east)
int16 vz            # [cm/s] Ground Z Speed (Altitude, positive down)
uint16 hdg          # [cdeg] Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX