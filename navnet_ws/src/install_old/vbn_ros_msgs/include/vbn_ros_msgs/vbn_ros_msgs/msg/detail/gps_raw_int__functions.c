// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vbn_ros_msgs:msg/GPSRawInt.idl
// generated code does not contain a copyright notice
#include "vbn_ros_msgs/msg/detail/gps_raw_int__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
vbn_ros_msgs__msg__GPSRawInt__init(vbn_ros_msgs__msg__GPSRawInt * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vbn_ros_msgs__msg__GPSRawInt__fini(msg);
    return false;
  }
  // time_usec
  // fix_type
  // lat
  // lon
  // alt
  // eph
  // epv
  // vel
  // cog
  // satellites_visible
  // alt_ellipsoid
  // h_acc
  // v_acc
  // vel_acc
  // hdg_acc
  // yaw
  return true;
}

void
vbn_ros_msgs__msg__GPSRawInt__fini(vbn_ros_msgs__msg__GPSRawInt * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // time_usec
  // fix_type
  // lat
  // lon
  // alt
  // eph
  // epv
  // vel
  // cog
  // satellites_visible
  // alt_ellipsoid
  // h_acc
  // v_acc
  // vel_acc
  // hdg_acc
  // yaw
}

bool
vbn_ros_msgs__msg__GPSRawInt__are_equal(const vbn_ros_msgs__msg__GPSRawInt * lhs, const vbn_ros_msgs__msg__GPSRawInt * rhs)
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
  // fix_type
  if (lhs->fix_type != rhs->fix_type) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // alt
  if (lhs->alt != rhs->alt) {
    return false;
  }
  // eph
  if (lhs->eph != rhs->eph) {
    return false;
  }
  // epv
  if (lhs->epv != rhs->epv) {
    return false;
  }
  // vel
  if (lhs->vel != rhs->vel) {
    return false;
  }
  // cog
  if (lhs->cog != rhs->cog) {
    return false;
  }
  // satellites_visible
  if (lhs->satellites_visible != rhs->satellites_visible) {
    return false;
  }
  // alt_ellipsoid
  if (lhs->alt_ellipsoid != rhs->alt_ellipsoid) {
    return false;
  }
  // h_acc
  if (lhs->h_acc != rhs->h_acc) {
    return false;
  }
  // v_acc
  if (lhs->v_acc != rhs->v_acc) {
    return false;
  }
  // vel_acc
  if (lhs->vel_acc != rhs->vel_acc) {
    return false;
  }
  // hdg_acc
  if (lhs->hdg_acc != rhs->hdg_acc) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
vbn_ros_msgs__msg__GPSRawInt__copy(
  const vbn_ros_msgs__msg__GPSRawInt * input,
  vbn_ros_msgs__msg__GPSRawInt * output)
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
  // fix_type
  output->fix_type = input->fix_type;
  // lat
  output->lat = input->lat;
  // lon
  output->lon = input->lon;
  // alt
  output->alt = input->alt;
  // eph
  output->eph = input->eph;
  // epv
  output->epv = input->epv;
  // vel
  output->vel = input->vel;
  // cog
  output->cog = input->cog;
  // satellites_visible
  output->satellites_visible = input->satellites_visible;
  // alt_ellipsoid
  output->alt_ellipsoid = input->alt_ellipsoid;
  // h_acc
  output->h_acc = input->h_acc;
  // v_acc
  output->v_acc = input->v_acc;
  // vel_acc
  output->vel_acc = input->vel_acc;
  // hdg_acc
  output->hdg_acc = input->hdg_acc;
  // yaw
  output->yaw = input->yaw;
  return true;
}

vbn_ros_msgs__msg__GPSRawInt *
vbn_ros_msgs__msg__GPSRawInt__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__GPSRawInt * msg = (vbn_ros_msgs__msg__GPSRawInt *)allocator.allocate(sizeof(vbn_ros_msgs__msg__GPSRawInt), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vbn_ros_msgs__msg__GPSRawInt));
  bool success = vbn_ros_msgs__msg__GPSRawInt__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vbn_ros_msgs__msg__GPSRawInt__destroy(vbn_ros_msgs__msg__GPSRawInt * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vbn_ros_msgs__msg__GPSRawInt__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vbn_ros_msgs__msg__GPSRawInt__Sequence__init(vbn_ros_msgs__msg__GPSRawInt__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__GPSRawInt * data = NULL;

  if (size) {
    data = (vbn_ros_msgs__msg__GPSRawInt *)allocator.zero_allocate(size, sizeof(vbn_ros_msgs__msg__GPSRawInt), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vbn_ros_msgs__msg__GPSRawInt__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vbn_ros_msgs__msg__GPSRawInt__fini(&data[i - 1]);
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
vbn_ros_msgs__msg__GPSRawInt__Sequence__fini(vbn_ros_msgs__msg__GPSRawInt__Sequence * array)
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
      vbn_ros_msgs__msg__GPSRawInt__fini(&array->data[i]);
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

vbn_ros_msgs__msg__GPSRawInt__Sequence *
vbn_ros_msgs__msg__GPSRawInt__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vbn_ros_msgs__msg__GPSRawInt__Sequence * array = (vbn_ros_msgs__msg__GPSRawInt__Sequence *)allocator.allocate(sizeof(vbn_ros_msgs__msg__GPSRawInt__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vbn_ros_msgs__msg__GPSRawInt__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vbn_ros_msgs__msg__GPSRawInt__Sequence__destroy(vbn_ros_msgs__msg__GPSRawInt__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vbn_ros_msgs__msg__GPSRawInt__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vbn_ros_msgs__msg__GPSRawInt__Sequence__are_equal(const vbn_ros_msgs__msg__GPSRawInt__Sequence * lhs, const vbn_ros_msgs__msg__GPSRawInt__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vbn_ros_msgs__msg__GPSRawInt__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vbn_ros_msgs__msg__GPSRawInt__Sequence__copy(
  const vbn_ros_msgs__msg__GPSRawInt__Sequence * input,
  vbn_ros_msgs__msg__GPSRawInt__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vbn_ros_msgs__msg__GPSRawInt);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vbn_ros_msgs__msg__GPSRawInt * data =
      (vbn_ros_msgs__msg__GPSRawInt *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vbn_ros_msgs__msg__GPSRawInt__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vbn_ros_msgs__msg__GPSRawInt__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vbn_ros_msgs__msg__GPSRawInt__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
