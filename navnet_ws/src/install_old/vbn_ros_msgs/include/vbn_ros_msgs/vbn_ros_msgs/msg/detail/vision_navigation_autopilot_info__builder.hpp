// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/vision_navigation_autopilot_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_VisionNavigationAutopilotInfo_yaw
{
public:
  explicit Init_VisionNavigationAutopilotInfo_yaw(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo yaw(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_pitch
{
public:
  explicit Init_VisionNavigationAutopilotInfo_pitch(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_yaw pitch(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_yaw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_roll
{
public:
  explicit Init_VisionNavigationAutopilotInfo_roll(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_pitch roll(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_pitch(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_vz
{
public:
  explicit Init_VisionNavigationAutopilotInfo_vz(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_roll vz(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_roll(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_vy
{
public:
  explicit Init_VisionNavigationAutopilotInfo_vy(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_vz vy(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_vz(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_vx
{
public:
  explicit Init_VisionNavigationAutopilotInfo_vx(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_vy vx(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_vy(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_pos_variance_z
{
public:
  explicit Init_VisionNavigationAutopilotInfo_pos_variance_z(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_vx pos_variance_z(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_pos_variance_z_type arg)
  {
    msg_.pos_variance_z = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_vx(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_pos_variance_y
{
public:
  explicit Init_VisionNavigationAutopilotInfo_pos_variance_y(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_pos_variance_z pos_variance_y(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_pos_variance_y_type arg)
  {
    msg_.pos_variance_y = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_pos_variance_z(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_pos_variance_x
{
public:
  explicit Init_VisionNavigationAutopilotInfo_pos_variance_x(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_pos_variance_y pos_variance_x(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_pos_variance_x_type arg)
  {
    msg_.pos_variance_x = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_pos_variance_y(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_alt_msl
{
public:
  explicit Init_VisionNavigationAutopilotInfo_alt_msl(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_pos_variance_x alt_msl(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_alt_msl_type arg)
  {
    msg_.alt_msl = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_pos_variance_x(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_lng
{
public:
  explicit Init_VisionNavigationAutopilotInfo_lng(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_alt_msl lng(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_lng_type arg)
  {
    msg_.lng = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_alt_msl(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_lat
{
public:
  explicit Init_VisionNavigationAutopilotInfo_lat(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_lng lat(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_lng(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_alarms
{
public:
  explicit Init_VisionNavigationAutopilotInfo_alarms(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_lat alarms(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_alarms_type arg)
  {
    msg_.alarms = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_lat(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_time_msec
{
public:
  explicit Init_VisionNavigationAutopilotInfo_time_msec(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo & msg)
  : msg_(msg)
  {}
  Init_VisionNavigationAutopilotInfo_alarms time_msec(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_time_msec_type arg)
  {
    msg_.time_msec = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_alarms(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

class Init_VisionNavigationAutopilotInfo_header
{
public:
  Init_VisionNavigationAutopilotInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionNavigationAutopilotInfo_time_msec header(::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VisionNavigationAutopilotInfo_time_msec(msg_);
  }

private:
  ::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::VisionNavigationAutopilotInfo>()
{
  return vbn_ros_msgs::msg::builder::Init_VisionNavigationAutopilotInfo_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__BUILDER_HPP_
