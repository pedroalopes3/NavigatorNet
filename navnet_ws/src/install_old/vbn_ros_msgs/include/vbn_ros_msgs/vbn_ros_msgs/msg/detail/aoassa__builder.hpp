// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/AOASSA.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AOASSA__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AOASSA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/aoassa__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_AOASSA_ssa
{
public:
  explicit Init_AOASSA_ssa(::vbn_ros_msgs::msg::AOASSA & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::AOASSA ssa(::vbn_ros_msgs::msg::AOASSA::_ssa_type arg)
  {
    msg_.ssa = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AOASSA msg_;
};

class Init_AOASSA_aoa
{
public:
  explicit Init_AOASSA_aoa(::vbn_ros_msgs::msg::AOASSA & msg)
  : msg_(msg)
  {}
  Init_AOASSA_ssa aoa(::vbn_ros_msgs::msg::AOASSA::_aoa_type arg)
  {
    msg_.aoa = std::move(arg);
    return Init_AOASSA_ssa(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AOASSA msg_;
};

class Init_AOASSA_time_usec
{
public:
  explicit Init_AOASSA_time_usec(::vbn_ros_msgs::msg::AOASSA & msg)
  : msg_(msg)
  {}
  Init_AOASSA_aoa time_usec(::vbn_ros_msgs::msg::AOASSA::_time_usec_type arg)
  {
    msg_.time_usec = std::move(arg);
    return Init_AOASSA_aoa(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AOASSA msg_;
};

class Init_AOASSA_header
{
public:
  Init_AOASSA_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AOASSA_time_usec header(::vbn_ros_msgs::msg::AOASSA::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AOASSA_time_usec(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AOASSA msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::AOASSA>()
{
  return vbn_ros_msgs::msg::builder::Init_AOASSA_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AOASSA__BUILDER_HPP_
