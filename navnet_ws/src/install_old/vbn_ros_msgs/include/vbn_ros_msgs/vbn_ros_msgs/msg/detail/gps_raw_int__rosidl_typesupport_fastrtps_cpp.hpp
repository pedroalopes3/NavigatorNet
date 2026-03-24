// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from vbn_ros_msgs:msg/GPSRawInt.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "vbn_ros_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "vbn_ros_msgs/msg/detail/gps_raw_int__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace vbn_ros_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vbn_ros_msgs
cdr_serialize(
  const vbn_ros_msgs::msg::GPSRawInt & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vbn_ros_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vbn_ros_msgs::msg::GPSRawInt & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vbn_ros_msgs
get_serialized_size(
  const vbn_ros_msgs::msg::GPSRawInt & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vbn_ros_msgs
max_serialized_size_GPSRawInt(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vbn_ros_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vbn_ros_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vbn_ros_msgs, msg, GPSRawInt)();

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
