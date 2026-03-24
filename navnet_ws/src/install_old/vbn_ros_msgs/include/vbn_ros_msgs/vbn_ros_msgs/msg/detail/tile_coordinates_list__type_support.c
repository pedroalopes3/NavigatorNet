// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vbn_ros_msgs:msg/TileCoordinatesList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vbn_ros_msgs/msg/detail/tile_coordinates_list__rosidl_typesupport_introspection_c.h"
#include "vbn_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vbn_ros_msgs/msg/detail/tile_coordinates_list__functions.h"
#include "vbn_ros_msgs/msg/detail/tile_coordinates_list__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `coordinates`
#include "vbn_ros_msgs/msg/tile_coordinate.h"
// Member `coordinates`
#include "vbn_ros_msgs/msg/detail/tile_coordinate__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vbn_ros_msgs__msg__TileCoordinatesList__init(message_memory);
}

void vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_fini_function(void * message_memory)
{
  vbn_ros_msgs__msg__TileCoordinatesList__fini(message_memory);
}

size_t vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__size_function__TileCoordinatesList__coordinates(
  const void * untyped_member)
{
  const vbn_ros_msgs__msg__TileCoordinate__Sequence * member =
    (const vbn_ros_msgs__msg__TileCoordinate__Sequence *)(untyped_member);
  return member->size;
}

const void * vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_const_function__TileCoordinatesList__coordinates(
  const void * untyped_member, size_t index)
{
  const vbn_ros_msgs__msg__TileCoordinate__Sequence * member =
    (const vbn_ros_msgs__msg__TileCoordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_function__TileCoordinatesList__coordinates(
  void * untyped_member, size_t index)
{
  vbn_ros_msgs__msg__TileCoordinate__Sequence * member =
    (vbn_ros_msgs__msg__TileCoordinate__Sequence *)(untyped_member);
  return &member->data[index];
}

void vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__fetch_function__TileCoordinatesList__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vbn_ros_msgs__msg__TileCoordinate * item =
    ((const vbn_ros_msgs__msg__TileCoordinate *)
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_const_function__TileCoordinatesList__coordinates(untyped_member, index));
  vbn_ros_msgs__msg__TileCoordinate * value =
    (vbn_ros_msgs__msg__TileCoordinate *)(untyped_value);
  *value = *item;
}

void vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__assign_function__TileCoordinatesList__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vbn_ros_msgs__msg__TileCoordinate * item =
    ((vbn_ros_msgs__msg__TileCoordinate *)
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_function__TileCoordinatesList__coordinates(untyped_member, index));
  const vbn_ros_msgs__msg__TileCoordinate * value =
    (const vbn_ros_msgs__msg__TileCoordinate *)(untyped_value);
  *item = *value;
}

bool vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__resize_function__TileCoordinatesList__coordinates(
  void * untyped_member, size_t size)
{
  vbn_ros_msgs__msg__TileCoordinate__Sequence * member =
    (vbn_ros_msgs__msg__TileCoordinate__Sequence *)(untyped_member);
  vbn_ros_msgs__msg__TileCoordinate__Sequence__fini(member);
  return vbn_ros_msgs__msg__TileCoordinate__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinatesList, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode_elevation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinatesList, mode_elevation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__TileCoordinatesList, coordinates),  // bytes offset in struct
    NULL,  // default value
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__size_function__TileCoordinatesList__coordinates,  // size() function pointer
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_const_function__TileCoordinatesList__coordinates,  // get_const(index) function pointer
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__get_function__TileCoordinatesList__coordinates,  // get(index) function pointer
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__fetch_function__TileCoordinatesList__coordinates,  // fetch(index, &value) function pointer
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__assign_function__TileCoordinatesList__coordinates,  // assign(index, value) function pointer
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__resize_function__TileCoordinatesList__coordinates  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_members = {
  "vbn_ros_msgs__msg",  // message namespace
  "TileCoordinatesList",  // message name
  3,  // number of fields
  sizeof(vbn_ros_msgs__msg__TileCoordinatesList),
  vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_member_array,  // message members
  vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_init_function,  // function to initialize message memory (memory has to be allocated)
  vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_type_support_handle = {
  0,
  &vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vbn_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vbn_ros_msgs, msg, TileCoordinatesList)() {
  vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vbn_ros_msgs, msg, TileCoordinate)();
  if (!vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_type_support_handle.typesupport_identifier) {
    vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vbn_ros_msgs__msg__TileCoordinatesList__rosidl_typesupport_introspection_c__TileCoordinatesList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
