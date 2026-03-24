// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vbn_ros_msgs:msg/EKFStatusReport.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "vbn_ros_msgs/msg/detail/ekf_status_report__struct.h"
#include "vbn_ros_msgs/msg/detail/ekf_status_report__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vbn_ros_msgs__msg__ekf_status_report__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vbn_ros_msgs.msg._ekf_status_report.EKFStatusReport", full_classname_dest, 51) == 0);
  }
  vbn_ros_msgs__msg__EKFStatusReport * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // velocity_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->velocity_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_horiz_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_horiz_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_horiz_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_vert_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_vert_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_vert_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // compass_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "compass_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->compass_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // terrain_alt_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "terrain_alt_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->terrain_alt_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // airspeed_variance
    PyObject * field = PyObject_GetAttrString(_pymsg, "airspeed_variance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->airspeed_variance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vbn_ros_msgs__msg__ekf_status_report__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EKFStatusReport */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vbn_ros_msgs.msg._ekf_status_report");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EKFStatusReport");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vbn_ros_msgs__msg__EKFStatusReport * ros_message = (vbn_ros_msgs__msg__EKFStatusReport *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->velocity_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "velocity_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_horiz_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_horiz_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_horiz_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_vert_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_vert_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_vert_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // compass_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->compass_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "compass_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // terrain_alt_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->terrain_alt_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "terrain_alt_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // airspeed_variance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->airspeed_variance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "airspeed_variance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
