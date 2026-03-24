// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Attitude & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time_boot_ms
  {
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
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

  // member: rollspeed
  {
    out << "rollspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed, out);
    out << ", ";
  }

  // member: pitchspeed
  {
    out << "pitchspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed, out);
    out << ", ";
  }

  // member: yawspeed
  {
    out << "yawspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Attitude & msg,
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

  // member: time_boot_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
    out << "\n";
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

  // member: rollspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rollspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed, out);
    out << "\n";
  }

  // member: pitchspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitchspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed, out);
    out << "\n";
  }

  // member: yawspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yawspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Attitude & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::Attitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::Attitude & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::Attitude>()
{
  return "vbn_ros_msgs::msg::Attitude";
}

template<>
inline const char * name<vbn_ros_msgs::msg::Attitude>()
{
  return "vbn_ros_msgs/msg/Attitude";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::Attitude>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::Attitude>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::Attitude>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__TRAITS_HPP_
