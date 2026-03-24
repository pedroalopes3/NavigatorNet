// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/AHRS.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AHRS__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AHRS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/ahrs__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AHRS & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: omega_ix
  {
    out << "omega_ix: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_ix, out);
    out << ", ";
  }

  // member: omega_iy
  {
    out << "omega_iy: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_iy, out);
    out << ", ";
  }

  // member: omega_iz
  {
    out << "omega_iz: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_iz, out);
    out << ", ";
  }

  // member: accel_weight
  {
    out << "accel_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_weight, out);
    out << ", ";
  }

  // member: renorm_val
  {
    out << "renorm_val: ";
    rosidl_generator_traits::value_to_yaml(msg.renorm_val, out);
    out << ", ";
  }

  // member: error_rp
  {
    out << "error_rp: ";
    rosidl_generator_traits::value_to_yaml(msg.error_rp, out);
    out << ", ";
  }

  // member: error_yaw
  {
    out << "error_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.error_yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AHRS & msg,
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

  // member: omega_ix
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_ix: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_ix, out);
    out << "\n";
  }

  // member: omega_iy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_iy: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_iy, out);
    out << "\n";
  }

  // member: omega_iz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega_iz: ";
    rosidl_generator_traits::value_to_yaml(msg.omega_iz, out);
    out << "\n";
  }

  // member: accel_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_weight, out);
    out << "\n";
  }

  // member: renorm_val
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "renorm_val: ";
    rosidl_generator_traits::value_to_yaml(msg.renorm_val, out);
    out << "\n";
  }

  // member: error_rp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_rp: ";
    rosidl_generator_traits::value_to_yaml(msg.error_rp, out);
    out << "\n";
  }

  // member: error_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.error_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AHRS & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::AHRS & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::AHRS & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::AHRS>()
{
  return "vbn_ros_msgs::msg::AHRS";
}

template<>
inline const char * name<vbn_ros_msgs::msg::AHRS>()
{
  return "vbn_ros_msgs/msg/AHRS";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::AHRS>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::AHRS>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::AHRS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AHRS__TRAITS_HPP_
