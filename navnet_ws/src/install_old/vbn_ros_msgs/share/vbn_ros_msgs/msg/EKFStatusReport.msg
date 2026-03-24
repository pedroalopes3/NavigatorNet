### Message associated with the MAVLINK msg EKF_STATUS_REPORT. See https://mavlink.io/en/messages/ardupilotmega.html#EKF_STATUS_REPORT

# EKF Status message including flags and variances.

# Header - this will contain the ROS timestamp
std_msgs/Header header

# EKF_STATUS_FLAGS typemask
uint16 flags
uint16 EKF_ATTITUDE              = 1         # Set if EKF's attitude estimate is good.
uint16 EKF_VELOCITY_HORIZ        = 2         # Set if EKF's horizontal velocity estimate is good.
uint16 EKF_VELOCITY_VERT         = 4         # Set if EKF's vertical velocity estimate is good.
uint16 EKF_POS_HORIZ_REL         = 8         # Set if EKF's horizontal position (relative) estimate is good.
uint16 EKF_POS_HORIZ_ABS         = 16        # Set if EKF's horizontal position (absolute) estimate is good.
uint16 EKF_POS_VERT_ABS          = 32        # Set if EKF's vertical position (absolute) estimate is good.
uint16 EKF_POS_VERT_AGL          = 64        # Set if EKF's vertical position (above ground) estimate is good.
uint16 EKF_CONST_POS_MODE        = 128       # EKF is in constant position mode and does not know it's absolute or relative position.
uint16 EKF_PRED_POS_HORIZ_REL    = 256       # Set if EKF's predicted horizontal position (relative) estimate is good.
uint16 EKF_PRED_POS_HORIZ_ABS    = 512       # Set if EKF's predicted horizontal position (absolute) estimate is good.
uint16 EKF_UNINITIALIZED         = 1024      # Set if EKF has never been healthy.
uint16 EKF_GPS_GLITCHING         = 32768     # Set if EKF believes the GPS input data is faulty.

float32 velocity_variance     # Velocity variance.
float32 pos_horiz_variance    # Horizontal Position variance.
float32 pos_vert_variance     # Vertical Position variance.
float32 compass_variance      # Compass variance.
float32 terrain_alt_variance  # Terrain Altitude variance.
float32 airspeed_variance     # Airspeed variance.