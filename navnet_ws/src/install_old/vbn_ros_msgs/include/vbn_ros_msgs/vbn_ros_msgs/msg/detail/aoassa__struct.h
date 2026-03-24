// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/AOASSA.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_H_

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

/// Struct defined in msg/AOASSA in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg AOA_SSA. See https://mavlink.io/en/messages/ardupilotmega.html#AOA_SSA
 */
typedef struct vbn_ros_msgs__msg__AOASSA
{
  /// Angle of Attack and Side Slip Angle.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Timestamp (since boot or Unix epoch).
  uint64_t time_usec;
  /// Angle of Attack.
  float aoa;
  /// Side Slip Angle.
  float ssa;
} vbn_ros_msgs__msg__AOASSA;

// Struct for a sequence of vbn_ros_msgs__msg__AOASSA.
typedef struct vbn_ros_msgs__msg__AOASSA__Sequence
{
  vbn_ros_msgs__msg__AOASSA * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__AOASSA__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_H_
