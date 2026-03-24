// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vbn_ros_msgs__msg__RCChannels __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__RCChannels __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RCChannels_
{
  using Type = RCChannels_<ContainerAllocator>;

  explicit RCChannels_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->chancount = 0;
      this->chan1_raw = 0;
      this->chan2_raw = 0;
      this->chan3_raw = 0;
      this->chan4_raw = 0;
      this->chan5_raw = 0;
      this->chan6_raw = 0;
      this->chan7_raw = 0;
      this->chan8_raw = 0;
      this->chan9_raw = 0;
      this->chan10_raw = 0;
      this->chan11_raw = 0;
      this->chan12_raw = 0;
      this->chan13_raw = 0;
      this->chan14_raw = 0;
      this->chan15_raw = 0;
      this->chan16_raw = 0;
      this->chan17_raw = 0;
      this->chan18_raw = 0;
      this->rssi = 0;
    }
  }

  explicit RCChannels_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->chancount = 0;
      this->chan1_raw = 0;
      this->chan2_raw = 0;
      this->chan3_raw = 0;
      this->chan4_raw = 0;
      this->chan5_raw = 0;
      this->chan6_raw = 0;
      this->chan7_raw = 0;
      this->chan8_raw = 0;
      this->chan9_raw = 0;
      this->chan10_raw = 0;
      this->chan11_raw = 0;
      this->chan12_raw = 0;
      this->chan13_raw = 0;
      this->chan14_raw = 0;
      this->chan15_raw = 0;
      this->chan16_raw = 0;
      this->chan17_raw = 0;
      this->chan18_raw = 0;
      this->rssi = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _chancount_type =
    uint8_t;
  _chancount_type chancount;
  using _chan1_raw_type =
    uint16_t;
  _chan1_raw_type chan1_raw;
  using _chan2_raw_type =
    uint16_t;
  _chan2_raw_type chan2_raw;
  using _chan3_raw_type =
    uint16_t;
  _chan3_raw_type chan3_raw;
  using _chan4_raw_type =
    uint16_t;
  _chan4_raw_type chan4_raw;
  using _chan5_raw_type =
    uint16_t;
  _chan5_raw_type chan5_raw;
  using _chan6_raw_type =
    uint16_t;
  _chan6_raw_type chan6_raw;
  using _chan7_raw_type =
    uint16_t;
  _chan7_raw_type chan7_raw;
  using _chan8_raw_type =
    uint16_t;
  _chan8_raw_type chan8_raw;
  using _chan9_raw_type =
    uint16_t;
  _chan9_raw_type chan9_raw;
  using _chan10_raw_type =
    uint16_t;
  _chan10_raw_type chan10_raw;
  using _chan11_raw_type =
    uint16_t;
  _chan11_raw_type chan11_raw;
  using _chan12_raw_type =
    uint16_t;
  _chan12_raw_type chan12_raw;
  using _chan13_raw_type =
    uint16_t;
  _chan13_raw_type chan13_raw;
  using _chan14_raw_type =
    uint16_t;
  _chan14_raw_type chan14_raw;
  using _chan15_raw_type =
    uint16_t;
  _chan15_raw_type chan15_raw;
  using _chan16_raw_type =
    uint16_t;
  _chan16_raw_type chan16_raw;
  using _chan17_raw_type =
    uint16_t;
  _chan17_raw_type chan17_raw;
  using _chan18_raw_type =
    uint16_t;
  _chan18_raw_type chan18_raw;
  using _rssi_type =
    uint8_t;
  _rssi_type rssi;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time_boot_ms(
    const uint32_t & _arg)
  {
    this->time_boot_ms = _arg;
    return *this;
  }
  Type & set__chancount(
    const uint8_t & _arg)
  {
    this->chancount = _arg;
    return *this;
  }
  Type & set__chan1_raw(
    const uint16_t & _arg)
  {
    this->chan1_raw = _arg;
    return *this;
  }
  Type & set__chan2_raw(
    const uint16_t & _arg)
  {
    this->chan2_raw = _arg;
    return *this;
  }
  Type & set__chan3_raw(
    const uint16_t & _arg)
  {
    this->chan3_raw = _arg;
    return *this;
  }
  Type & set__chan4_raw(
    const uint16_t & _arg)
  {
    this->chan4_raw = _arg;
    return *this;
  }
  Type & set__chan5_raw(
    const uint16_t & _arg)
  {
    this->chan5_raw = _arg;
    return *this;
  }
  Type & set__chan6_raw(
    const uint16_t & _arg)
  {
    this->chan6_raw = _arg;
    return *this;
  }
  Type & set__chan7_raw(
    const uint16_t & _arg)
  {
    this->chan7_raw = _arg;
    return *this;
  }
  Type & set__chan8_raw(
    const uint16_t & _arg)
  {
    this->chan8_raw = _arg;
    return *this;
  }
  Type & set__chan9_raw(
    const uint16_t & _arg)
  {
    this->chan9_raw = _arg;
    return *this;
  }
  Type & set__chan10_raw(
    const uint16_t & _arg)
  {
    this->chan10_raw = _arg;
    return *this;
  }
  Type & set__chan11_raw(
    const uint16_t & _arg)
  {
    this->chan11_raw = _arg;
    return *this;
  }
  Type & set__chan12_raw(
    const uint16_t & _arg)
  {
    this->chan12_raw = _arg;
    return *this;
  }
  Type & set__chan13_raw(
    const uint16_t & _arg)
  {
    this->chan13_raw = _arg;
    return *this;
  }
  Type & set__chan14_raw(
    const uint16_t & _arg)
  {
    this->chan14_raw = _arg;
    return *this;
  }
  Type & set__chan15_raw(
    const uint16_t & _arg)
  {
    this->chan15_raw = _arg;
    return *this;
  }
  Type & set__chan16_raw(
    const uint16_t & _arg)
  {
    this->chan16_raw = _arg;
    return *this;
  }
  Type & set__chan17_raw(
    const uint16_t & _arg)
  {
    this->chan17_raw = _arg;
    return *this;
  }
  Type & set__chan18_raw(
    const uint16_t & _arg)
  {
    this->chan18_raw = _arg;
    return *this;
  }
  Type & set__rssi(
    const uint8_t & _arg)
  {
    this->rssi = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__RCChannels
    std::shared_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__RCChannels
    std::shared_ptr<vbn_ros_msgs::msg::RCChannels_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RCChannels_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->chancount != other.chancount) {
      return false;
    }
    if (this->chan1_raw != other.chan1_raw) {
      return false;
    }
    if (this->chan2_raw != other.chan2_raw) {
      return false;
    }
    if (this->chan3_raw != other.chan3_raw) {
      return false;
    }
    if (this->chan4_raw != other.chan4_raw) {
      return false;
    }
    if (this->chan5_raw != other.chan5_raw) {
      return false;
    }
    if (this->chan6_raw != other.chan6_raw) {
      return false;
    }
    if (this->chan7_raw != other.chan7_raw) {
      return false;
    }
    if (this->chan8_raw != other.chan8_raw) {
      return false;
    }
    if (this->chan9_raw != other.chan9_raw) {
      return false;
    }
    if (this->chan10_raw != other.chan10_raw) {
      return false;
    }
    if (this->chan11_raw != other.chan11_raw) {
      return false;
    }
    if (this->chan12_raw != other.chan12_raw) {
      return false;
    }
    if (this->chan13_raw != other.chan13_raw) {
      return false;
    }
    if (this->chan14_raw != other.chan14_raw) {
      return false;
    }
    if (this->chan15_raw != other.chan15_raw) {
      return false;
    }
    if (this->chan16_raw != other.chan16_raw) {
      return false;
    }
    if (this->chan17_raw != other.chan17_raw) {
      return false;
    }
    if (this->chan18_raw != other.chan18_raw) {
      return false;
    }
    if (this->rssi != other.rssi) {
      return false;
    }
    return true;
  }
  bool operator!=(const RCChannels_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RCChannels_

// alias to use template instance with default allocator
using RCChannels =
  vbn_ros_msgs::msg::RCChannels_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RC_CHANNELS__STRUCT_HPP_
