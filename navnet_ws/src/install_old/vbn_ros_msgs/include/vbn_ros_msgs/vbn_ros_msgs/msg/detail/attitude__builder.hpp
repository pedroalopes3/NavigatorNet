// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/Attitude.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/attitude__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_Attitude_yawspeed
{
public:
  explicit Init_Attitude_yawspeed(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::Attitude yawspeed(::vbn_ros_msgs::msg::Attitude::_yawspeed_type arg)
  {
    msg_.yawspeed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_pitchspeed
{
public:
  explicit Init_Attitude_pitchspeed(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yawspeed pitchspeed(::vbn_ros_msgs::msg::Attitude::_pitchspeed_type arg)
  {
    msg_.pitchspeed = std::move(arg);
    return Init_Attitude_yawspeed(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_rollspeed
{
public:
  explicit Init_Attitude_rollspeed(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_pitchspeed rollspeed(::vbn_ros_msgs::msg::Attitude::_rollspeed_type arg)
  {
    msg_.rollspeed = std::move(arg);
    return Init_Attitude_pitchspeed(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_yaw
{
public:
  explicit Init_Attitude_yaw(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_rollspeed yaw(::vbn_ros_msgs::msg::Attitude::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Attitude_rollspeed(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_pitch
{
public:
  explicit Init_Attitude_pitch(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_yaw pitch(::vbn_ros_msgs::msg::Attitude::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Attitude_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_roll
{
public:
  explicit Init_Attitude_roll(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_pitch roll(::vbn_ros_msgs::msg::Attitude::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Attitude_pitch(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_time_boot_ms
{
public:
  explicit Init_Attitude_time_boot_ms(::vbn_ros_msgs::msg::Attitude & msg)
  : msg_(msg)
  {}
  Init_Attitude_roll time_boot_ms(::vbn_ros_msgs::msg::Attitude::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_Attitude_roll(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

class Init_Attitude_header
{
public:
  Init_Attitude_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Attitude_time_boot_ms header(::vbn_ros_msgs::msg::Attitude::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Attitude_time_boot_ms(msg_);
  }

private:
  ::vbn_ros_msgs::msg::Attitude msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::Attitude>()
{
  return vbn_ros_msgs::msg::builder::Init_Attitude_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__ATTITUDE__BUILDER_HPP_
