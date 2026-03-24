// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/Wind.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__WIND__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__WIND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/wind__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_Wind_speed_z
{
public:
  explicit Init_Wind_speed_z(::vbn_ros_msgs::msg::Wind & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::Wind speed_z(::vbn_ros_msgs::msg::Wind::_speed_z_type arg)
  {
    msg_.speed_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Wind msg_;
};

class Init_Wind_speed
{
public:
  explicit Init_Wind_speed(::vbn_ros_msgs::msg::Wind & msg)
  : msg_(msg)
  {}
  Init_Wind_speed_z speed(::vbn_ros_msgs::msg::Wind::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Wind_speed_z(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Wind msg_;
};

class Init_Wind_direction
{
public:
  explicit Init_Wind_direction(::vbn_ros_msgs::msg::Wind & msg)
  : msg_(msg)
  {}
  Init_Wind_speed direction(::vbn_ros_msgs::msg::Wind::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Wind_speed(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Wind msg_;
};

class Init_Wind_header
{
public:
  Init_Wind_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Wind_direction header(::vbn_ros_msgs::msg::Wind::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Wind_direction(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Wind msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::Wind>()
{
  return vbn_ros_msgs::msg::builder::Init_Wind_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__WIND__BUILDER_HPP_
