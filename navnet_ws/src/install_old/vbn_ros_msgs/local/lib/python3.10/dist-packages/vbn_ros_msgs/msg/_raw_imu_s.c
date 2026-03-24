// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vbn_ros_msgs:msg/RawIMU.idl
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
#include "vbn_ros_msgs/msg/detail/raw_imu__struct.h"
#include "vbn_ros_msgs/msg/detail/raw_imu__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vbn_ros_msgs__msg__raw_imu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
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
    assert(strncmp("vbn_ros_msgs.msg._raw_imu.RawIMU", full_classname_dest, 32) == 0);
  }
  vbn_ros_msgs__msg__RawIMU * ros_message = _ros_message;
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
  {  // time_usec
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_usec");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_usec = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // xacc
    PyObject * field = PyObject_GetAttrString(_pymsg, "xacc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xacc = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // yacc
    PyObject * field = PyObject_GetAttrString(_pymsg, "yacc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yacc = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // zacc
    PyObject * field = PyObject_GetAttrString(_pymsg, "zacc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zacc = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // xgyro
    PyObject * field = PyObject_GetAttrString(_pymsg, "xgyro");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xgyro = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ygyro
    PyObject * field = PyObject_GetAttrString(_pymsg, "ygyro");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ygyro = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // zgyro
    PyObject * field = PyObject_GetAttrString(_pymsg, "zgyro");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zgyro = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // xmag
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmag = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // ymag
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymag = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // zmag
    PyObject * field = PyObject_GetAttrString(_pymsg, "zmag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zmag = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vbn_ros_msgs__msg__raw_imu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RawIMU */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vbn_ros_msgs.msg._raw_imu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RawIMU");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vbn_ros_msgs__msg__RawIMU * ros_message = (vbn_ros_msgs__msg__RawIMU *)raw_ros_message;
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
  {  // time_usec
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->time_usec);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_usec", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xacc
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xacc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xacc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yacc
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->yacc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yacc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zacc
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->zacc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zacc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xgyro
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xgyro);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xgyro", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ygyro
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ygyro);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ygyro", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zgyro
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->zgyro);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zgyro", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmag
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->xmag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymag
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->ymag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zmag
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->zmag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zmag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
