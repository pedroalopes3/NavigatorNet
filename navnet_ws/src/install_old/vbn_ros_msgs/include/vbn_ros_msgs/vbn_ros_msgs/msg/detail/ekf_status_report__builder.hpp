// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/EKFStatusReport.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/ekf_status_report__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_EKFStatusReport_airspeed_variance
{
public:
  explicit Init_EKFStatusReport_airspeed_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::EKFStatusReport airspeed_variance(::vbn_ros_msgs::msg::EKFStatusReport::_airspeed_variance_type arg)
  {
    msg_.airspeed_variance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_terrain_alt_variance
{
public:
  explicit Init_EKFStatusReport_terrain_alt_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_airspeed_variance terrain_alt_variance(::vbn_ros_msgs::msg::EKFStatusReport::_terrain_alt_variance_type arg)
  {
    msg_.terrain_alt_variance = std::move(arg);
    return Init_EKFStatusReport_airspeed_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_compass_variance
{
public:
  explicit Init_EKFStatusReport_compass_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_terrain_alt_variance compass_variance(::vbn_ros_msgs::msg::EKFStatusReport::_compass_variance_type arg)
  {
    msg_.compass_variance = std::move(arg);
    return Init_EKFStatusReport_terrain_alt_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_pos_vert_variance
{
public:
  explicit Init_EKFStatusReport_pos_vert_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_compass_variance pos_vert_variance(::vbn_ros_msgs::msg::EKFStatusReport::_pos_vert_variance_type arg)
  {
    msg_.pos_vert_variance = std::move(arg);
    return Init_EKFStatusReport_compass_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_pos_horiz_variance
{
public:
  explicit Init_EKFStatusReport_pos_horiz_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_pos_vert_variance pos_horiz_variance(::vbn_ros_msgs::msg::EKFStatusReport::_pos_horiz_variance_type arg)
  {
    msg_.pos_horiz_variance = std::move(arg);
    return Init_EKFStatusReport_pos_vert_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_velocity_variance
{
public:
  explicit Init_EKFStatusReport_velocity_variance(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_pos_horiz_variance velocity_variance(::vbn_ros_msgs::msg::EKFStatusReport::_velocity_variance_type arg)
  {
    msg_.velocity_variance = std::move(arg);
    return Init_EKFStatusReport_pos_horiz_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_flags
{
public:
  explicit Init_EKFStatusReport_flags(::vbn_ros_msgs::msg::EKFStatusReport & msg)
  : msg_(msg)
  {}
  Init_EKFStatusReport_velocity_variance flags(::vbn_ros_msgs::msg::EKFStatusReport::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_EKFStatusReport_velocity_variance(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

class Init_EKFStatusReport_header
{
public:
  Init_EKFStatusReport_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EKFStatusReport_flags header(::vbn_ros_msgs::msg::EKFStatusReport::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EKFStatusReport_flags(msg_);
  }

private:
  ::vbn_ros_msgs::msg::EKFStatusReport msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::EKFStatusReport>()
{
  return vbn_ros_msgs::msg::builder::Init_EKFStatusReport_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__BUILDER_HPP_
