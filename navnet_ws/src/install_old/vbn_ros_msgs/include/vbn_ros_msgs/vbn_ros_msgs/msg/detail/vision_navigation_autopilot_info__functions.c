// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/vision_navigation_autopilot_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__init(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(msg);
    return false;
  }
  // time_msec
  // alarms
  // lat
  // lng
  // alt_msl
  // pos_variance_x
  // pos_variance_y
  // pos_variance_z
  // vx
  // vy
  // vz
  // roll
  // pitch
  // yaw
  return true;
}

void
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time_msec
  // alarms
  // lat
  // lng
  // alt_msl
  // pos_variance_x
  // pos_variance_y
  // pos_variance_z
  // vx
  // vy
  // vz
  // roll
  // pitch
  // yaw
}

bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__are_equal(const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * lhs, const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * rhs)
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
  // time_msec
  if (lhs->time_msec != rhs->time_msec) {
    return false;
  }
  // alarms
  if (lhs->alarms != rhs->alarms) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // lng
  if (lhs->lng != rhs->lng) {
    return false;
  }
  // alt_msl
  if (lhs->alt_msl != rhs->alt_msl) {
    return false;
  }
  // pos_variance_x
  if (lhs->pos_variance_x != rhs->pos_variance_x) {
    return false;
  }
  // pos_variance_y
  if (lhs->pos_variance_y != rhs->pos_variance_y) {
    return false;
  }
  // pos_variance_z
  if (lhs->pos_variance_z != rhs->pos_variance_z) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__copy(
  const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * input,
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * output)
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
  // time_msec
  output->time_msec = input->time_msec;
  // alarms
  output->alarms = input->alarms;
  // lat
  output->lat = input->lat;
  // lng
  output->lng = input->lng;
  // alt_msl
  output->alt_msl = input->alt_msl;
  // pos_variance_x
  output->pos_variance_x = input->pos_variance_x;
  // pos_variance_y
  output->pos_variance_y = input->pos_variance_y;
  // pos_variance_z
  output->pos_variance_z = input->pos_variance_z;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

vbn_ros_msgs__msg__VisionNavigationAutopilotInfo *
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * msg = (vbn_ros_msgs__msg__VisionNavigationAutopilotInfo *)allocator.allocate(sizeof(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo));
  bool success = vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__destroy(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__init(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__VisionNavigationAutopilotInfo *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(&data[i - 1]);
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
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__fini(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * array)
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
      vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(&array->data[i]);
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

vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence *
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * array = (vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__destroy(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__are_equal(const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * lhs, const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence__copy(
  const vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * input,
  vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__VisionNavigationAutopilotInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__VisionNavigationAutopilotInfo * data =
      (vbn_ros_msgs__msg__VisionNavigationAutopilotInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__VisionNavigationAutopilotInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
