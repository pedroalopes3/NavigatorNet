// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vbn_ros_msgs__msg__TileCoordinate __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__TileCoordinate __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TileCoordinate_
{
  using Type = TileCoordinate_<ContainerAllocator>;

  explicit TileCoordinate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->z = 0l;
      this->x = 0l;
      this->y = 0l;
      this->similarity_score = 0.0;
      this->source_type = "";
    }
  }

  explicit TileCoordinate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : source_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->z = 0l;
      this->x = 0l;
      this->y = 0l;
      this->similarity_score = 0.0;
      this->source_type = "";
    }
  }

  // field types and members
  using _z_type =
    int32_t;
  _z_type z;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _similarity_score_type =
    double;
  _similarity_score_type similarity_score;
  using _source_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type_type source_type;

  // setters for named parameter idiom
  Type & set__z(
    const int32_t & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__similarity_score(
    const double & _arg)
  {
    this->similarity_score = _arg;
    return *this;
  }
  Type & set__source_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__TileCoordinate
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__TileCoordinate
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TileCoordinate_ & other) const
  {
    if (this->z != other.z) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->similarity_score != other.similarity_score) {
      return false;
    }
    if (this->source_type != other.source_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const TileCoordinate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TileCoordinate_

// alias to use template instance with default allocator
using TileCoordinate =
  vbn_ros_msgs::msg::TileCoordinate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATE__STRUCT_HPP_
