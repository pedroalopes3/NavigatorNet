// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/VisionNavigationEstimation.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/vision_navigation_estimation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_VisionNavigationEstimation_pos_error
{
public:
  explicit Init_VisionNavigationEstimation_pos_error(::vbn_ros_msgs::msg::VisionNavigationEstimation & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::VisionNavigationEstimation pos_error(::vbn_ros_msgs::msg::VisionNavigationEstimation::_pos_error_type arg)
  {
    msg_.pos_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationEstimation msg_;
};

class Init_VisionNavigationEstimation_flags
{
public:
  explicit Init_VisionNavigationEstimation_flags(::vbn_ros_msgs::msg::VisionNavigationEstimation & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationEstimation_pos_error flags(::vbn_ros_msgs::msg::VisionNavigationEstimation::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_VisionNavigationEstimation_pos_error(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationEstimation msg_;
};

class Init_VisionNavigationEstimation_position
{
public:
  explicit Init_VisionNavigationEstimation_position(::vbn_ros_msgs::msg::VisionNavigationEstimation & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationEstimation_flags position(::vbn_ros_msgs::msg::VisionNavigationEstimation::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_VisionNavigationEstimation_flags(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationEstimation msg_;
};

class Init_VisionNavigationEstimation_header
{
public:
  Init_VisionNavigationEstimation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionNavigationEstimation_position header(::vbn_ros_msgs::msg::VisionNavigationEstimation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VisionNavigationEstimation_position(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationEstimation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::VisionNavigationEstimation>()
{
  return vbn_ros_msgs::msg::builder::Init_VisionNavigationEstimation_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__BUILDER_HPP_
