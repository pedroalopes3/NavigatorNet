// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/GlobalPositionInt.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__GlobalPositionInt __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__GlobalPositionInt __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GlobalPositionInt_
{
  using Type = GlobalPositionInt_<ContainerAllocator>;

  explicit GlobalPositionInt_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->lat = 0l;
      this->lon = 0l;
      this->alt = 0l;
      this->relative_alt = 0l;
      this->vx = 0;
      this->vy = 0;
      this->vz = 0;
      this->hdg = 0;
    }
  }

  explicit GlobalPositionInt_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->lat = 0l;
      this->lon = 0l;
      this->alt = 0l;
      this->relative_alt = 0l;
      this->vx = 0;
      this->vy = 0;
      this->vz = 0;
      this->hdg = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _lat_type =
    int32_t;
  _lat_type lat;
  using _lon_type =
    int32_t;
  _lon_type lon;
  using _alt_type =
    int32_t;
  _alt_type alt;
  using _relative_alt_type =
    int32_t;
  _relative_alt_type relative_alt;
  using _vx_type =
    int16_t;
  _vx_type vx;
  using _vy_type =
    int16_t;
  _vy_type vy;
  using _vz_type =
    int16_t;
  _vz_type vz;
  using _hdg_type =
    uint16_t;
  _hdg_type hdg;

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
  Type & set__lat(
    const int32_t & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lon(
    const int32_t & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__alt(
    const int32_t & _arg)
  {
    this->alt = _arg;
    return *this;
  }
  Type & set__relative_alt(
    const int32_t & _arg)
  {
    this->relative_alt = _arg;
    return *this;
  }
  Type & set__vx(
    const int16_t & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const int16_t & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const int16_t & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__hdg(
    const uint16_t & _arg)
  {
    this->hdg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__GlobalPositionInt
    std::shared_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__GlobalPositionInt
    std::shared_ptr<vbn_ros_msgs::msg::GlobalPositionInt_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GlobalPositionInt_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->alt != other.alt) {
      return false;
    }
    if (this->relative_alt != other.relative_alt) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->hdg != other.hdg) {
      return false;
    }
    return true;
  }
  bool operator!=(const GlobalPositionInt_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GlobalPositionInt_

// alias to use template instance with default allocator
using GlobalPositionInt =
  vbn_ros_msgs::msg::GlobalPositionInt_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__GLOBAL_POSITION_INT__STRUCT_HPP_
