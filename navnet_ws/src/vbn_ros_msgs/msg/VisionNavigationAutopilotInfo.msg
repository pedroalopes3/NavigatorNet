### Message associated with the MAVLINK msg VISION_NAVIGATION_AUTOPILOT_INFO (Tekever dialect, custom).

# Bunch of data for our VBN system.


# Header - this will contain the ROS timestamp
std_msgs/Header header

uint32 time_msec        # Autopilot timestamp (milliseconds since system boot)

# Alarms bitmask
uint8 alarms           # Autopilot AHRS alarms
uint8 VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN = 0    # Default unknown value
uint8 VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING = 1  # Aircraft is flying
uint8 VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS = 2      # Autopilot is operating without GNSS
uint8 VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING = 4   # Autopilot is operating without a valid magnetometer

float32 lat               # Latitude in degrees
float32 lng               # Longitude in degrees
float32 alt_msl           # Altitude (MSL) in meters
float32 pos_variance_x    # Variance in global position, x
float32 pos_variance_y    # Variance in global position, y
float32 pos_variance_z    # Variance in global position, z
float32 vx                # Velocity north in m/s
float32 vy                # Velocity east in m/s
float32 vz                # Velocity down in m/s
float32 roll              # Roll angle in degrees
float32 pitch             # Pitch angle in degrees
float32 yaw               # Yaw angle in degrees