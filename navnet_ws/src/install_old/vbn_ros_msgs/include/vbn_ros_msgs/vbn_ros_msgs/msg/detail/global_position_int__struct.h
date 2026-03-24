// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/GlobalPositionInt.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/GlobalPositionInt in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg GLOBAL_POSITION_INT . See https://mavlink.io/en/messages/common.html#GLOBAL_POSITION_INT
 */
typedef struct vbn_ros_msgs__msg__GlobalPositionInt
{
  /// The filtered global position (e.g. fused GPS and accelerometers). The position is in GPS-frame (right-handed, Z-up).
  /// It is designed as scaled integer message since the resolution of float is not sufficient.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// This is the timestamp from the Mavlink msg.
  /// [ms] Timestamp (time since system boot).
  uint32_t time_boot_ms;
  /// Latitude (WGS84, EGM96 ellipsoid)
  int32_t lat;
  /// Longitude (WGS84, EGM96 ellipsoid)
  int32_t lon;
  /// Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude.
  int32_t alt;
  /// Altitude above home
  int32_t relative_alt;
  /// Ground X Speed (Latitude, positive north)
  int16_t vx;
  /// Ground Y Speed (Longitude, positive east)
  int16_t vy;
  /// Ground Z Speed (Altitude, positive down)
  int16_t vz;
  /// Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
  uint16_t hdg;
} vbn_ros_msgs__msg__GlobalPositionInt;

// Struct for a sequence of vbn_ros_msgs__msg__GlobalPositionInt.
typedef struct vbn_ros_msgs__msg__GlobalPositionInt__Sequence
{
  vbn_ros_msgs__msg__GlobalPositionInt * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__GlobalPositionInt__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_H_
