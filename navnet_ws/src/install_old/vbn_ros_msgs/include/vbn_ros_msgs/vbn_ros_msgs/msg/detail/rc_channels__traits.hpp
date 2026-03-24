// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/rc_channels__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RCChannels & msg,
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

  // member: chancount
  {
    out << "chancount: ";
    rosidl_generator_traits::value_to_yaml(msg.chancount, out);
    out << ", ";
  }

  // member: chan1_raw
  {
    out << "chan1_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan1_raw, out);
    out << ", ";
  }

  // member: chan2_raw
  {
    out << "chan2_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan2_raw, out);
    out << ", ";
  }

  // member: chan3_raw
  {
    out << "chan3_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan3_raw, out);
    out << ", ";
  }

  // member: chan4_raw
  {
    out << "chan4_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan4_raw, out);
    out << ", ";
  }

  // member: chan5_raw
  {
    out << "chan5_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan5_raw, out);
    out << ", ";
  }

  // member: chan6_raw
  {
    out << "chan6_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan6_raw, out);
    out << ", ";
  }

  // member: chan7_raw
  {
    out << "chan7_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan7_raw, out);
    out << ", ";
  }

  // member: chan8_raw
  {
    out << "chan8_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan8_raw, out);
    out << ", ";
  }

  // member: chan9_raw
  {
    out << "chan9_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan9_raw, out);
    out << ", ";
  }

  // member: chan10_raw
  {
    out << "chan10_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan10_raw, out);
    out << ", ";
  }

  // member: chan11_raw
  {
    out << "chan11_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan11_raw, out);
    out << ", ";
  }

  // member: chan12_raw
  {
    out << "chan12_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan12_raw, out);
    out << ", ";
  }

  // member: chan13_raw
  {
    out << "chan13_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan13_raw, out);
    out << ", ";
  }

  // member: chan14_raw
  {
    out << "chan14_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan14_raw, out);
    out << ", ";
  }

  // member: chan15_raw
  {
    out << "chan15_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan15_raw, out);
    out << ", ";
  }

  // member: chan16_raw
  {
    out << "chan16_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan16_raw, out);
    out << ", ";
  }

  // member: chan17_raw
  {
    out << "chan17_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan17_raw, out);
    out << ", ";
  }

  // member: chan18_raw
  {
    out << "chan18_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan18_raw, out);
    out << ", ";
  }

  // member: rssi
  {
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RCChannels & msg,
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

  // member: chancount
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chancount: ";
    rosidl_generator_traits::value_to_yaml(msg.chancount, out);
    out << "\n";
  }

  // member: chan1_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan1_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan1_raw, out);
    out << "\n";
  }

  // member: chan2_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan2_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan2_raw, out);
    out << "\n";
  }

  // member: chan3_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan3_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan3_raw, out);
    out << "\n";
  }

  // member: chan4_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan4_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan4_raw, out);
    out << "\n";
  }

  // member: chan5_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan5_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan5_raw, out);
    out << "\n";
  }

  // member: chan6_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan6_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan6_raw, out);
    out << "\n";
  }

  // member: chan7_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan7_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan7_raw, out);
    out << "\n";
  }

  // member: chan8_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan8_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan8_raw, out);
    out << "\n";
  }

  // member: chan9_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan9_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan9_raw, out);
    out << "\n";
  }

  // member: chan10_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan10_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan10_raw, out);
    out << "\n";
  }

  // member: chan11_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan11_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan11_raw, out);
    out << "\n";
  }

  // member: chan12_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan12_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan12_raw, out);
    out << "\n";
  }

  // member: chan13_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan13_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan13_raw, out);
    out << "\n";
  }

  // member: chan14_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan14_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan14_raw, out);
    out << "\n";
  }

  // member: chan15_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan15_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan15_raw, out);
    out << "\n";
  }

  // member: chan16_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan16_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan16_raw, out);
    out << "\n";
  }

  // member: chan17_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan17_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan17_raw, out);
    out << "\n";
  }

  // member: chan18_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "chan18_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.chan18_raw, out);
    out << "\n";
  }

  // member: rssi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RCChannels & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::RCChannels & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::RCChannels & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::RCChannels>()
{
  return "vbn_ros_msgs::msg::RCChannels";
}

template<>
inline const char * name<vbn_ros_msgs::msg::RCChannels>()
{
  return "vbn_ros_msgs/msg/RCChannels";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::RCChannels>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::RCChannels>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vbn_ros_msgs::msg::RCChannels>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__TRAITS_HPP_
