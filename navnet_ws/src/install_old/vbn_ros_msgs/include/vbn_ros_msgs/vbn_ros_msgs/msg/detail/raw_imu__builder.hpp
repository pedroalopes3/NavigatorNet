// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/RawIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/raw_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_RawIMU_temperature
{
public:
  explicit Init_RawIMU_temperature(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::RawIMU temperature(::vbn_ros_msgs::msg::RawIMU::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_id
{
public:
  explicit Init_RawIMU_id(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_temperature id(::vbn_ros_msgs::msg::RawIMU::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RawIMU_temperature(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_zmag
{
public:
  explicit Init_RawIMU_zmag(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_id zmag(::vbn_ros_msgs::msg::RawIMU::_zmag_type arg)
  {
    msg_.zmag = std::move(arg);
    return Init_RawIMU_id(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_ymag
{
public:
  explicit Init_RawIMU_ymag(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_zmag ymag(::vbn_ros_msgs::msg::RawIMU::_ymag_type arg)
  {
    msg_.ymag = std::move(arg);
    return Init_RawIMU_zmag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_xmag
{
public:
  explicit Init_RawIMU_xmag(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_ymag xmag(::vbn_ros_msgs::msg::RawIMU::_xmag_type arg)
  {
    msg_.xmag = std::move(arg);
    return Init_RawIMU_ymag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_zgyro
{
public:
  explicit Init_RawIMU_zgyro(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_xmag zgyro(::vbn_ros_msgs::msg::RawIMU::_zgyro_type arg)
  {
    msg_.zgyro = std::move(arg);
    return Init_RawIMU_xmag(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_ygyro
{
public:
  explicit Init_RawIMU_ygyro(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_zgyro ygyro(::vbn_ros_msgs::msg::RawIMU::_ygyro_type arg)
  {
    msg_.ygyro = std::move(arg);
    return Init_RawIMU_zgyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_xgyro
{
public:
  explicit Init_RawIMU_xgyro(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_ygyro xgyro(::vbn_ros_msgs::msg::RawIMU::_xgyro_type arg)
  {
    msg_.xgyro = std::move(arg);
    return Init_RawIMU_ygyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_zacc
{
public:
  explicit Init_RawIMU_zacc(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_xgyro zacc(::vbn_ros_msgs::msg::RawIMU::_zacc_type arg)
  {
    msg_.zacc = std::move(arg);
    return Init_RawIMU_xgyro(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_yacc
{
public:
  explicit Init_RawIMU_yacc(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_zacc yacc(::vbn_ros_msgs::msg::RawIMU::_yacc_type arg)
  {
    msg_.yacc = std::move(arg);
    return Init_RawIMU_zacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_xacc
{
public:
  explicit Init_RawIMU_xacc(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_yacc xacc(::vbn_ros_msgs::msg::RawIMU::_xacc_type arg)
  {
    msg_.xacc = std::move(arg);
    return Init_RawIMU_yacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_time_usec
{
public:
  explicit Init_RawIMU_time_usec(::vbn_ros_msgs::msg::RawIMU & msg)
  : msg_(msg)
  {}
  Init_RawIMU_xacc time_usec(::vbn_ros_msgs::msg::RawIMU::_time_usec_type arg)
  {
    msg_.time_usec = std::move(arg);
    return Init_RawIMU_xacc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

class Init_RawIMU_header
{
public:
  Init_RawIMU_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RawIMU_time_usec header(::vbn_ros_msgs::msg::RawIMU::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RawIMU_time_usec(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RawIMU msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::RawIMU>()
{
  return vbn_ros_msgs::msg::builder::Init_RawIMU_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__BUILDER_HPP_
