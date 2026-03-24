// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/AHRS.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AHRS__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AHRS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/ahrs__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_AHRS_error_yaw
{
public:
  explicit Init_AHRS_error_yaw(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::AHRS error_yaw(::vbn_ros_msgs::msg::AHRS::_error_yaw_type arg)
  {
    msg_.error_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_error_rp
{
public:
  explicit Init_AHRS_error_rp(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_error_yaw error_rp(::vbn_ros_msgs::msg::AHRS::_error_rp_type arg)
  {
    msg_.error_rp = std::move(arg);
    return Init_AHRS_error_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_renorm_val
{
public:
  explicit Init_AHRS_renorm_val(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_error_rp renorm_val(::vbn_ros_msgs::msg::AHRS::_renorm_val_type arg)
  {
    msg_.renorm_val = std::move(arg);
    return Init_AHRS_error_rp(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_accel_weight
{
public:
  explicit Init_AHRS_accel_weight(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_renorm_val accel_weight(::vbn_ros_msgs::msg::AHRS::_accel_weight_type arg)
  {
    msg_.accel_weight = std::move(arg);
    return Init_AHRS_renorm_val(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_omega_iz
{
public:
  explicit Init_AHRS_omega_iz(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_accel_weight omega_iz(::vbn_ros_msgs::msg::AHRS::_omega_iz_type arg)
  {
    msg_.omega_iz = std::move(arg);
    return Init_AHRS_accel_weight(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_omega_iy
{
public:
  explicit Init_AHRS_omega_iy(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_omega_iz omega_iy(::vbn_ros_msgs::msg::AHRS::_omega_iy_type arg)
  {
    msg_.omega_iy = std::move(arg);
    return Init_AHRS_omega_iz(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_omega_ix
{
public:
  explicit Init_AHRS_omega_ix(::vbn_ros_msgs::msg::AHRS & msg)
  : msg_(msg)
  {}
  Init_AHRS_omega_iy omega_ix(::vbn_ros_msgs::msg::AHRS::_omega_ix_type arg)
  {
    msg_.omega_ix = std::move(arg);
    return Init_AHRS_omega_iy(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

class Init_AHRS_header
{
public:
  Init_AHRS_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AHRS_omega_ix header(::vbn_ros_msgs::msg::AHRS::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AHRS_omega_ix(msg_);
  }

private:
  ::vbn_ros_msgs::msg::AHRS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::AHRS>()
{
  return vbn_ros_msgs::msg::builder::Init_AHRS_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AHRS__BUILDER_HPP_
