// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/RawIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_H_

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

/// Struct defined in msg/RawIMU in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg RAW_IMU. See https://mavlink.io/en/messages/common.html#RAW_IMU
 */
typedef struct vbn_ros_msgs__msg__RawIMU
{
  /// The RAW IMU readings for a 9DOF sensor, which is identified by the id (default IMU1).
  /// This message should always contain the true raw values without any scaling to allow data capture and system debugging.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Timestamp (UNIX Epoch time or time since system boot).
  uint64_t time_usec;
  /// X acceleration (raw)
  int16_t xacc;
  /// Y acceleration (raw)
  int16_t yacc;
  /// Z acceleration (raw)
  int16_t zacc;
  /// Angular speed around X axis (raw)
  int16_t xgyro;
  /// Angular speed around Y axis (raw)
  int16_t ygyro;
  /// Angular speed around Z axis (raw)
  int16_t zgyro;
  /// X Magnetic field (raw)
  int16_t xmag;
  /// Y Magnetic field (raw)
  int16_t ymag;
  /// Z Magnetic field (raw)
  int16_t zmag;
  /// IMU Id. Ids are numbered from 0 and map to IMUs numbered from 1.
  uint8_t id;
  /// Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C).
  int16_t temperature;
} vbn_ros_msgs__msg__RawIMU;

// Struct for a sequence of vbn_ros_msgs__msg__RawIMU.
typedef struct vbn_ros_msgs__msg__RawIMU__Sequence
{
  vbn_ros_msgs__msg__RawIMU * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__RawIMU__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_H_
