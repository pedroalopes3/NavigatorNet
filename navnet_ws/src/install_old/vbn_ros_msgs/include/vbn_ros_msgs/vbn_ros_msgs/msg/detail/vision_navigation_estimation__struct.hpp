// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/VisionNavigationEstimation.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__STRUCT_HPP_

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
// Member 'position'
#include "geographic_msgs/msg/detail/geo_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vbn_ros_msgs__msg__VisionNavigationEstimation __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__VisionNavigationEstimation __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisionNavigationEstimation_
{
  using Type = VisionNavigationEstimation_<ContainerAllocator>;

  explicit VisionNavigationEstimation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->pos_error = 0.0f;
    }
  }

  explicit VisionNavigationEstimation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flags = 0;
      this->pos_error = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _position_type =
    geographic_msgs::msg::GeoPoint_<ContainerAllocator>;
  _position_type position;
  using _flags_type =
    uint8_t;
  _flags_type flags;
  using _pos_error_type =
    float;
  _pos_error_type pos_error;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__position(
    const geographic_msgs::msg::GeoPoint_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__flags(
    const uint8_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__pos_error(
    const float & _arg)
  {
    this->pos_error = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t NAVIGATION_ESTIMATION_FLAGS_UNKNOWN =
    0u;
  static constexpr uint8_t NAVIGATION_ESTIMATION_FLAGS_OK =
    1u;
  static constexpr uint8_t NAVIGATION_ESTIMATION_FLAGS_ABS_OK =
    2u;

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__VisionNavigationEstimation
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__VisionNavigationEstimation
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationEstimation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionNavigationEstimation_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->pos_error != other.pos_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionNavigationEstimation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionNavigationEstimation_

// alias to use template instance with default allocator
using VisionNavigationEstimation =
  vbn_ros_msgs::msg::VisionNavigationEstimation_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationEstimation_<ContainerAllocator>::NAVIGATION_ESTIMATION_FLAGS_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationEstimation_<ContainerAllocator>::NAVIGATION_ESTIMATION_FLAGS_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationEstimation_<ContainerAllocator>::NAVIGATION_ESTIMATION_FLAGS_ABS_OK;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__STRUCT_HPP_
