// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/EulerStamped.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/euler_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_EulerStamped_sequence
{
public:
  explicit Init_EulerStamped_sequence(::vbn_ros_msgs::msg::EulerStamped & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::EulerStamped sequence(::vbn_ros_msgs::msg::EulerStamped::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

class Init_EulerStamped_degrees
{
public:
  explicit Init_EulerStamped_degrees(::vbn_ros_msgs::msg::EulerStamped & msg)
  : msg_(msg)
  {}
  Init_EulerStamped_sequence degrees(::vbn_ros_msgs::msg::EulerStamped::_degrees_type arg)
  {
    msg_.degrees = std::move(arg);
    return Init_EulerStamped_sequence(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

class Init_EulerStamped_yaw
{
public:
  explicit Init_EulerStamped_yaw(::vbn_ros_msgs::msg::EulerStamped & msg)
  : msg_(msg)
  {}
  Init_EulerStamped_degrees yaw(::vbn_ros_msgs::msg::EulerStamped::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_EulerStamped_degrees(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

class Init_EulerStamped_pitch
{
public:
  explicit Init_EulerStamped_pitch(::vbn_ros_msgs::msg::EulerStamped & msg)
  : msg_(msg)
  {}
  Init_EulerStamped_yaw pitch(::vbn_ros_msgs::msg::EulerStamped::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_EulerStamped_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

class Init_EulerStamped_roll
{
public:
  explicit Init_EulerStamped_roll(::vbn_ros_msgs::msg::EulerStamped & msg)
  : msg_(msg)
  {}
  Init_EulerStamped_pitch roll(::vbn_ros_msgs::msg::EulerStamped::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_EulerStamped_pitch(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

class Init_EulerStamped_header
{
public:
  Init_EulerStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EulerStamped_roll header(::vbn_ros_msgs::msg::EulerStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EulerStamped_roll(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EulerStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::EulerStamped>()
{
  return vbn_ros_msgs::msg::builder::Init_EulerStamped_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EULER_STAMPED__BUILDER_HPP_
