// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN'.
/**
  * Default unknown value
 */
enum
{
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN = 0
};

/// Constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING'.
/**
  * Aircraft is flying
 */
enum
{
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING = 1
};

/// Constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS'.
/**
  * Autopilot is operating without GNSS
 */
enum
{
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS = 2
};

/// Constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING'.
/**
  * Autopilot is operating without a valid magnetometer
 */
enum
{
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/VisionNavigationAutopilotInfo in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg VISION_NAVIGATION_AUTOPILOT_INFO (Tekever dialect, custom).
 */
typedef struct vbn_ros_msgs__msg__VisionNavigationAutopilotInfo
{
  /// Bunch of data for our VBN system.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Autopilot timestamp (milliseconds since system boot)
  uint32_t time_msec;
  /// Alarms bitmask
  /// Autopilot AHRS alarms
  uint8_t alarms;
  /// Latitude in degrees
  float lat;
  /// Longitude in degrees
  float lng;
  /// Altitude (MSL) in meters
  float alt_msl;
  /// Variance in global position, x
  float pos_variance_x;
  /// Variance in global position, y
  float pos_variance_y;
  /// Variance in global position, z
  float pos_variance_z;
  /// Velocity north in m/s
  float vx;
  /// Velocity east in m/s
  float vy;
  /// Velocity down in m/s
  float vz;
  /// Roll angle in degrees
  float roll;
  /// Pitch angle in degrees
  float pitch;
  /// Yaw angle in degrees
  float yaw;
} vbn_ros_msgs__msg__VisionNavigationAutopilotInfo;

// Struct for a sequence of vbn_ros_msgs__msg__VisionNavigationAutopilotInfo.
typedef struct vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence
{
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_H_
