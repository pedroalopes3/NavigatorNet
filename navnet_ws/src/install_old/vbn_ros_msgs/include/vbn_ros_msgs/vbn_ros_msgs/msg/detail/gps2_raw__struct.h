// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/GPS2Raw.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GPS_FIX_TYPE_NO_GPS'.
/**
  * GPS_FIX_TYPE enum
  * No GPS connected
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_NO_GPS = 0
};

/// Constant 'GPS_FIX_TYPE_NO_FIX'.
/**
  * No position information, GPS is connected
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_NO_FIX = 1
};

/// Constant 'GPS_FIX_TYPE_2D_FIX'.
/**
  * 2D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_2D_FIX = 2
};

/// Constant 'GPS_FIX_TYPE_3D_FIX'.
/**
  * 3D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_3D_FIX = 3
};

/// Constant 'GPS_FIX_TYPE_DGPS'.
/**
  * DGPS/SBAS aided 3D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_DGPS = 4
};

/// Constant 'GPS_FIX_TYPE_RTK_FLOAT'.
/**
  * RTK float, 3D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_RTK_FLOAT = 5
};

/// Constant 'GPS_FIX_TYPE_RTK_FIXED'.
/**
  * RTK Fixed, 3D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_RTK_FIXED = 6
};

/// Constant 'GPS_FIX_TYPE_STATIC'.
/**
  * Static fixed, typically used for base stations
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_STATIC = 7
};

/// Constant 'GPS_FIX_TYPE_PPP'.
/**
  * PPP, 3D position
 */
enum
{
  vbn_ros_msgs__msg__GPS2Raw__GPS_FIX_TYPE_PPP = 8
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/GPS2Raw in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg GPS2_RAW . See https://mavlink.io/en/messages/common.html#GPS2_RAW 
  * Definition adapted from MAVROS (see "https://github.com/mavlink/mavros/blob/ros2/mavros_msgs/msg/GPSRAW.msg")
 */
typedef struct vbn_ros_msgs__msg__GPS2Raw
{
  /// The global position, as returned by the secondary Global Positioning System (GPS).
  /// This is NOT the global position estimate of the system, but rather a RAW sensor value.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// This is the timestamp from the Mavlink msg.
  /// [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
  uint64_t time_usec;
  /// GPS fix type
  uint8_t fix_type;
  /// Latitude (WGS84, EGM96 ellipsoid)
  int32_t lat;
  /// Longitude (WGS84, EGM96 ellipsoid)
  int32_t lon;
  /// Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
  int32_t alt;
  /// GPS HDOP horizontal dilution of position (unitless * 100). If unknown, set to: UINT16_MAX
  uint16_t eph;
  /// GPS VDOP vertical dilution of position (unitless * 100). If unknown, set to: UINT16_MAX
  uint16_t epv;
  /// GPS ground speed. If unknown, set to: UINT16_MAX
  uint16_t vel;
  /// Course over ground (NOT heading, but direction of movement), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
  uint16_t cog;
  /// Number of satellites visible. If unknown, set to 255
  uint8_t satellites_visible;
  /// Number of DGPS satellites
  uint8_t dgps_numch;
  /// Age of DGPS info.
  uint32_t dgps_age;
  /// Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use UINT16_MAX if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north.
  uint16_t yaw;
  /// Altitude (above WGS84, EGM96 ellipsoid). Positive for up.
  int32_t alt_ellipsoid;
  /// Position uncertainty. Positive for up.
  uint32_t h_acc;
  /// Altitude uncertainty. Positive for up.
  uint32_t v_acc;
  /// Speed uncertainty. Positive for up.
  uint32_t vel_acc;
  /// Heading / track uncertainty
  uint32_t hdg_acc;
} vbn_ros_msgs__msg__GPS2Raw;

// Struct for a sequence of vbn_ros_msgs__msg__GPS2Raw.
typedef struct vbn_ros_msgs__msg__GPS2Raw__Sequence
{
  vbn_ros_msgs__msg__GPS2Raw * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__GPS2Raw__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__STRUCT_H_
