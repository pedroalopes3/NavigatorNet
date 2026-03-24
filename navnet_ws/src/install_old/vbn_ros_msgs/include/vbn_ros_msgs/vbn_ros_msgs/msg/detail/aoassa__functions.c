// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/AOASSA.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/aoassa__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
vbn_ros_msgs__msg__AOASSA__init(vbn_ros_msgs__msg__AOASSA * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vbn_ros_msgs__msg__AOASSA__fini(msg);
    return false;
  }
  // time_usec
  // aoa
  // ssa
  return true;
}

void
vbn_ros_msgs__msg__AOASSA__fini(vbn_ros_msgs__msg__AOASSA * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time_usec
  // aoa
  // ssa
}

bool
vbn_ros_msgs__msg__AOASSA__are_equal(const vbn_ros_msgs__msg__AOASSA * lhs, const vbn_ros_msgs__msg__AOASSA * rhs)
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
  // time_usec
  if (lhs->time_usec != rhs->time_usec) {
    return false;
  }
  // aoa
  if (lhs->aoa != rhs->aoa) {
    return false;
  }
  // ssa
  if (lhs->ssa != rhs->ssa) {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__AOASSA__copy(
  const vbn_ros_msgs__msg__AOASSA * input,
  vbn_ros_msgs__msg__AOASSA * output)
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
  // time_usec
  output->time_usec = input->time_usec;
  // aoa
  output->aoa = input->aoa;
  // ssa
  output->ssa = input->ssa;
  return true;
}

vbn_ros_msgs__msg__AOASSA *
vbn_ros_msgs__msg__AOASSA__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__AOASSA * msg = (vbn_ros_msgs__msg__AOASSA *)allocator.allocate(sizeof(vbn_ros_msgs__msg__AOASSA), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__AOASSA));
  bool success = vbn_ros_msgs__msg__AOASSA__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__AOASSA__destroy(vbn_ros_msgs__msg__AOASSA * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__AOASSA__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__AOASSA__Sequence__init(vbn_ros_msgs__msg__AOASSA__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__AOASSA * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__AOASSA *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__AOASSA), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__AOASSA__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__AOASSA__fini(&data[i - 1]);
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
vbn_ros_msgs__msg__AOASSA__Sequence__fini(vbn_ros_msgs__msg__AOASSA__Sequence * array)
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
      vbn_ros_msgs__msg__AOASSA__fini(&array->data[i]);
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

vbn_ros_msgs__msg__AOASSA__Sequence *
vbn_ros_msgs__msg__AOASSA__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__AOASSA__Sequence * array = (vbn_ros_msgs__msg__AOASSA__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__AOASSA__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__AOASSA__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__AOASSA__Sequence__destroy(vbn_ros_msgs__msg__AOASSA__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__AOASSA__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__AOASSA__Sequence__are_equal(const vbn_ros_msgs__msg__AOASSA__Sequence * lhs, const vbn_ros_msgs__msg__AOASSA__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__AOASSA__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__AOASSA__Sequence__copy(
  const vbn_ros_msgs__msg__AOASSA__Sequence * input,
  vbn_ros_msgs__msg__AOASSA__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__AOASSA);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__AOASSA * data =
      (vbn_ros_msgs__msg__AOASSA *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__AOASSA__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__AOASSA__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__AOASSA__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
