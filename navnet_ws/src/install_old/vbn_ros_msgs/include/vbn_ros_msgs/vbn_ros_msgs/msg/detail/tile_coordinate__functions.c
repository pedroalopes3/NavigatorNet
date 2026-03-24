// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/TileCoordinate.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/tile_coordinate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `source_type`
#include "rosidl_runtime_c/string_functions.h"

bool
vbn_ros_msgs__msg__TileCoordinate__init(vbn_ros_msgs__msg__TileCoordinate * msg)
{
  if (!msg) {
    return false;
  }
  // z
  // x
  // y
  // similarity_score
  // source_type
  if (!rosidl_runtime_c__String__init(&msg->source_type)) {
    vbn_ros_msgs__msg__TileCoordinate__fini(msg);
    return false;
  }
  return true;
}

void
vbn_ros_msgs__msg__TileCoordinate__fini(vbn_ros_msgs__msg__TileCoordinate * msg)
{
  if (!msg) {
    return;
  }
  // z
  // x
  // y
  // similarity_score
  // source_type
  rosidl_runtime_c__String__fini(&msg->source_type);
}

bool
vbn_ros_msgs__msg__TileCoordinate__are_equal(const vbn_ros_msgs__msg__TileCoordinate * lhs, const vbn_ros_msgs__msg__TileCoordinate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // similarity_score
  if (lhs->similarity_score != rhs->similarity_score) {
    return false;
  }
  // source_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source_type), &(rhs->source_type)))
  {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__TileCoordinate__copy(
  const vbn_ros_msgs__msg__TileCoordinate * input,
  vbn_ros_msgs__msg__TileCoordinate * output)
{
  if (!input || !output) {
    return false;
  }
  // z
  output->z = input->z;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // similarity_score
  output->similarity_score = input->similarity_score;
  // source_type
  if (!rosidl_runtime_c__String__copy(
      &(input->source_type), &(output->source_type)))
  {
    return false;
  }
  return true;
}

vbn_ros_msgs__msg__TileCoordinate *
vbn_ros_msgs__msg__TileCoordinate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__TileCoordinate * msg = (vbn_ros_msgs__msg__TileCoordinate *)allocator.allocate(sizeof(vbn_ros_msgs__msg__TileCoordinate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__TileCoordinate));
  bool success = vbn_ros_msgs__msg__TileCoordinate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__TileCoordinate__destroy(vbn_ros_msgs__msg__TileCoordinate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__TileCoordinate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__TileCoordinate__Sequence__init(vbn_ros_msgs__msg__TileCoordinate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__TileCoordinate * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__TileCoordinate *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__TileCoordinate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__TileCoordinate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__TileCoordinate__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vbn_ros_msgs__msg__TileCoordinate__Sequence__fini(vbn_ros_msgs__msg__TileCoordinate__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vbn_ros_msgs__msg__TileCoordinate__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vbn_ros_msgs__msg__TileCoordinate__Sequence *
vbn_ros_msgs__msg__TileCoordinate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__TileCoordinate__Sequence * array = (vbn_ros_msgs__msg__TileCoordinate__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__TileCoordinate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__TileCoordinate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__TileCoordinate__Sequence__destroy(vbn_ros_msgs__msg__TileCoordinate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__TileCoordinate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__TileCoordinate__Sequence__are_equal(const vbn_ros_msgs__msg__TileCoordinate__Sequence * lhs, const vbn_ros_msgs__msg__TileCoordinate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__TileCoordinate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__TileCoordinate__Sequence__copy(
  const vbn_ros_msgs__msg__TileCoordinate__Sequence * input,
  vbn_ros_msgs__msg__TileCoordinate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__TileCoordinate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__TileCoordinate * data =
      (vbn_ros_msgs__msg__TileCoordinate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__TileCoordinate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__TileCoordinate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__TileCoordinate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
