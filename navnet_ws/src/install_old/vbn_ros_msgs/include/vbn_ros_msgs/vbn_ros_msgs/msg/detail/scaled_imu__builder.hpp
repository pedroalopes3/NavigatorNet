// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/ScaledIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/scaled_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_ScaledIMU_temperature
{
public:
  explicit Init_ScaledIMU_temperature(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::ScaledIMU temperature(::vbn_ros_msgs::msg::ScaledIMU::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_zmag
{
public:
  explicit Init_ScaledIMU_zmag(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_temperature zmag(::vbn_ros_msgs::msg::ScaledIMU::_zmag_type arg)
  {
    msg_.zmag = std::move(arg);
    return Init_ScaledIMU_temperature(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_ymag
{
public:
  explicit Init_ScaledIMU_ymag(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_zmag ymag(::vbn_ros_msgs::msg::ScaledIMU::_ymag_type arg)
  {
    msg_.ymag = std::move(arg);
    return Init_ScaledIMU_zmag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_xmag
{
public:
  explicit Init_ScaledIMU_xmag(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_ymag xmag(::vbn_ros_msgs::msg::ScaledIMU::_xmag_type arg)
  {
    msg_.xmag = std::move(arg);
    return Init_ScaledIMU_ymag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_zgyro
{
public:
  explicit Init_ScaledIMU_zgyro(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_xmag zgyro(::vbn_ros_msgs::msg::ScaledIMU::_zgyro_type arg)
  {
    msg_.zgyro = std::move(arg);
    return Init_ScaledIMU_xmag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_ygyro
{
public:
  explicit Init_ScaledIMU_ygyro(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_zgyro ygyro(::vbn_ros_msgs::msg::ScaledIMU::_ygyro_type arg)
  {
    msg_.ygyro = std::move(arg);
    return Init_ScaledIMU_zgyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_xgyro
{
public:
  explicit Init_ScaledIMU_xgyro(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_ygyro xgyro(::vbn_ros_msgs::msg::ScaledIMU::_xgyro_type arg)
  {
    msg_.xgyro = std::move(arg);
    return Init_ScaledIMU_ygyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_zacc
{
public:
  explicit Init_ScaledIMU_zacc(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_xgyro zacc(::vbn_ros_msgs::msg::ScaledIMU::_zacc_type arg)
  {
    msg_.zacc = std::move(arg);
    return Init_ScaledIMU_xgyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_yacc
{
public:
  explicit Init_ScaledIMU_yacc(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_zacc yacc(::vbn_ros_msgs::msg::ScaledIMU::_yacc_type arg)
  {
    msg_.yacc = std::move(arg);
    return Init_ScaledIMU_zacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_xacc
{
public:
  explicit Init_ScaledIMU_xacc(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_yacc xacc(::vbn_ros_msgs::msg::ScaledIMU::_xacc_type arg)
  {
    msg_.xacc = std::move(arg);
    return Init_ScaledIMU_yacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_time_boot_ms
{
public:
  explicit Init_ScaledIMU_time_boot_ms(::vbn_ros_msgs::msg::ScaledIMU & msg)
  : msg_(msg)
  {}
  Init_ScaledIMU_xacc time_boot_ms(::vbn_ros_msgs::msg::ScaledIMU::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_ScaledIMU_xacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

class Init_ScaledIMU_header
{
public:
  Init_ScaledIMU_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScaledIMU_time_boot_ms header(::vbn_ros_msgs::msg::ScaledIMU::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ScaledIMU_time_boot_ms(msg_);
  }

private:
  ::vbn_ros_msgs::msg::ScaledIMU msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::ScaledIMU>()
{
  return vbn_ros_msgs::msg::builder::Init_ScaledIMU_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__SCALED_IMU__BUILDER_HPP_
