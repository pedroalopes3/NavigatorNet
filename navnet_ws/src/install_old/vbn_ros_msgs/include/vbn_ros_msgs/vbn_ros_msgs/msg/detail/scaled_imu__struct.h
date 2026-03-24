// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/ScaledIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__STRUCT_H_

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

/// Struct defined in msg/ScaledIMU in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg SCALED_IMU. See https://mavlink.io/en/messages/common.html#SCALED_IMU
 */
typedef struct vbn_ros_msgs__msg__ScaledIMU
{
  /// The RAW IMU readings for 9DOF sensor setup. This message should contain the scaled values to the described units
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Timestamp (time since system boot).
  uint64_t time_boot_ms;
  /// X acceleration
  int16_t xacc;
  /// Y acceleration
  int16_t yacc;
  /// Z acceleration
  int16_t zacc;
  /// Angular speed around X axis
  int16_t xgyro;
  /// Angular speed around Y axis
  int16_t ygyro;
  /// Angular speed around Z axis
  int16_t zgyro;
  /// X Magnetic field
  int16_t xmag;
  /// Y Magnetic field
  int16_t ymag;
  /// Z Magnetic field
  int16_t zmag;
  /// Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).
  int16_t temperature;
} vbn_ros_msgs__msg__ScaledIMU;

// Struct for a sequence of vbn_ros_msgs__msg__ScaledIMU.
typedef struct vbn_ros_msgs__msg__ScaledIMU__Sequence
{
  vbn_ros_msgs__msg__ScaledIMU * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__ScaledIMU__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__STRUCT_H_
