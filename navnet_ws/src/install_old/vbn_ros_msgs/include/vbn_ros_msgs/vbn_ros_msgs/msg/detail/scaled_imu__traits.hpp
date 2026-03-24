// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/ScaledIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/scaled_imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ScaledIMU & msg,
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

  // member: xacc
  {
    out << "xacc: ";
    rosidl_generator_traits::value_to_yaml(msg.xacc, out);
    out << ", ";
  }

  // member: yacc
  {
    out << "yacc: ";
    rosidl_generator_traits::value_to_yaml(msg.yacc, out);
    out << ", ";
  }

  // member: zacc
  {
    out << "zacc: ";
    rosidl_generator_traits::value_to_yaml(msg.zacc, out);
    out << ", ";
  }

  // member: xgyro
  {
    out << "xgyro: ";
    rosidl_generator_traits::value_to_yaml(msg.xgyro, out);
    out << ", ";
  }

  // member: ygyro
  {
    out << "ygyro: ";
    rosidl_generator_traits::value_to_yaml(msg.ygyro, out);
    out << ", ";
  }

  // member: zgyro
  {
    out << "zgyro: ";
    rosidl_generator_traits::value_to_yaml(msg.zgyro, out);
    out << ", ";
  }

  // member: xmag
  {
    out << "xmag: ";
    rosidl_generator_traits::value_to_yaml(msg.xmag, out);
    out << ", ";
  }

  // member: ymag
  {
    out << "ymag: ";
    rosidl_generator_traits::value_to_yaml(msg.ymag, out);
    out << ", ";
  }

  // member: zmag
  {
    out << "zmag: ";
    rosidl_generator_traits::value_to_yaml(msg.zmag, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScaledIMU & msg,
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

  // member: xacc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xacc: ";
    rosidl_generator_traits::value_to_yaml(msg.xacc, out);
    out << "\n";
  }

  // member: yacc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yacc: ";
    rosidl_generator_traits::value_to_yaml(msg.yacc, out);
    out << "\n";
  }

  // member: zacc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zacc: ";
    rosidl_generator_traits::value_to_yaml(msg.zacc, out);
    out << "\n";
  }

  // member: xgyro
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xgyro: ";
    rosidl_generator_traits::value_to_yaml(msg.xgyro, out);
    out << "\n";
  }

  // member: ygyro
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ygyro: ";
    rosidl_generator_traits::value_to_yaml(msg.ygyro, out);
    out << "\n";
  }

  // member: zgyro
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zgyro: ";
    rosidl_generator_traits::value_to_yaml(msg.zgyro, out);
    out << "\n";
  }

  // member: xmag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xmag: ";
    rosidl_generator_traits::value_to_yaml(msg.xmag, out);
    out << "\n";
  }

  // member: ymag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ymag: ";
    rosidl_generator_traits::value_to_yaml(msg.ymag, out);
    out << "\n";
  }

  // member: zmag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zmag: ";
    rosidl_generator_traits::value_to_yaml(msg.zmag, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScaledIMU & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::ScaledIMU & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::ScaledIMU & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::ScaledIMU>()
{
  return "vbn_ros_msgs::msg::ScaledIMU";
}

template<>
inline const char * name<vbn_ros_msgs::msg::ScaledIMU>()
{
  return "vbn_ros_msgs/msg/ScaledIMU";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::ScaledIMU>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::ScaledIMU>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::ScaledIMU>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__TRAITS_HPP_
