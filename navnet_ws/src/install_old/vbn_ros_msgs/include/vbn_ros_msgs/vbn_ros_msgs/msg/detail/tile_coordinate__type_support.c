// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vbn_ros_msgs/msg/detail/tile_coordinate__rosidl_typesupport_introspection_c.h"
#include "vbn_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vbn_ros_msgs/msg/detail/tile_coordinate__functions.h"
#include "vbn_ros_msgs/msg/detail/tile_coordinate__struct.h"


// Include directives for member types
// Member `source_type`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vbn_ros_msgs__msg__TileCoordinate__init(message_memory);
}

void vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_fini_function(void * message_memory)
{
  vbn_ros_msgs__msg__TileCoordinate__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_member_array[5] = {
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinate, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinate, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinate, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "similarity_score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinate, similarity_score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinate, source_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_members = {
  "vbn_ros_msgs__msg",  // message namespace
  "TileCoordinate",  // message name
  5,  // number of fields
  sizeof(vbn_ros_msgs__msg__TileCoordinate),
  vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_member_array,  // message members
  vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_init_function,  // function to initialize message memory (memory has to be allocated)
  vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_type_support_handle = {
  0,
  &vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vbn_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vbn_ros_msgs, msg, TileCoordinate)() {
  if (!vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_type_support_handle.typesupport_identifier) {
    vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vbn_ros_msgs__msg__TileCoordinate__rosidl_typesupport_introspection_c__TileCoordinate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
