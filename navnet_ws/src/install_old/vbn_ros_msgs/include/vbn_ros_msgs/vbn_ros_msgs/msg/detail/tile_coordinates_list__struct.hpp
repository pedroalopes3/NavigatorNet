// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/TileCoordinatesList.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_HPP_

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
// Member 'coordinates'
#include "vbn_ros_msgs/msg/detail/tile_coordinate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vbn_ros_msgs__msg__TileCoordinatesList __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__TileCoordinatesList __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TileCoordinatesList_
{
  using Type = TileCoordinatesList_<ContainerAllocator>;

  explicit TileCoordinatesList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_elevation = 0.0f;
    }
  }

  explicit TileCoordinatesList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_elevation = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mode_elevation_type =
    float;
  _mode_elevation_type mode_elevation;
  using _coordinates_type =
    std::vector<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>>;
  _coordinates_type coordinates;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mode_elevation(
    const float & _arg)
  {
    this->mode_elevation = _arg;
    return *this;
  }
  Type & set__coordinates(
    const std::vector<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vbn_ros_msgs::msg::TileCoordinate_<ContainerAllocator>>> & _arg)
  {
    this->coordinates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__TileCoordinatesList
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__TileCoordinatesList
    std::shared_ptr<vbn_ros_msgs::msg::TileCoordinatesList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TileCoordinatesList_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mode_elevation != other.mode_elevation) {
      return false;
    }
    if (this->coordinates != other.coordinates) {
      return false;
    }
    return true;
  }
  bool operator!=(const TileCoordinatesList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TileCoordinatesList_

// alias to use template instance with default allocator
using TileCoordinatesList =
  vbn_ros_msgs::msg::TileCoordinatesList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__TILE_COORDINATES_LIST__STRUCT_HPP_
