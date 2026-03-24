// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/TileCoordinatesList.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/tile_coordinates_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_TileCoordinatesList_coordinates
{
public:
  explicit Init_TileCoordinatesList_coordinates(::vbn_ros_msgs::msg::TileCoordinatesList & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::TileCoordinatesList coordinates(::vbn_ros_msgs::msg::TileCoordinatesList::_coordinates_type arg)
  {
    msg_.coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinatesList msg_;
};

class Init_TileCoordinatesList_mode_elevation
{
public:
  explicit Init_TileCoordinatesList_mode_elevation(::vbn_ros_msgs::msg::TileCoordinatesList & msg)
  : msg_(msg)
  {}
  Init_TileCoordinatesList_coordinates mode_elevation(::vbn_ros_msgs::msg::TileCoordinatesList::_mode_elevation_type arg)
  {
    msg_.mode_elevation = std::move(arg);
    return Init_TileCoordinatesList_coordinates(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinatesList msg_;
};

class Init_TileCoordinatesList_header
{
public:
  Init_TileCoordinatesList_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TileCoordinatesList_mode_elevation header(::vbn_ros_msgs::msg::TileCoordinatesList::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TileCoordinatesList_mode_elevation(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinatesList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::TileCoordinatesList>()
{
  return vbn_ros_msgs::msg::builder::Init_TileCoordinatesList_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__BUILDER_HPP_
