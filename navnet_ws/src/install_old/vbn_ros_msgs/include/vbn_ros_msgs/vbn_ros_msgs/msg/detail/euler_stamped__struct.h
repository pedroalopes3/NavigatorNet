// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/EulerStamped.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__STRUCT_H_

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
// Member 'sequence'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/EulerStamped in the package vbn_ros_msgs.
/**
  * Custom message to store the attitude
 */
typedef struct vbn_ros_msgs__msg__EulerStamped
{
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Roll angle (-pi..+pi)
  float roll;
  /// Pitch angle (-pi..+pi)
  float pitch;
  /// Yaw angle (-pi..+pi)
  float yaw;
  /// Boolean defining whether the data is in degrees
  bool degrees;
  /// Euler angle sequence. Uppercase for extrinsic and lowercase for intrinsic.
  rosidl_runtime_c__String sequence;
} vbn_ros_msgs__msg__EulerStamped;

// Struct for a sequence of vbn_ros_msgs__msg__EulerStamped.
typedef struct vbn_ros_msgs__msg__EulerStamped__Sequence
{
  vbn_ros_msgs__msg__EulerStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__EulerStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__STRUCT_H_
