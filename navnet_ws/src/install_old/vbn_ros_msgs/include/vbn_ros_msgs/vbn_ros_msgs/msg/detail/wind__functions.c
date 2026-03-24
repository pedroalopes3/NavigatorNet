// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/Wind.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/wind__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
vbn_ros_msgs__msg__Wind__init(vbn_ros_msgs__msg__Wind * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vbn_ros_msgs__msg__Wind__fini(msg);
    return false;
  }
  // direction
  // speed
  // speed_z
  return true;
}

void
vbn_ros_msgs__msg__Wind__fini(vbn_ros_msgs__msg__Wind * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // direction
  // speed
  // speed_z
}

bool
vbn_ros_msgs__msg__Wind__are_equal(const vbn_ros_msgs__msg__Wind * lhs, const vbn_ros_msgs__msg__Wind * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // direction
  if (lhs->direction != rhs->direction) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // speed_z
  if (lhs->speed_z != rhs->speed_z) {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__Wind__copy(
  const vbn_ros_msgs__msg__Wind * input,
  vbn_ros_msgs__msg__Wind * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // direction
  output->direction = input->direction;
  // speed
  output->speed = input->speed;
  // speed_z
  output->speed_z = input->speed_z;
  return true;
}

vbn_ros_msgs__msg__Wind *
vbn_ros_msgs__msg__Wind__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__Wind * msg = (vbn_ros_msgs__msg__Wind *)allocator.allocate(sizeof(vbn_ros_msgs__msg__Wind), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__Wind));
  bool success = vbn_ros_msgs__msg__Wind__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__Wind__destroy(vbn_ros_msgs__msg__Wind * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__Wind__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__Wind__Sequence__init(vbn_ros_msgs__msg__Wind__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__Wind * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__Wind *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__Wind), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__Wind__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__Wind__fini(&data[i - 1]);
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
vbn_ros_msgs__msg__Wind__Sequence__fini(vbn_ros_msgs__msg__Wind__Sequence * array)
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
      vbn_ros_msgs__msg__Wind__fini(&array->data[i]);
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

vbn_ros_msgs__msg__Wind__Sequence *
vbn_ros_msgs__msg__Wind__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__Wind__Sequence * array = (vbn_ros_msgs__msg__Wind__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__Wind__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__Wind__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__Wind__Sequence__destroy(vbn_ros_msgs__msg__Wind__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__Wind__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__Wind__Sequence__are_equal(const vbn_ros_msgs__msg__Wind__Sequence * lhs, const vbn_ros_msgs__msg__Wind__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__Wind__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__Wind__Sequence__copy(
  const vbn_ros_msgs__msg__Wind__Sequence * input,
  vbn_ros_msgs__msg__Wind__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__Wind);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__Wind * data =
      (vbn_ros_msgs__msg__Wind *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__Wind__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__Wind__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__Wind__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
