// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vbn_ros_msgs:msg/AHRS.idl
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
#include "vbn_ros_msgs/msg/detail/ahrs__struct.h"
#include "vbn_ros_msgs/msg/detail/ahrs__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vbn_ros_msgs__msg__ahrs__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
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
    assert(strncmp("vbn_ros_msgs.msg._ahrs.AHRS", full_classname_dest, 27) == 0);
  }
  vbn_ros_msgs__msg__AHRS * ros_message = _ros_message;
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
  {  // omega_ix
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_ix");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->omega_ix = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // omega_iy
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_iy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->omega_iy = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // omega_iz
    PyObject * field = PyObject_GetAttrString(_pymsg, "omega_iz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->omega_iz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // accel_weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "accel_weight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->accel_weight = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // renorm_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "renorm_val");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->renorm_val = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_rp
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_rp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_rp = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vbn_ros_msgs__msg__ahrs__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AHRS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vbn_ros_msgs.msg._ahrs");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AHRS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vbn_ros_msgs__msg__AHRS * ros_message = (vbn_ros_msgs__msg__AHRS *)raw_ros_message;
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
  {  // omega_ix
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->omega_ix);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_ix", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega_iy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->omega_iy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_iy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // omega_iz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->omega_iz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "omega_iz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // accel_weight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->accel_weight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accel_weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // renorm_val
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->renorm_val);
    {
      int rc = PyObject_SetAttrString(_pymessage, "renorm_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_rp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_rp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_rp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
