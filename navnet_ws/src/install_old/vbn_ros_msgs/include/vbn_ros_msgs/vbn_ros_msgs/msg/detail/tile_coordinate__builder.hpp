// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/tile_coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_TileCoordinate_source_type
{
public:
  explicit Init_TileCoordinate_source_type(::vbn_ros_msgs::msg::TileCoordinate & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::TileCoordinate source_type(::vbn_ros_msgs::msg::TileCoordinate::_source_type_type arg)
  {
    msg_.source_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinate msg_;
};

class Init_TileCoordinate_similarity_score
{
public:
  explicit Init_TileCoordinate_similarity_score(::vbn_ros_msgs::msg::TileCoordinate & msg)
  : msg_(msg)
  {}
  Init_TileCoordinate_source_type similarity_score(::vbn_ros_msgs::msg::TileCoordinate::_similarity_score_type arg)
  {
    msg_.similarity_score = std::move(arg);
    return Init_TileCoordinate_source_type(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinate msg_;
};

class Init_TileCoordinate_y
{
public:
  explicit Init_TileCoordinate_y(::vbn_ros_msgs::msg::TileCoordinate & msg)
  : msg_(msg)
  {}
  Init_TileCoordinate_similarity_score y(::vbn_ros_msgs::msg::TileCoordinate::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TileCoordinate_similarity_score(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinate msg_;
};

class Init_TileCoordinate_x
{
public:
  explicit Init_TileCoordinate_x(::vbn_ros_msgs::msg::TileCoordinate & msg)
  : msg_(msg)
  {}
  Init_TileCoordinate_y x(::vbn_ros_msgs::msg::TileCoordinate::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TileCoordinate_y(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinate msg_;
};

class Init_TileCoordinate_z
{
public:
  Init_TileCoordinate_z()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TileCoordinate_x z(::vbn_ros_msgs::msg::TileCoordinate::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_TileCoordinate_x(msg_);
  }

private:
  ::vbn_ros_msgs::msg::TileCoordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::TileCoordinate>()
{
  return vbn_ros_msgs::msg::builder::Init_TileCoordinate_z();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__BUILDER_HPP_
