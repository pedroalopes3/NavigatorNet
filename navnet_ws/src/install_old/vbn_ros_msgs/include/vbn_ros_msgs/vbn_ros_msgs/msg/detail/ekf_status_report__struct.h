// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/EKFStatusReport.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'EKF_ATTITUDE'.
/**
  * Set if EKF's attitude estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_ATTITUDE = 1
};

/// Constant 'EKF_VELOCITY_HORIZ'.
/**
  * Set if EKF's horizontal velocity estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_VELOCITY_HORIZ = 2
};

/// Constant 'EKF_VELOCITY_VERT'.
/**
  * Set if EKF's vertical velocity estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_VELOCITY_VERT = 4
};

/// Constant 'EKF_POS_HORIZ_REL'.
/**
  * Set if EKF's horizontal position (relative) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_POS_HORIZ_REL = 8
};

/// Constant 'EKF_POS_HORIZ_ABS'.
/**
  * Set if EKF's horizontal position (absolute) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_POS_HORIZ_ABS = 16
};

/// Constant 'EKF_POS_VERT_ABS'.
/**
  * Set if EKF's vertical position (absolute) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_POS_VERT_ABS = 32
};

/// Constant 'EKF_POS_VERT_AGL'.
/**
  * Set if EKF's vertical position (above ground) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_POS_VERT_AGL = 64
};

/// Constant 'EKF_CONST_POS_MODE'.
/**
  * EKF is in constant position mode and does not know it's absolute or relative position.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_CONST_POS_MODE = 128
};

/// Constant 'EKF_PRED_POS_HORIZ_REL'.
/**
  * Set if EKF's predicted horizontal position (relative) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_PRED_POS_HORIZ_REL = 256
};

/// Constant 'EKF_PRED_POS_HORIZ_ABS'.
/**
  * Set if EKF's predicted horizontal position (absolute) estimate is good.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_PRED_POS_HORIZ_ABS = 512
};

/// Constant 'EKF_UNINITIALIZED'.
/**
  * Set if EKF has never been healthy.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_UNINITIALIZED = 1024
};

/// Constant 'EKF_GPS_GLITCHING'.
/**
  * Set if EKF believes the GPS input data is faulty.
 */
enum
{
  vbn_ros_msgs__msg__EKFStatusReport__EKF_GPS_GLITCHING = 32768
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/EKFStatusReport in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg EKF_STATUS_REPORT. See https://mavlink.io/en/messages/ardupilotmega.html#EKF_STATUS_REPORT
 */
typedef struct vbn_ros_msgs__msg__EKFStatusReport
{
  /// EKF Status message including flags and variances.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// EKF_STATUS_FLAGS typemask
  uint16_t flags;
  /// Velocity variance.
  float velocity_variance;
  /// Horizontal Position variance.
  float pos_horiz_variance;
  /// Vertical Position variance.
  float pos_vert_variance;
  /// Compass variance.
  float compass_variance;
  /// Terrain Altitude variance.
  float terrain_alt_variance;
  /// Airspeed variance.
  float airspeed_variance;
} vbn_ros_msgs__msg__EKFStatusReport;

// Struct for a sequence of vbn_ros_msgs__msg__EKFStatusReport.
typedef struct vbn_ros_msgs__msg__EKFStatusReport__Sequence
{
  vbn_ros_msgs__msg__EKFStatusReport * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__EKFStatusReport__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_H_
