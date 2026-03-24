// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/AOASSA.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__AOASSA __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__AOASSA __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AOASSA_
{
  using Type = AOASSA_<ContainerAllocator>;

  explicit AOASSA_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_usec = 0ull;
      this->aoa = 0.0f;
      this->ssa = 0.0f;
    }
  }

  explicit AOASSA_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_usec = 0ull;
      this->aoa = 0.0f;
      this->ssa = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_usec_type =
    uint64_t;
  _time_usec_type time_usec;
  using _aoa_type =
    float;
  _aoa_type aoa;
  using _ssa_type =
    float;
  _ssa_type ssa;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time_usec(
    const uint64_t & _arg)
  {
    this->time_usec = _arg;
    return *this;
  }
  Type & set__aoa(
    const float & _arg)
  {
    this->aoa = _arg;
    return *this;
  }
  Type & set__ssa(
    const float & _arg)
  {
    this->ssa = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__AOASSA
    std::shared_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__AOASSA
    std::shared_ptr<vbn_ros_msgs::msg::AOASSA_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AOASSA_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_usec != other.time_usec) {
      return false;
    }
    if (this->aoa != other.aoa) {
      return false;
    }
    if (this->ssa != other.ssa) {
      return false;
    }
    return true;
  }
  bool operator!=(const AOASSA_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AOASSA_

// alias to use template instance with default allocator
using AOASSA =
  vbn_ros_msgs::msg::AOASSA_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AOASSA__STRUCT_HPP_
