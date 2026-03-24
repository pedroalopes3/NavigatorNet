// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/vision_navigation_autopilot_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisionNavigationAutopilotInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: time_msec
  {
    out << "time_msec: ";
    rosidl_generator_traits::value_to_yaml(msg.time_msec, out);
    out << ", ";
  }

  // member: alarms
  {
    out << "alarms: ";
    rosidl_generator_traits::value_to_yaml(msg.alarms, out);
    out << ", ";
  }

  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: lng
  {
    out << "lng: ";
    rosidl_generator_traits::value_to_yaml(msg.lng, out);
    out << ", ";
  }

  // member: alt_msl
  {
    out << "alt_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_msl, out);
    out << ", ";
  }

  // member: pos_variance_x
  {
    out << "pos_variance_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_x, out);
    out << ", ";
  }

  // member: pos_variance_y
  {
    out << "pos_variance_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_y, out);
    out << ", ";
  }

  // member: pos_variance_z
  {
    out << "pos_variance_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_z, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: vz
  {
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionNavigationAutopilotInfo & msg,
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

  // member: time_msec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_msec: ";
    rosidl_generator_traits::value_to_yaml(msg.time_msec, out);
    out << "\n";
  }

  // member: alarms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alarms: ";
    rosidl_generator_traits::value_to_yaml(msg.alarms, out);
    out << "\n";
  }

  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: lng
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lng: ";
    rosidl_generator_traits::value_to_yaml(msg.lng, out);
    out << "\n";
  }

  // member: alt_msl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt_msl: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_msl, out);
    out << "\n";
  }

  // member: pos_variance_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_variance_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_x, out);
    out << "\n";
  }

  // member: pos_variance_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_variance_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_y, out);
    out << "\n";
  }

  // member: pos_variance_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_variance_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_variance_z, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionNavigationAutopilotInfo & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>()
{
  return "vbn_ros_msgs::msg::VisionNavigationAutopilotInfo";
}

template<>
inline const char * name<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>()
{
  return "vbn_ros_msgs/msg/VisionNavigationAutopilotInfo";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__TRAITS_HPP_
