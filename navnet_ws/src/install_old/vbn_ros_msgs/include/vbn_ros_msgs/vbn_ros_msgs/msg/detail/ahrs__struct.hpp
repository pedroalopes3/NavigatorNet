// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/AHRS.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__AHRS __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__AHRS __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AHRS_
{
  using Type = AHRS_<ContainerAllocator>;

  explicit AHRS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->omega_ix = 0.0f;
      this->omega_iy = 0.0f;
      this->omega_iz = 0.0f;
      this->accel_weight = 0.0f;
      this->renorm_val = 0.0f;
      this->error_rp = 0.0f;
      this->error_yaw = 0.0f;
    }
  }

  explicit AHRS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->omega_ix = 0.0f;
      this->omega_iy = 0.0f;
      this->omega_iz = 0.0f;
      this->accel_weight = 0.0f;
      this->renorm_val = 0.0f;
      this->error_rp = 0.0f;
      this->error_yaw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _omega_ix_type =
    float;
  _omega_ix_type omega_ix;
  using _omega_iy_type =
    float;
  _omega_iy_type omega_iy;
  using _omega_iz_type =
    float;
  _omega_iz_type omega_iz;
  using _accel_weight_type =
    float;
  _accel_weight_type accel_weight;
  using _renorm_val_type =
    float;
  _renorm_val_type renorm_val;
  using _error_rp_type =
    float;
  _error_rp_type error_rp;
  using _error_yaw_type =
    float;
  _error_yaw_type error_yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__omega_ix(
    const float & _arg)
  {
    this->omega_ix = _arg;
    return *this;
  }
  Type & set__omega_iy(
    const float & _arg)
  {
    this->omega_iy = _arg;
    return *this;
  }
  Type & set__omega_iz(
    const float & _arg)
  {
    this->omega_iz = _arg;
    return *this;
  }
  Type & set__accel_weight(
    const float & _arg)
  {
    this->accel_weight = _arg;
    return *this;
  }
  Type & set__renorm_val(
    const float & _arg)
  {
    this->renorm_val = _arg;
    return *this;
  }
  Type & set__error_rp(
    const float & _arg)
  {
    this->error_rp = _arg;
    return *this;
  }
  Type & set__error_yaw(
    const float & _arg)
  {
    this->error_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::AHRS_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::AHRS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::AHRS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::AHRS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__AHRS
    std::shared_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__AHRS
    std::shared_ptr<vbn_ros_msgs::msg::AHRS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AHRS_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->omega_ix != other.omega_ix) {
      return false;
    }
    if (this->omega_iy != other.omega_iy) {
      return false;
    }
    if (this->omega_iz != other.omega_iz) {
      return false;
    }
    if (this->accel_weight != other.accel_weight) {
      return false;
    }
    if (this->renorm_val != other.renorm_val) {
      return false;
    }
    if (this->error_rp != other.error_rp) {
      return false;
    }
    if (this->error_yaw != other.error_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const AHRS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AHRS_

// alias to use template instance with default allocator
using AHRS =
  vbn_ros_msgs::msg::AHRS_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__AHRS__STRUCT_HPP_
