// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/EKFStatusReport.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/ekf_status_report__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EKFStatusReport & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: velocity_variance
  {
    out << "velocity_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_variance, out);
    out << ", ";
  }

  // member: pos_horiz_variance
  {
    out << "pos_horiz_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_horiz_variance, out);
    out << ", ";
  }

  // member: pos_vert_variance
  {
    out << "pos_vert_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_vert_variance, out);
    out << ", ";
  }

  // member: compass_variance
  {
    out << "compass_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.compass_variance, out);
    out << ", ";
  }

  // member: terrain_alt_variance
  {
    out << "terrain_alt_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt_variance, out);
    out << ", ";
  }

  // member: airspeed_variance
  {
    out << "airspeed_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_variance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EKFStatusReport & msg,
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

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }

  // member: velocity_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_variance, out);
    out << "\n";
  }

  // member: pos_horiz_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_horiz_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_horiz_variance, out);
    out << "\n";
  }

  // member: pos_vert_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_vert_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_vert_variance, out);
    out << "\n";
  }

  // member: compass_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "compass_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.compass_variance, out);
    out << "\n";
  }

  // member: terrain_alt_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "terrain_alt_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt_variance, out);
    out << "\n";
  }

  // member: airspeed_variance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "airspeed_variance: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_variance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EKFStatusReport & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::EKFStatusReport & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::EKFStatusReport & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::EKFStatusReport>()
{
  return "vbn_ros_msgs::msg::EKFStatusReport";
}

template<>
inline const char * name<vbn_ros_msgs::msg::EKFStatusReport>()
{
  return "vbn_ros_msgs/msg/EKFStatusReport";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::EKFStatusReport>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::EKFStatusReport>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::EKFStatusReport>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__TRAITS_HPP_
