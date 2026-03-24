// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__BUILDER_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vbn_ros_msgs/msg/detail/rc_channels__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vbn_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_RCChannels_rssi
{
public:
  explicit Init_RCChannels_rssi(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  ::vbn_ros_msgs::msg::RCChannels rssi(::vbn_ros_msgs::msg::RCChannels::_rssi_type arg)
  {
    msg_.rssi = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan18_raw
{
public:
  explicit Init_RCChannels_chan18_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_rssi chan18_raw(::vbn_ros_msgs::msg::RCChannels::_chan18_raw_type arg)
  {
    msg_.chan18_raw = std::move(arg);
    return Init_RCChannels_rssi(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan17_raw
{
public:
  explicit Init_RCChannels_chan17_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan18_raw chan17_raw(::vbn_ros_msgs::msg::RCChannels::_chan17_raw_type arg)
  {
    msg_.chan17_raw = std::move(arg);
    return Init_RCChannels_chan18_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan16_raw
{
public:
  explicit Init_RCChannels_chan16_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan17_raw chan16_raw(::vbn_ros_msgs::msg::RCChannels::_chan16_raw_type arg)
  {
    msg_.chan16_raw = std::move(arg);
    return Init_RCChannels_chan17_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan15_raw
{
public:
  explicit Init_RCChannels_chan15_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan16_raw chan15_raw(::vbn_ros_msgs::msg::RCChannels::_chan15_raw_type arg)
  {
    msg_.chan15_raw = std::move(arg);
    return Init_RCChannels_chan16_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan14_raw
{
public:
  explicit Init_RCChannels_chan14_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan15_raw chan14_raw(::vbn_ros_msgs::msg::RCChannels::_chan14_raw_type arg)
  {
    msg_.chan14_raw = std::move(arg);
    return Init_RCChannels_chan15_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan13_raw
{
public:
  explicit Init_RCChannels_chan13_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan14_raw chan13_raw(::vbn_ros_msgs::msg::RCChannels::_chan13_raw_type arg)
  {
    msg_.chan13_raw = std::move(arg);
    return Init_RCChannels_chan14_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan12_raw
{
public:
  explicit Init_RCChannels_chan12_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan13_raw chan12_raw(::vbn_ros_msgs::msg::RCChannels::_chan12_raw_type arg)
  {
    msg_.chan12_raw = std::move(arg);
    return Init_RCChannels_chan13_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan11_raw
{
public:
  explicit Init_RCChannels_chan11_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan12_raw chan11_raw(::vbn_ros_msgs::msg::RCChannels::_chan11_raw_type arg)
  {
    msg_.chan11_raw = std::move(arg);
    return Init_RCChannels_chan12_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan10_raw
{
public:
  explicit Init_RCChannels_chan10_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan11_raw chan10_raw(::vbn_ros_msgs::msg::RCChannels::_chan10_raw_type arg)
  {
    msg_.chan10_raw = std::move(arg);
    return Init_RCChannels_chan11_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan9_raw
{
public:
  explicit Init_RCChannels_chan9_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan10_raw chan9_raw(::vbn_ros_msgs::msg::RCChannels::_chan9_raw_type arg)
  {
    msg_.chan9_raw = std::move(arg);
    return Init_RCChannels_chan10_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan8_raw
{
public:
  explicit Init_RCChannels_chan8_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan9_raw chan8_raw(::vbn_ros_msgs::msg::RCChannels::_chan8_raw_type arg)
  {
    msg_.chan8_raw = std::move(arg);
    return Init_RCChannels_chan9_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan7_raw
{
public:
  explicit Init_RCChannels_chan7_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan8_raw chan7_raw(::vbn_ros_msgs::msg::RCChannels::_chan7_raw_type arg)
  {
    msg_.chan7_raw = std::move(arg);
    return Init_RCChannels_chan8_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan6_raw
{
public:
  explicit Init_RCChannels_chan6_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan7_raw chan6_raw(::vbn_ros_msgs::msg::RCChannels::_chan6_raw_type arg)
  {
    msg_.chan6_raw = std::move(arg);
    return Init_RCChannels_chan7_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan5_raw
{
public:
  explicit Init_RCChannels_chan5_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan6_raw chan5_raw(::vbn_ros_msgs::msg::RCChannels::_chan5_raw_type arg)
  {
    msg_.chan5_raw = std::move(arg);
    return Init_RCChannels_chan6_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan4_raw
{
public:
  explicit Init_RCChannels_chan4_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan5_raw chan4_raw(::vbn_ros_msgs::msg::RCChannels::_chan4_raw_type arg)
  {
    msg_.chan4_raw = std::move(arg);
    return Init_RCChannels_chan5_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan3_raw
{
public:
  explicit Init_RCChannels_chan3_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan4_raw chan3_raw(::vbn_ros_msgs::msg::RCChannels::_chan3_raw_type arg)
  {
    msg_.chan3_raw = std::move(arg);
    return Init_RCChannels_chan4_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan2_raw
{
public:
  explicit Init_RCChannels_chan2_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan3_raw chan2_raw(::vbn_ros_msgs::msg::RCChannels::_chan2_raw_type arg)
  {
    msg_.chan2_raw = std::move(arg);
    return Init_RCChannels_chan3_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chan1_raw
{
public:
  explicit Init_RCChannels_chan1_raw(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan2_raw chan1_raw(::vbn_ros_msgs::msg::RCChannels::_chan1_raw_type arg)
  {
    msg_.chan1_raw = std::move(arg);
    return Init_RCChannels_chan2_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_chancount
{
public:
  explicit Init_RCChannels_chancount(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chan1_raw chancount(::vbn_ros_msgs::msg::RCChannels::_chancount_type arg)
  {
    msg_.chancount = std::move(arg);
    return Init_RCChannels_chan1_raw(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_time_boot_ms
{
public:
  explicit Init_RCChannels_time_boot_ms(::vbn_ros_msgs::msg::RCChannels & msg)
  : msg_(msg)
  {}
  Init_RCChannels_chancount time_boot_ms(::vbn_ros_msgs::msg::RCChannels::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_RCChannels_chancount(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

class Init_RCChannels_header
{
public:
  Init_RCChannels_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RCChannels_time_boot_ms header(::vbn_ros_msgs::msg::RCChannels::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RCChannels_time_boot_ms(msg_);
  }

private:
  ::vbn_ros_msgs::msg::RCChannels msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vbn_ros_msgs::msg::RCChannels>()
{
  return vbn_ros_msgs::msg::builder::Init_RCChannels_header();
}

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__BUILDER_HPP_
