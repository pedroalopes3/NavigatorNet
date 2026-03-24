// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vbn_ros_msgs:msg/TileCoordinatesList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vbn_ros_msgs/msg/detail/tile_coordinates_list__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vbn_ros_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TileCoordinatesList_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vbn_ros_msgs::msg::TileCoordinatesList(_init);
}

void TileCoordinatesList_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vbn_ros_msgs::msg::TileCoordinatesList *>(message_memory);
  typed_message->~TileCoordinatesList();
}

size_t size_function__TileCoordinatesList__coordinates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vbn_ros_msgs::msg::TileCoordinate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TileCoordinatesList__coordinates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vbn_ros_msgs::msg::TileCoordinate> *>(untyped_member);
  return &member[index];
}

void * get_function__TileCoordinatesList__coordinates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vbn_ros_msgs::msg::TileCoordinate> *>(untyped_member);
  return &member[index];
}

void fetch_function__TileCoordinatesList__coordinates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vbn_ros_msgs::msg::TileCoordinate *>(
    get_const_function__TileCoordinatesList__coordinates(untyped_member, index));
  auto & value = *reinterpret_cast<vbn_ros_msgs::msg::TileCoordinate *>(untyped_value);
  value = item;
}

void assign_function__TileCoordinatesList__coordinates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vbn_ros_msgs::msg::TileCoordinate *>(
    get_function__TileCoordinatesList__coordinates(untyped_member, index));
  const auto & value = *reinterpret_cast<const vbn_ros_msgs::msg::TileCoordinate *>(untyped_value);
  item = value;
}

void resize_function__TileCoordinatesList__coordinates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vbn_ros_msgs::msg::TileCoordinate> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TileCoordinatesList_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs::msg::TileCoordinatesList, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode_elevation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs::msg::TileCoordinatesList, mode_elevation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "coordinates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vbn_ros_msgs::msg::TileCoordinate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vbn_ros_msgs::msg::TileCoordinatesList, coordinates),  // bytes offset in struct
    nullptr,  // default value
    size_function__TileCoordinatesList__coordinates,  // size() function pointer
    get_const_function__TileCoordinatesList__coordinates,  // get_const(index) function pointer
    get_function__TileCoordinatesList__coordinates,  // get(index) function pointer
    fetch_function__TileCoordinatesList__coordinates,  // fetch(index, &value) function pointer
    assign_function__TileCoordinatesList__coordinates,  // assign(index, value) function pointer
    resize_function__TileCoordinatesList__coordinates  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TileCoordinatesList_message_members = {
  "vbn_ros_msgs::msg",  // message namespace
  "TileCoordinatesList",  // message name
  3,  // number of fields
  sizeof(vbn_ros_msgs::msg::TileCoordinatesList),
  TileCoordinatesList_message_member_array,  // message members
  TileCoordinatesList_init_function,  // function to initialize message memory (memory has to be allocated)
  TileCoordinatesList_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TileCoordinatesList_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TileCoordinatesList_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vbn_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vbn_ros_msgs::msg::TileCoordinatesList>()
{
  return &::vbn_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TileCoordinatesList_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vbn_ros_msgs, msg, TileCoordinatesList)() {
  return &::vbn_ros_msgs::msg::rosidl_typesupport_introspection_cpp::TileCoordinatesList_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
