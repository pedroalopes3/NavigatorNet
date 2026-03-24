// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vbn_ros_msgs:msg/RCChannels.idl
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
#include "vbn_ros_msgs/msg/detail/rc_channels__struct.h"
#include "vbn_ros_msgs/msg/detail/rc_channels__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vbn_ros_msgs__msg__rc_channels__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("vbn_ros_msgs.msg._rc_channels.RCChannels", full_classname_dest, 40) == 0);
  }
  vbn_ros_msgs__msg__RCChannels * ros_message = _ros_message;
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
  {  // time_boot_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_boot_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_boot_ms = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chancount
    PyObject * field = PyObject_GetAttrString(_pymsg, "chancount");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chancount = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan1_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan1_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan1_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan2_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan2_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan2_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan3_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan3_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan3_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan4_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan4_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan4_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan5_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan5_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan5_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan6_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan6_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan6_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan7_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan7_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan7_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan8_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan8_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan8_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan9_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan9_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan9_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan10_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan10_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan10_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan11_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan11_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan11_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan12_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan12_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan12_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan13_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan13_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan13_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan14_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan14_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan14_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan15_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan15_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan15_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan16_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan16_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan16_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan17_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan17_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan17_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // chan18_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "chan18_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chan18_raw = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rssi
    PyObject * field = PyObject_GetAttrString(_pymsg, "rssi");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rssi = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vbn_ros_msgs__msg__rc_channels__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RCChannels */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vbn_ros_msgs.msg._rc_channels");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RCChannels");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vbn_ros_msgs__msg__RCChannels * ros_message = (vbn_ros_msgs__msg__RCChannels *)raw_ros_message;
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
  {  // time_boot_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->time_boot_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_boot_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chancount
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chancount);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chancount", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan1_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan1_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan1_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan2_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan2_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan2_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan3_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan3_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan3_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan4_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan4_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan4_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan5_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan5_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan5_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan6_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan6_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan6_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan7_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan7_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan7_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan8_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan8_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan8_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan9_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan9_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan9_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan10_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan10_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan10_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan11_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan11_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan11_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan12_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan12_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan12_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan13_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan13_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan13_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan14_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan14_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan14_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan15_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan15_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan15_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan16_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan16_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan16_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan17_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan17_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan17_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // chan18_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chan18_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chan18_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rssi
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rssi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rssi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
