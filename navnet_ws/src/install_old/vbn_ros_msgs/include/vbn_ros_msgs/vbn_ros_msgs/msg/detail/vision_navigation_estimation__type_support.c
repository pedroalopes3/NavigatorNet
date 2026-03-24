// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vbn_ros_msgs:msg/VisionNavigationEstimation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vbn_ros_msgs/msg/detail/vision_navigation_estimation__rosidl_typesupport_introspection_c.h"
#include "vbn_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vbn_ros_msgs/msg/detail/vision_navigation_estimation__functions.h"
#include "vbn_ros_msgs/msg/detail/vision_navigation_estimation__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geographic_msgs/msg/geo_point.h"
// Member `position`
#include "geographic_msgs/msg/detail/geo_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vbn_ros_msgs__msg__VisionNavigationEstimation__init(message_memory);
}

void vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_fini_function(void * message_memory)
{
  vbn_ros_msgs__msg__VisionNavigationEstimation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__VisionNavigationEstimation, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__VisionNavigationEstimation, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flags",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__VisionNavigationEstimation, flags),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs__msg__VisionNavigationEstimation, pos_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_members = {
  "vbn_ros_msgs__msg",  // message namespace
  "VisionNavigationEstimation",  // message name
  4,  // number of fields
  sizeof(vbn_ros_msgs__msg__VisionNavigationEstimation),
  vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_member_array,  // message members
  vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_init_function,  // function to initialize message memory (memory has to be allocated)
  vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_type_support_handle = {
  0,
  &vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vbn_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vbn_ros_msgs, msg, VisionNavigationEstimation)() {
  vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geographic_msgs, msg, GeoPoint)();
  if (!vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_type_support_handle.typesupport_identifier) {
    vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vbn_ros_msgs__msg__VisionNavigationEstimation__rosidl_typesupport_introspection_c__VisionNavigationEstimation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
