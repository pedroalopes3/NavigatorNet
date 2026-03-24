// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/GlobalPositionInt.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/global_position_int__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_GlobalPositionInt_hdg
{
public:
  explicit Init_GlobalPositionInt_hdg(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::GlobalPositionInt hdg(::vbn_ros_msgs::msg::GlobalPositionInt::_hdg_type arg)
  {
    msg_.hdg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_vz
{
public:
  explicit Init_GlobalPositionInt_vz(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_hdg vz(::vbn_ros_msgs::msg::GlobalPositionInt::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_GlobalPositionInt_hdg(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_vy
{
public:
  explicit Init_GlobalPositionInt_vy(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_vz vy(::vbn_ros_msgs::msg::GlobalPositionInt::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_GlobalPositionInt_vz(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_vx
{
public:
  explicit Init_GlobalPositionInt_vx(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_vy vx(::vbn_ros_msgs::msg::GlobalPositionInt::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_GlobalPositionInt_vy(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_relative_alt
{
public:
  explicit Init_GlobalPositionInt_relative_alt(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_vx relative_alt(::vbn_ros_msgs::msg::GlobalPositionInt::_relative_alt_type arg)
  {
    msg_.relative_alt = std::move(arg);
    return Init_GlobalPositionInt_vx(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_alt
{
public:
  explicit Init_GlobalPositionInt_alt(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_relative_alt alt(::vbn_ros_msgs::msg::GlobalPositionInt::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_GlobalPositionInt_relative_alt(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_lon
{
public:
  explicit Init_GlobalPositionInt_lon(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_alt lon(::vbn_ros_msgs::msg::GlobalPositionInt::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_GlobalPositionInt_alt(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_lat
{
public:
  explicit Init_GlobalPositionInt_lat(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_lon lat(::vbn_ros_msgs::msg::GlobalPositionInt::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_GlobalPositionInt_lon(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_time_boot_ms
{
public:
  explicit Init_GlobalPositionInt_time_boot_ms(::vbn_ros_msgs::msg::GlobalPositionInt & msg)
  : msg_(msg)
  {}
  Init_GlobalPositionInt_lat time_boot_ms(::vbn_ros_msgs::msg::GlobalPositionInt::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_GlobalPositionInt_lat(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

class Init_GlobalPositionInt_header
{
public:
  Init_GlobalPositionInt_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GlobalPositionInt_time_boot_ms header(::vbn_ros_msgs::msg::GlobalPositionInt::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GlobalPositionInt_time_boot_ms(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GlobalPositionInt msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::GlobalPositionInt>()
{
  return vbn_ros_msgs::msg::builder::Init_GlobalPositionInt_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__BUILDER_HPP_
