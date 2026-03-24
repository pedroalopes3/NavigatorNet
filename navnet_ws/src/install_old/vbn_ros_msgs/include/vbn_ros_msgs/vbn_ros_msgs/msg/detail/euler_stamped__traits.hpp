// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/EulerStamped.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/euler_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EulerStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: degrees
  {
    out << "degrees: ";
    rosidl_generator_traits::value_to_yaml(msg.degrees, out);
    out << ", ";
  }

  // member: sequence
  {
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EulerStamped & msg,
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

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: degrees
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "degrees: ";
    rosidl_generator_traits::value_to_yaml(msg.degrees, out);
    out << "\n";
  }

  // member: sequence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EulerStamped & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::EulerStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::EulerStamped & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::EulerStamped>()
{
  return "vbn_ros_msgs::msg::EulerStamped";
}

template<>
inline const char * name<vbn_ros_msgs::msg::EulerStamped>()
{
  return "vbn_ros_msgs/msg/EulerStamped";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::EulerStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::EulerStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vbn_ros_msgs::msg::EulerStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__TRAITS_HPP_
