// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/GPSRawInt.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/gps_raw_int__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_GPSRawInt_yaw
{
public:
  explicit Init_GPSRawInt_yaw(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::GPSRawInt yaw(::vbn_ros_msgs::msg::GPSRawInt::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_hdg_acc
{
public:
  explicit Init_GPSRawInt_hdg_acc(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_yaw hdg_acc(::vbn_ros_msgs::msg::GPSRawInt::_hdg_acc_type arg)
  {
    msg_.hdg_acc = std::move(arg);
    return Init_GPSRawInt_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_vel_acc
{
public:
  explicit Init_GPSRawInt_vel_acc(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_hdg_acc vel_acc(::vbn_ros_msgs::msg::GPSRawInt::_vel_acc_type arg)
  {
    msg_.vel_acc = std::move(arg);
    return Init_GPSRawInt_hdg_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_v_acc
{
public:
  explicit Init_GPSRawInt_v_acc(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_vel_acc v_acc(::vbn_ros_msgs::msg::GPSRawInt::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_GPSRawInt_vel_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_h_acc
{
public:
  explicit Init_GPSRawInt_h_acc(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_v_acc h_acc(::vbn_ros_msgs::msg::GPSRawInt::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_GPSRawInt_v_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_alt_ellipsoid
{
public:
  explicit Init_GPSRawInt_alt_ellipsoid(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_h_acc alt_ellipsoid(::vbn_ros_msgs::msg::GPSRawInt::_alt_ellipsoid_type arg)
  {
    msg_.alt_ellipsoid = std::move(arg);
    return Init_GPSRawInt_h_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_satellites_visible
{
public:
  explicit Init_GPSRawInt_satellites_visible(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_alt_ellipsoid satellites_visible(::vbn_ros_msgs::msg::GPSRawInt::_satellites_visible_type arg)
  {
    msg_.satellites_visible = std::move(arg);
    return Init_GPSRawInt_alt_ellipsoid(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_cog
{
public:
  explicit Init_GPSRawInt_cog(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_satellites_visible cog(::vbn_ros_msgs::msg::GPSRawInt::_cog_type arg)
  {
    msg_.cog = std::move(arg);
    return Init_GPSRawInt_satellites_visible(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_vel
{
public:
  explicit Init_GPSRawInt_vel(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_cog vel(::vbn_ros_msgs::msg::GPSRawInt::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_GPSRawInt_cog(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_epv
{
public:
  explicit Init_GPSRawInt_epv(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_vel epv(::vbn_ros_msgs::msg::GPSRawInt::_epv_type arg)
  {
    msg_.epv = std::move(arg);
    return Init_GPSRawInt_vel(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_eph
{
public:
  explicit Init_GPSRawInt_eph(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_epv eph(::vbn_ros_msgs::msg::GPSRawInt::_eph_type arg)
  {
    msg_.eph = std::move(arg);
    return Init_GPSRawInt_epv(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_alt
{
public:
  explicit Init_GPSRawInt_alt(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_eph alt(::vbn_ros_msgs::msg::GPSRawInt::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_GPSRawInt_eph(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_lon
{
public:
  explicit Init_GPSRawInt_lon(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_alt lon(::vbn_ros_msgs::msg::GPSRawInt::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_GPSRawInt_alt(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_lat
{
public:
  explicit Init_GPSRawInt_lat(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_lon lat(::vbn_ros_msgs::msg::GPSRawInt::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_GPSRawInt_lon(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_fix_type
{
public:
  explicit Init_GPSRawInt_fix_type(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_lat fix_type(::vbn_ros_msgs::msg::GPSRawInt::_fix_type_type arg)
  {
    msg_.fix_type = std::move(arg);
    return Init_GPSRawInt_lat(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_time_usec
{
public:
  explicit Init_GPSRawInt_time_usec(::vbn_ros_msgs::msg::GPSRawInt & msg)
  : msg_(msg)
  {}
  Init_GPSRawInt_fix_type time_usec(::vbn_ros_msgs::msg::GPSRawInt::_time_usec_type arg)
  {
    msg_.time_usec = std::move(arg);
    return Init_GPSRawInt_fix_type(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

class Init_GPSRawInt_header
{
public:
  Init_GPSRawInt_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPSRawInt_time_usec header(::vbn_ros_msgs::msg::GPSRawInt::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPSRawInt_time_usec(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPSRawInt msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::GPSRawInt>()
{
  return vbn_ros_msgs::msg::builder::Init_GPSRawInt_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GPS_RAW_INT__BUILDER_HPP_
