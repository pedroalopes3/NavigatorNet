// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vbn_ros_msgs:msg/TileCoordinatesList.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_H_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_H_

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
// Member 'coordinates'
#include "vbn_ros_msgs/msg/detail/tile_coordinate__struct.h"

/// Struct defined in msg/TileCoordinatesList in the package vbn_ros_msgs.
/**
  * Message used for the list of tiles currently being used.
 */
typedef struct vbn_ros_msgs__msg__TileCoordinatesList
{
  /// Header - this will contain the ROS timestamp
  std_msgs__msg__Header header;
  float mode_elevation;
  vbn_ros_msgs__msg__TileCoordinate__Sequence coordinates;
} vbn_ros_msgs__msg__TileCoordinatesList;

// Struct for a sequence of vbn_ros_msgs__msg__TileCoordinatesList.
typedef struct vbn_ros_msgs__msg__TileCoordinatesList__Sequence
{
  vbn_ros_msgs__msg__TileCoordinatesList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vbn_ros_msgs__msg__TileCoordinatesList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_H_
