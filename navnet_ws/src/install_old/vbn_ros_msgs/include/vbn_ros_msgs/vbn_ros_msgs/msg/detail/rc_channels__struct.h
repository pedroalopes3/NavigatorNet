// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_H_

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

/// Struct defined in msg/RCChannels in the package vbn_ros_msgs.
/**
  * Message associated with the MAVLINK msg RC_CHANNELS. See https://mavlink.io/en/messages/common.html#RC_CHANNELS
 */
typedef struct vbn_ros_msgs__msg__RCChannels
{
  /// The PPM values of the RC channels received. The standard PPM modulation is as follows: 1000 microseconds: 0%, 2000 microseconds: 100%.
  /// A value of UINT16_MAX implies the channel is unused. Individual receivers/transmitters might violate this specification.
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  /// Timestamp (time since system boot).
  uint32_t time_boot_ms;
  /// Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available.
  uint8_t chancount;
  uint16_t chan1_raw;
  uint16_t chan2_raw;
  uint16_t chan3_raw;
  uint16_t chan4_raw;
  uint16_t chan5_raw;
  uint16_t chan6_raw;
  uint16_t chan7_raw;
  uint16_t chan8_raw;
  uint16_t chan9_raw;
  uint16_t chan10_raw;
  uint16_t chan11_raw;
  uint16_t chan12_raw;
  uint16_t chan13_raw;
  uint16_t chan14_raw;
  uint16_t chan15_raw;
  uint16_t chan16_raw;
  uint16_t chan17_raw;
  uint16_t chan18_raw;
  /// Receive signal strength indicator in device-dependent units/scale. Values:, UINT8_MAX: invalid/unknown.
  uint8_t rssi;
} vbn_ros_msgs__msg__RCChannels;

// Struct for a sequence of vbn_ros_msgs__msg__RCChannels.
typedef struct vbn_ros_msgs__msg__RCChannels__Sequence
{
  vbn_ros_msgs__msg__RCChannels * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__RCChannels__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_H_
