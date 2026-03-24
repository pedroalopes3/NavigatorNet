// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/AHRS.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_H_

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

/// Struct defined in msg/AHRS in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg AHRS. See https://mavlink.io/en/messages/ardupilotmega.html#AHRS
 */
typedef struct vbn_ros_msgs__msg__AHRS
{
  /// Status of DCM attitude estimator.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// X gyro drift estimate.
  float omega_ix;
  /// Y gyro drift estimate.
  float omega_iy;
  /// Z gyro drift estimate.
  float omega_iz;
  /// Average accel_weight.
  float accel_weight;
  /// Average renormalisation value.
  float renorm_val;
  /// Average error_roll_pitch value.
  float error_rp;
  /// Average error_yaw value.
  float error_yaw;
} vbn_ros_msgs__msg__AHRS;

// Struct for a sequence of vbn_ros_msgs__msg__AHRS.
typedef struct vbn_ros_msgs__msg__AHRS__Sequence
{
  vbn_ros_msgs__msg__AHRS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__AHRS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_H_
