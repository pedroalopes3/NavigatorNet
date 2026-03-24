// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vbn_ros_msgs:msg/VisionNavigationEstimation.idl
// generated code does not contain a copyright notice

#ifndef VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__FUNCTIONS_H_
#define VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vbn_ros_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vbn_ros_msgs/msg/detail/vision_navigation_estimation__struct.h"

/// Initialize msg/VisionNavigationEstimation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vbn_ros_msgs__msg__VisionNavigationEstimation
 * )) before or use
 * vbn_ros_msgs__msg__VisionNavigationEstimation__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__init(vbn_ros_msgs__msg__VisionNavigationEstimation * msg);

/// Finalize msg/VisionNavigationEstimation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
void
vbn_ros_msgs__msg__VisionNavigationEstimation__fini(vbn_ros_msgs__msg__VisionNavigationEstimation * msg);

/// Create msg/VisionNavigationEstimation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
vbn_ros_msgs__msg__VisionNavigationEstimation *
vbn_ros_msgs__msg__VisionNavigationEstimation__create();

/// Destroy msg/VisionNavigationEstimation message.
/**
 * It calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
void
vbn_ros_msgs__msg__VisionNavigationEstimation__destroy(vbn_ros_msgs__msg__VisionNavigationEstimation * msg);

/// Check for msg/VisionNavigationEstimation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__are_equal(const vbn_ros_msgs__msg__VisionNavigationEstimation * lhs, const vbn_ros_msgs__msg__VisionNavigationEstimation * rhs);

/// Copy a msg/VisionNavigationEstimation message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__copy(
  const vbn_ros_msgs__msg__VisionNavigationEstimation * input,
  vbn_ros_msgs__msg__VisionNavigationEstimation * output);

/// Initialize array of msg/VisionNavigationEstimation messages.
/**
 * It allocates the memory for the number of elements and calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__init(vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * array, size_t size);

/// Finalize array of msg/VisionNavigationEstimation messages.
/**
 * It calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
void
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__fini(vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * array);

/// Create array of msg/VisionNavigationEstimation messages.
/**
 * It allocates the memory for the array and calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence *
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__create(size_t size);

/// Destroy array of msg/VisionNavigationEstimation messages.
/**
 * It calls
 * vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
void
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__destroy(vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * array);

/// Check for msg/VisionNavigationEstimation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__are_equal(const vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * lhs, const vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * rhs);

/// Copy an array of msg/VisionNavigationEstimation messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vbn_ros_msgs
bool
vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence__copy(
  const vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * input,
  vbn_ros_msgs__msg__VisionNavigationEstimation__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VBN_ROS_MSGS__MSG__DETAIL__VISION_NAVIGATION_ESTIMATION__FUNCTIONS_H_
