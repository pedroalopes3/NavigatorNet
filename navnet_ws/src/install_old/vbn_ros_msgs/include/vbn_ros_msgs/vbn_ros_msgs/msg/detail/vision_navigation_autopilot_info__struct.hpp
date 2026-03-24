// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_HPP_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_HPP_

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
# define DEPRECATED__vbn_ros_msgs__msg__VisionNavigationAutopilotInfo __attribute__((deprecated))
#else
# define DEPRECATED__vbn_ros_msgs__msg__VisionNavigationAutopilotInfo __declspec(deprecated)
#endif

namespace vbn_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisionNavigationAutopilotInfo_
{
  using Type = VisionNavigationAutopilotInfo_<ContainerAllocator>;

  explicit VisionNavigationAutopilotInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_msec = 0ul;
      this->alarms = 0;
      this->lat = 0.0f;
      this->lng = 0.0f;
      this->alt_msl = 0.0f;
      this->pos_variance_x = 0.0f;
      this->pos_variance_y = 0.0f;
      this->pos_variance_z = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit VisionNavigationAutopilotInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_msec = 0ul;
      this->alarms = 0;
      this->lat = 0.0f;
      this->lng = 0.0f;
      this->alt_msl = 0.0f;
      this->pos_variance_x = 0.0f;
      this->pos_variance_y = 0.0f;
      this->pos_variance_z = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _time_msec_type =
    uint32_t;
  _time_msec_type time_msec;
  using _alarms_type =
    uint8_t;
  _alarms_type alarms;
  using _lat_type =
    float;
  _lat_type lat;
  using _lng_type =
    float;
  _lng_type lng;
  using _alt_msl_type =
    float;
  _alt_msl_type alt_msl;
  using _pos_variance_x_type =
    float;
  _pos_variance_x_type pos_variance_x;
  using _pos_variance_y_type =
    float;
  _pos_variance_y_type pos_variance_y;
  using _pos_variance_z_type =
    float;
  _pos_variance_z_type pos_variance_z;
  using _vx_type =
    float;
  _vx_type vx;
  using _vy_type =
    float;
  _vy_type vy;
  using _vz_type =
    float;
  _vz_type vz;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__time_msec(
    const uint32_t & _arg)
  {
    this->time_msec = _arg;
    return *this;
  }
  Type & set__alarms(
    const uint8_t & _arg)
  {
    this->alarms = _arg;
    return *this;
  }
  Type & set__lat(
    const float & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lng(
    const float & _arg)
  {
    this->lng = _arg;
    return *this;
  }
  Type & set__alt_msl(
    const float & _arg)
  {
    this->alt_msl = _arg;
    return *this;
  }
  Type & set__pos_variance_x(
    const float & _arg)
  {
    this->pos_variance_x = _arg;
    return *this;
  }
  Type & set__pos_variance_y(
    const float & _arg)
  {
    this->pos_variance_y = _arg;
    return *this;
  }
  Type & set__pos_variance_z(
    const float & _arg)
  {
    this->pos_variance_z = _arg;
    return *this;
  }
  Type & set__vx(
    const float & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const float & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const float & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN =
    0u;
  static constexpr uint8_t VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING =
    1u;
  static constexpr uint8_t VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS =
    2u;
  static constexpr uint8_t VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING =
    4u;

  // pointer types
  using RawPtr =
    vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vbn_ros_msgs__msg__VisionNavigationAutopilotInfo
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vbn_ros_msgs__msg__VisionNavigationAutopilotInfo
    std::shared_ptr<vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionNavigationAutopilotInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->time_msec != other.time_msec) {
      return false;
    }
    if (this->alarms != other.alarms) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lng != other.lng) {
      return false;
    }
    if (this->alt_msl != other.alt_msl) {
      return false;
    }
    if (this->pos_variance_x != other.pos_variance_x) {
      return false;
    }
    if (this->pos_variance_y != other.pos_variance_y) {
      return false;
    }
    if (this->pos_variance_z != other.pos_variance_z) {
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
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionNavigationAutopilotInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionNavigationAutopilotInfo_

// alias to use template instance with default allocator
using VisionNavigationAutopilotInfo =
  vbn_ros_msgs::msg::VisionNavigationAutopilotInfo_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationAutopilotInfo_<ContainerAllocator>::VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationAutopilotInfo_<ContainerAllocator>::VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationAutopilotInfo_<ContainerAllocator>::VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VisionNavigationAutopilotInfo_<ContainerAllocator>::VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace vbn_ros_msgs

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_AUTOPILOT_INFO__STRUCT_HPP_
