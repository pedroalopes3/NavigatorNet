// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__STRUCT_H_

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

/// Struct defined in msg/Attitude in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg ATTITUDE. See https://mavlink.io/en/messages/common.html#ATTITUDE
 */
typedef struct vbn_ros_msgs__msg__Attitude
{
  /// The attitude in the aeronautical frame (right-handed, Z-down, Y-right, X-front, ZYX, intrinsic).
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Timestamp (time since system boot).
  uint32_t time_boot_ms;
  /// Roll angle (-pi..+pi)
  float roll;
  /// Pitch angle (-pi..+pi)
  float pitch;
  /// Yaw angle (-pi..+pi)
  float yaw;
  /// Roll angular speed
  float rollspeed;
  /// Pitch angular speed
  float pitchspeed;
  /// Yaw angular speed
  float yawspeed;
} vbn_ros_msgs__msg__Attitude;

// Struct for a sequence of vbn_ros_msgs__msg__Attitude.
typedef struct vbn_ros_msgs__msg__Attitude__Sequence
{
  vbn_ros_msgs__msg__Attitude * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__Attitude__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__STRUCT_H_
