// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/RawIMU.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__RawIMU __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__RawIMU __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RawIMU_
{
  using Type = RawIMU_<ContainerAllocator>;

  explicit RawIMU_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_usec = 0ull;
      this->xacc = 0;
      this->yacc = 0;
      this->zacc = 0;
      this->xgyro = 0;
      this->ygyro = 0;
      this->zgyro = 0;
      this->xmag = 0;
      this->ymag = 0;
      this->zmag = 0;
      this->id = 0;
      this->temperature = 0;
    }
  }

  explicit RawIMU_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_usec = 0ull;
      this->xacc = 0;
      this->yacc = 0;
      this->zacc = 0;
      this->xgyro = 0;
      this->ygyro = 0;
      this->zgyro = 0;
      this->xmag = 0;
      this->ymag = 0;
      this->zmag = 0;
      this->id = 0;
      this->temperature = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_usec_type =
    uint64_t;
  _time_usec_type time_usec;
  using _xacc_type =
    int16_t;
  _xacc_type xacc;
  using _yacc_type =
    int16_t;
  _yacc_type yacc;
  using _zacc_type =
    int16_t;
  _zacc_type zacc;
  using _xgyro_type =
    int16_t;
  _xgyro_type xgyro;
  using _ygyro_type =
    int16_t;
  _ygyro_type ygyro;
  using _zgyro_type =
    int16_t;
  _zgyro_type zgyro;
  using _xmag_type =
    int16_t;
  _xmag_type xmag;
  using _ymag_type =
    int16_t;
  _ymag_type ymag;
  using _zmag_type =
    int16_t;
  _zmag_type zmag;
  using _id_type =
    uint8_t;
  _id_type id;
  using _temperature_type =
    int16_t;
  _temperature_type temperature;

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
  Type & set__xacc(
    const int16_t & _arg)
  {
    this->xacc = _arg;
    return *this;
  }
  Type & set__yacc(
    const int16_t & _arg)
  {
    this->yacc = _arg;
    return *this;
  }
  Type & set__zacc(
    const int16_t & _arg)
  {
    this->zacc = _arg;
    return *this;
  }
  Type & set__xgyro(
    const int16_t & _arg)
  {
    this->xgyro = _arg;
    return *this;
  }
  Type & set__ygyro(
    const int16_t & _arg)
  {
    this->ygyro = _arg;
    return *this;
  }
  Type & set__zgyro(
    const int16_t & _arg)
  {
    this->zgyro = _arg;
    return *this;
  }
  Type & set__xmag(
    const int16_t & _arg)
  {
    this->xmag = _arg;
    return *this;
  }
  Type & set__ymag(
    const int16_t & _arg)
  {
    this->ymag = _arg;
    return *this;
  }
  Type & set__zmag(
    const int16_t & _arg)
  {
    this->zmag = _arg;
    return *this;
  }
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__temperature(
    const int16_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__RawIMU
    std::shared_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__RawIMU
    std::shared_ptr<vbn_ros_msgs::msg::RawIMU_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RawIMU_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_usec != other.time_usec) {
      return false;
    }
    if (this->xacc != other.xacc) {
      return false;
    }
    if (this->yacc != other.yacc) {
      return false;
    }
    if (this->zacc != other.zacc) {
      return false;
    }
    if (this->xgyro != other.xgyro) {
      return false;
    }
    if (this->ygyro != other.ygyro) {
      return false;
    }
    if (this->zgyro != other.zgyro) {
      return false;
    }
    if (this->xmag != other.xmag) {
      return false;
    }
    if (this->ymag != other.ymag) {
      return false;
    }
    if (this->zmag != other.zmag) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const RawIMU_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RawIMU_

// alias to use template instance with default allocator
using RawIMU =
  vbn_ros_msgs::msg::RawIMU_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__RAW_IMU__STRUCT_HPP_
