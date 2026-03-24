// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/AOASSA.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AOASSA__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AOASSA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/aoassa__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AOASSA & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time_usec
  {
    out << "time_usec: ";
    rosidl_generator_traits::value_to_yaml(msg.time_usec, out);
    out << ", ";
  }

  // member: aoa
  {
    out << "aoa: ";
    rosidl_generator_traits::value_to_yaml(msg.aoa, out);
    out << ", ";
  }

  // member: ssa
  {
    out << "ssa: ";
    rosidl_generator_traits::value_to_yaml(msg.ssa, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AOASSA & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: time_usec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_usec: ";
    rosidl_generator_traits::value_to_yaml(msg.time_usec, out);
    out << "\n";
  }

  // member: aoa
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aoa: ";
    rosidl_generator_traits::value_to_yaml(msg.aoa, out);
    out << "\n";
  }

  // member: ssa
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ssa: ";
    rosidl_generator_traits::value_to_yaml(msg.ssa, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AOASSA & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vbn_ros_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vbn_ros_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vbn_ros_msgs::msg::AOASSA & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::AOASSA & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::AOASSA>()
{
  return "vbn_ros_msgs::msg::AOASSA";
}

template<>
inline const char * name<vbn_ros_msgs::msg::AOASSA>()
{
  return "vbn_ros_msgs/msg/AOASSA";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::AOASSA>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::AOASSA>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::AOASSA>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AOASSA__TRAITS_HPP_
