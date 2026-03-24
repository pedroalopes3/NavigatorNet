// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/Wind.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__WIND__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__WIND__STRUCT_H_

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

/// Struct defined in msg/Wind in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg WIND. See https://mavlink.io/en/messages/ardupilotmega.html#WIND
 */
typedef struct vbn_ros_msgs__msg__Wind
{
  /// Wind estimation.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Wind direction (that wind is coming from).
  float direction;
  /// Wind speed in ground plane.
  float speed;
  /// Vertical wind speed.
  float speed_z;
} vbn_ros_msgs__msg__Wind;

// Struct for a sequence of vbn_ros_msgs__msg__Wind.
typedef struct vbn_ros_msgs__msg__Wind__Sequence
{
  vbn_ros_msgs__msg__Wind * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__Wind__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__WIND__STRUCT_H_
