// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__TRAITS_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vbn_ros_msgs/msg/detail/tile_coordinate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vbn_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TileCoordinate & msg,
  std::ostream & out)
{
  out << "{";
  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: similarity_score
  {
    out << "similarity_score: ";
    rosidl_generator_traits::value_to_yaml(msg.similarity_score, out);
    out << ", ";
  }

  // member: source_type
  {
    out << "source_type: ";
    rosidl_generator_traits::value_to_yaml(msg.source_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TileCoordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: similarity_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "similarity_score: ";
    rosidl_generator_traits::value_to_yaml(msg.similarity_score, out);
    out << "\n";
  }

  // member: source_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_type: ";
    rosidl_generator_traits::value_to_yaml(msg.source_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TileCoordinate & msg, bool use_flow_style = false)
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
  const vbn_ros_msgs::msg::TileCoordinate & msg,
  std::ostream & out, size_t indentation = 0)
{
  vbn_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vbn_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vbn_ros_msgs::msg::TileCoordinate & msg)
{
  return vbn_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vbn_ros_msgs::msg::TileCoordinate>()
{
  return "vbn_ros_msgs::msg::TileCoordinate";
}

template<>
inline const char * name<vbn_ros_msgs::msg::TileCoordinate>()
{
  return "vbn_ros_msgs/msg/TileCoordinate";
}

template<>
struct has_fixed_size<vbn_ros_msgs::msg::TileCoordinate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vbn_ros_msgs::msg::TileCoordinate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vbn_ros_msgs::msg::TileCoordinate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__TRAITS_HPP_
