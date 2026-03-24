// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'source_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TileCoordinate in the package vbn_ros_msgs.
/**
  * Message used for a tile coordinate
 */
typedef struct vbn_ros_msgs__msg__TileCoordinate
{
  /// Zoom level
  int32_t z;
  /// X coordinate
  int32_t x;
  /// Y coordinate
  int32_t y;
  /// Similarity score from adaptive search (0.0 if not available)
  double similarity_score;
  /// Source type: "local", "global", etc.
  rosidl_runtime_c__String source_type;
} vbn_ros_msgs__msg__TileCoordinate;

// Struct for a sequence of vbn_ros_msgs__msg__TileCoordinate.
typedef struct vbn_ros_msgs__msg__TileCoordinate__Sequence
{
  vbn_ros_msgs__msg__TileCoordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__TileCoordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_H_
