// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/rc_channels__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
vbn_ros_msgs__msg__RCChannels__init(vbn_ros_msgs__msg__RCChannels * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vbn_ros_msgs__msg__RCChannels__fini(msg);
    return false;
  }
  // time_boot_ms
  // chancount
  // chan1_raw
  // chan2_raw
  // chan3_raw
  // chan4_raw
  // chan5_raw
  // chan6_raw
  // chan7_raw
  // chan8_raw
  // chan9_raw
  // chan10_raw
  // chan11_raw
  // chan12_raw
  // chan13_raw
  // chan14_raw
  // chan15_raw
  // chan16_raw
  // chan17_raw
  // chan18_raw
  // rssi
  return true;
}

void
vbn_ros_msgs__msg__RCChannels__fini(vbn_ros_msgs__msg__RCChannels * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time_boot_ms
  // chancount
  // chan1_raw
  // chan2_raw
  // chan3_raw
  // chan4_raw
  // chan5_raw
  // chan6_raw
  // chan7_raw
  // chan8_raw
  // chan9_raw
  // chan10_raw
  // chan11_raw
  // chan12_raw
  // chan13_raw
  // chan14_raw
  // chan15_raw
  // chan16_raw
  // chan17_raw
  // chan18_raw
  // rssi
}

bool
vbn_ros_msgs__msg__RCChannels__are_equal(const vbn_ros_msgs__msg__RCChannels * lhs, const vbn_ros_msgs__msg__RCChannels * rhs)
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
  // time_boot_ms
  if (lhs->time_boot_ms != rhs->time_boot_ms) {
    return false;
  }
  // chancount
  if (lhs->chancount != rhs->chancount) {
    return false;
  }
  // chan1_raw
  if (lhs->chan1_raw != rhs->chan1_raw) {
    return false;
  }
  // chan2_raw
  if (lhs->chan2_raw != rhs->chan2_raw) {
    return false;
  }
  // chan3_raw
  if (lhs->chan3_raw != rhs->chan3_raw) {
    return false;
  }
  // chan4_raw
  if (lhs->chan4_raw != rhs->chan4_raw) {
    return false;
  }
  // chan5_raw
  if (lhs->chan5_raw != rhs->chan5_raw) {
    return false;
  }
  // chan6_raw
  if (lhs->chan6_raw != rhs->chan6_raw) {
    return false;
  }
  // chan7_raw
  if (lhs->chan7_raw != rhs->chan7_raw) {
    return false;
  }
  // chan8_raw
  if (lhs->chan8_raw != rhs->chan8_raw) {
    return false;
  }
  // chan9_raw
  if (lhs->chan9_raw != rhs->chan9_raw) {
    return false;
  }
  // chan10_raw
  if (lhs->chan10_raw != rhs->chan10_raw) {
    return false;
  }
  // chan11_raw
  if (lhs->chan11_raw != rhs->chan11_raw) {
    return false;
  }
  // chan12_raw
  if (lhs->chan12_raw != rhs->chan12_raw) {
    return false;
  }
  // chan13_raw
  if (lhs->chan13_raw != rhs->chan13_raw) {
    return false;
  }
  // chan14_raw
  if (lhs->chan14_raw != rhs->chan14_raw) {
    return false;
  }
  // chan15_raw
  if (lhs->chan15_raw != rhs->chan15_raw) {
    return false;
  }
  // chan16_raw
  if (lhs->chan16_raw != rhs->chan16_raw) {
    return false;
  }
  // chan17_raw
  if (lhs->chan17_raw != rhs->chan17_raw) {
    return false;
  }
  // chan18_raw
  if (lhs->chan18_raw != rhs->chan18_raw) {
    return false;
  }
  // rssi
  if (lhs->rssi != rhs->rssi) {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__RCChannels__copy(
  const vbn_ros_msgs__msg__RCChannels * input,
  vbn_ros_msgs__msg__RCChannels * output)
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
  // time_boot_ms
  output->time_boot_ms = input->time_boot_ms;
  // chancount
  output->chancount = input->chancount;
  // chan1_raw
  output->chan1_raw = input->chan1_raw;
  // chan2_raw
  output->chan2_raw = input->chan2_raw;
  // chan3_raw
  output->chan3_raw = input->chan3_raw;
  // chan4_raw
  output->chan4_raw = input->chan4_raw;
  // chan5_raw
  output->chan5_raw = input->chan5_raw;
  // chan6_raw
  output->chan6_raw = input->chan6_raw;
  // chan7_raw
  output->chan7_raw = input->chan7_raw;
  // chan8_raw
  output->chan8_raw = input->chan8_raw;
  // chan9_raw
  output->chan9_raw = input->chan9_raw;
  // chan10_raw
  output->chan10_raw = input->chan10_raw;
  // chan11_raw
  output->chan11_raw = input->chan11_raw;
  // chan12_raw
  output->chan12_raw = input->chan12_raw;
  // chan13_raw
  output->chan13_raw = input->chan13_raw;
  // chan14_raw
  output->chan14_raw = input->chan14_raw;
  // chan15_raw
  output->chan15_raw = input->chan15_raw;
  // chan16_raw
  output->chan16_raw = input->chan16_raw;
  // chan17_raw
  output->chan17_raw = input->chan17_raw;
  // chan18_raw
  output->chan18_raw = input->chan18_raw;
  // rssi
  output->rssi = input->rssi;
  return true;
}

vbn_ros_msgs__msg__RCChannels *
vbn_ros_msgs__msg__RCChannels__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__RCChannels * msg = (vbn_ros_msgs__msg__RCChannels *)allocator.allocate(sizeof(vbn_ros_msgs__msg__RCChannels), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__RCChannels));
  bool success = vbn_ros_msgs__msg__RCChannels__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__RCChannels__destroy(vbn_ros_msgs__msg__RCChannels * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__RCChannels__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__RCChannels__Sequence__init(vbn_ros_msgs__msg__RCChannels__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__RCChannels * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__RCChannels *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__RCChannels), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__RCChannels__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__RCChannels__fini(&data[i - 1]);
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
vbn_ros_msgs__msg__RCChannels__Sequence__fini(vbn_ros_msgs__msg__RCChannels__Sequence * array)
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
      vbn_ros_msgs__msg__RCChannels__fini(&array->data[i]);
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

vbn_ros_msgs__msg__RCChannels__Sequence *
vbn_ros_msgs__msg__RCChannels__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__RCChannels__Sequence * array = (vbn_ros_msgs__msg__RCChannels__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__RCChannels__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__RCChannels__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__RCChannels__Sequence__destroy(vbn_ros_msgs__msg__RCChannels__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__RCChannels__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__RCChannels__Sequence__are_equal(const vbn_ros_msgs__msg__RCChannels__Sequence * lhs, const vbn_ros_msgs__msg__RCChannels__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__RCChannels__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__RCChannels__Sequence__copy(
  const vbn_ros_msgs__msg__RCChannels__Sequence * input,
  vbn_ros_msgs__msg__RCChannels__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__RCChannels);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__RCChannels * data =
      (vbn_ros_msgs__msg__RCChannels *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__RCChannels__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__RCChannels__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__RCChannels__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
