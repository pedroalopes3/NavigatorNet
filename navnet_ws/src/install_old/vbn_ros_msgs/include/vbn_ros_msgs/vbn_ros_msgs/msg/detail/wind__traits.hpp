// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/Wind.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__WIND__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__WIND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/wind__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Wind & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: speed_z
  {
    out << "speed_z: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Wind & msg,
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

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: speed_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_z: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Wind & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::Wind & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::Wind & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::Wind>()
{
  return "vbn_ros_msgs::msg::Wind";
}

template<>
inline const char * name<vbn_ros_msgs::msg::Wind>()
{
  return "vbn_ros_msgs/msg/Wind";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::Wind>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::Wind>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::Wind>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__WIND__TRAITS_HPP_
