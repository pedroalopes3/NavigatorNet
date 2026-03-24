// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/EKFStatusReport.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__EKFStatusReport __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__EKFStatusReport __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EKFStatusReport_
{
  using Type = EKFStatusReport_<ContainerAllocator>;

  explicit EKFStatusReport_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->velocity_variance = 0.0f;
      this->pos_horiz_variance = 0.0f;
      this->pos_vert_variance = 0.0f;
      this->compass_variance = 0.0f;
      this->terrain_alt_variance = 0.0f;
      this->airspeed_variance = 0.0f;
    }
  }

  explicit EKFStatusReport_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->velocity_variance = 0.0f;
      this->pos_horiz_variance = 0.0f;
      this->pos_vert_variance = 0.0f;
      this->compass_variance = 0.0f;
      this->terrain_alt_variance = 0.0f;
      this->airspeed_variance = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _velocity_variance_type =
    float;
  _velocity_variance_type velocity_variance;
  using _pos_horiz_variance_type =
    float;
  _pos_horiz_variance_type pos_horiz_variance;
  using _pos_vert_variance_type =
    float;
  _pos_vert_variance_type pos_vert_variance;
  using _compass_variance_type =
    float;
  _compass_variance_type compass_variance;
  using _terrain_alt_variance_type =
    float;
  _terrain_alt_variance_type terrain_alt_variance;
  using _airspeed_variance_type =
    float;
  _airspeed_variance_type airspeed_variance;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__velocity_variance(
    const float & _arg)
  {
    this->velocity_variance = _arg;
    return *this;
  }
  Type & set__pos_horiz_variance(
    const float & _arg)
  {
    this->pos_horiz_variance = _arg;
    return *this;
  }
  Type & set__pos_vert_variance(
    const float & _arg)
  {
    this->pos_vert_variance = _arg;
    return *this;
  }
  Type & set__compass_variance(
    const float & _arg)
  {
    this->compass_variance = _arg;
    return *this;
  }
  Type & set__terrain_alt_variance(
    const float & _arg)
  {
    this->terrain_alt_variance = _arg;
    return *this;
  }
  Type & set__airspeed_variance(
    const float & _arg)
  {
    this->airspeed_variance = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t EKF_ATTITUDE =
    1u;
  static constexpr uint16_t EKF_VELOCITY_HORIZ =
    2u;
  static constexpr uint16_t EKF_VELOCITY_VERT =
    4u;
  static constexpr uint16_t EKF_POS_HORIZ_REL =
    8u;
  static constexpr uint16_t EKF_POS_HORIZ_ABS =
    16u;
  static constexpr uint16_t EKF_POS_VERT_ABS =
    32u;
  static constexpr uint16_t EKF_POS_VERT_AGL =
    64u;
  static constexpr uint16_t EKF_CONST_POS_MODE =
    128u;
  static constexpr uint16_t EKF_PRED_POS_HORIZ_REL =
    256u;
  static constexpr uint16_t EKF_PRED_POS_HORIZ_ABS =
    512u;
  static constexpr uint16_t EKF_UNINITIALIZED =
    1024u;
  static constexpr uint16_t EKF_GPS_GLITCHING =
    32768u;

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__EKFStatusReport
    std::shared_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__EKFStatusReport
    std::shared_ptr<vbn_ros_msgs::msg::EKFStatusReport_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EKFStatusReport_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->velocity_variance != other.velocity_variance) {
      return false;
    }
    if (this->pos_horiz_variance != other.pos_horiz_variance) {
      return false;
    }
    if (this->pos_vert_variance != other.pos_vert_variance) {
      return false;
    }
    if (this->compass_variance != other.compass_variance) {
      return false;
    }
    if (this->terrain_alt_variance != other.terrain_alt_variance) {
      return false;
    }
    if (this->airspeed_variance != other.airspeed_variance) {
      return false;
    }
    return true;
  }
  bool operator!=(const EKFStatusReport_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EKFStatusReport_

// alias to use template instance with default allocator
using EKFStatusReport =
  vbn_ros_msgs::msg::EKFStatusReport_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_ATTITUDE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_VELOCITY_HORIZ;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_VELOCITY_VERT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_POS_HORIZ_REL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_POS_HORIZ_ABS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_POS_VERT_ABS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_POS_VERT_AGL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_CONST_POS_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_PRED_POS_HORIZ_REL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_PRED_POS_HORIZ_ABS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_UNINITIALIZED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t EKFStatusReport_<ContainerAllocator>::EKF_GPS_GLITCHING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__EKF_STATUS_REPORT__STRUCT_HPP_
