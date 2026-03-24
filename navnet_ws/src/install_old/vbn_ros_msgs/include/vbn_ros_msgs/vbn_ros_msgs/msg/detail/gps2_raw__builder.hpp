// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/GPS2Raw.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/gps2_raw__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_GPS2Raw_hdg_acc
{
public:
  explicit Init_GPS2Raw_hdg_acc(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::GPS2Raw hdg_acc(::vbn_ros_msgs::msg::GPS2Raw::_hdg_acc_type arg)
  {
    msg_.hdg_acc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_vel_acc
{
public:
  explicit Init_GPS2Raw_vel_acc(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_hdg_acc vel_acc(::vbn_ros_msgs::msg::GPS2Raw::_vel_acc_type arg)
  {
    msg_.vel_acc = std::move(arg);
    return Init_GPS2Raw_hdg_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_v_acc
{
public:
  explicit Init_GPS2Raw_v_acc(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_vel_acc v_acc(::vbn_ros_msgs::msg::GPS2Raw::_v_acc_type arg)
  {
    msg_.v_acc = std::move(arg);
    return Init_GPS2Raw_vel_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_h_acc
{
public:
  explicit Init_GPS2Raw_h_acc(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_v_acc h_acc(::vbn_ros_msgs::msg::GPS2Raw::_h_acc_type arg)
  {
    msg_.h_acc = std::move(arg);
    return Init_GPS2Raw_v_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_alt_ellipsoid
{
public:
  explicit Init_GPS2Raw_alt_ellipsoid(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_h_acc alt_ellipsoid(::vbn_ros_msgs::msg::GPS2Raw::_alt_ellipsoid_type arg)
  {
    msg_.alt_ellipsoid = std::move(arg);
    return Init_GPS2Raw_h_acc(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_yaw
{
public:
  explicit Init_GPS2Raw_yaw(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_alt_ellipsoid yaw(::vbn_ros_msgs::msg::GPS2Raw::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_GPS2Raw_alt_ellipsoid(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_dgps_age
{
public:
  explicit Init_GPS2Raw_dgps_age(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_yaw dgps_age(::vbn_ros_msgs::msg::GPS2Raw::_dgps_age_type arg)
  {
    msg_.dgps_age = std::move(arg);
    return Init_GPS2Raw_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_dgps_numch
{
public:
  explicit Init_GPS2Raw_dgps_numch(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_dgps_age dgps_numch(::vbn_ros_msgs::msg::GPS2Raw::_dgps_numch_type arg)
  {
    msg_.dgps_numch = std::move(arg);
    return Init_GPS2Raw_dgps_age(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_satellites_visible
{
public:
  explicit Init_GPS2Raw_satellites_visible(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_dgps_numch satellites_visible(::vbn_ros_msgs::msg::GPS2Raw::_satellites_visible_type arg)
  {
    msg_.satellites_visible = std::move(arg);
    return Init_GPS2Raw_dgps_numch(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_cog
{
public:
  explicit Init_GPS2Raw_cog(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_satellites_visible cog(::vbn_ros_msgs::msg::GPS2Raw::_cog_type arg)
  {
    msg_.cog = std::move(arg);
    return Init_GPS2Raw_satellites_visible(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_vel
{
public:
  explicit Init_GPS2Raw_vel(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_cog vel(::vbn_ros_msgs::msg::GPS2Raw::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_GPS2Raw_cog(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_epv
{
public:
  explicit Init_GPS2Raw_epv(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_vel epv(::vbn_ros_msgs::msg::GPS2Raw::_epv_type arg)
  {
    msg_.epv = std::move(arg);
    return Init_GPS2Raw_vel(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_eph
{
public:
  explicit Init_GPS2Raw_eph(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_epv eph(::vbn_ros_msgs::msg::GPS2Raw::_eph_type arg)
  {
    msg_.eph = std::move(arg);
    return Init_GPS2Raw_epv(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_alt
{
public:
  explicit Init_GPS2Raw_alt(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_eph alt(::vbn_ros_msgs::msg::GPS2Raw::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_GPS2Raw_eph(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_lon
{
public:
  explicit Init_GPS2Raw_lon(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_alt lon(::vbn_ros_msgs::msg::GPS2Raw::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_GPS2Raw_alt(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_lat
{
public:
  explicit Init_GPS2Raw_lat(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_lon lat(::vbn_ros_msgs::msg::GPS2Raw::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_GPS2Raw_lon(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_fix_type
{
public:
  explicit Init_GPS2Raw_fix_type(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_lat fix_type(::vbn_ros_msgs::msg::GPS2Raw::_fix_type_type arg)
  {
    msg_.fix_type = std::move(arg);
    return Init_GPS2Raw_lat(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_time_usec
{
public:
  explicit Init_GPS2Raw_time_usec(::vbn_ros_msgs::msg::GPS2Raw & msg)
  : msg_(msg)
  {}
  Init_GPS2Raw_fix_type time_usec(::vbn_ros_msgs::msg::GPS2Raw::_time_usec_type arg)
  {
    msg_.time_usec = std::move(arg);
    return Init_GPS2Raw_fix_type(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

class Init_GPS2Raw_header
{
public:
  Init_GPS2Raw_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPS2Raw_time_usec header(::vbn_ros_msgs::msg::GPS2Raw::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPS2Raw_time_usec(msg_);
  }

private:
  ::vbn_ros_msgs::msg::GPS2Raw msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::GPS2Raw>()
{
  return vbn_ros_msgs::msg::builder::Init_GPS2Raw_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GPS2_RAW__BUILDER_HPP_
