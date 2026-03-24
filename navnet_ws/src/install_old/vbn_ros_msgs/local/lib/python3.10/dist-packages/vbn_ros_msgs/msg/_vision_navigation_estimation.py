# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/VisionNavigationEstimation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisionNavigationEstimation(type):
    """Metaclass of message 'VisionNavigationEstimation'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NAVIGATION_ESTIMATION_FLAGS_UNKNOWN': 0,
        'NAVIGATION_ESTIMATION_FLAGS_OK': 1,
        'NAVIGATION_ESTIMATION_FLAGS_ABS_OK': 2,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vbn_ros_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vbn_ros_msgs.msg.VisionNavigationEstimation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vision_navigation_estimation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vision_navigation_estimation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vision_navigation_estimation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vision_navigation_estimation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vision_navigation_estimation

            from geographic_msgs.msg import GeoPoint
            if GeoPoint.__class__._TYPE_SUPPORT is None:
                GeoPoint.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NAVIGATION_ESTIMATION_FLAGS_UNKNOWN': cls.__constants['NAVIGATION_ESTIMATION_FLAGS_UNKNOWN'],
            'NAVIGATION_ESTIMATION_FLAGS_OK': cls.__constants['NAVIGATION_ESTIMATION_FLAGS_OK'],
            'NAVIGATION_ESTIMATION_FLAGS_ABS_OK': cls.__constants['NAVIGATION_ESTIMATION_FLAGS_ABS_OK'],
        }

    @property
    def NAVIGATION_ESTIMATION_FLAGS_UNKNOWN(self):
        """Message constant 'NAVIGATION_ESTIMATION_FLAGS_UNKNOWN'."""
        return Metaclass_VisionNavigationEstimation.__constants['NAVIGATION_ESTIMATION_FLAGS_UNKNOWN']

    @property
    def NAVIGATION_ESTIMATION_FLAGS_OK(self):
        """Message constant 'NAVIGATION_ESTIMATION_FLAGS_OK'."""
        return Metaclass_VisionNavigationEstimation.__constants['NAVIGATION_ESTIMATION_FLAGS_OK']

    @property
    def NAVIGATION_ESTIMATION_FLAGS_ABS_OK(self):
        """Message constant 'NAVIGATION_ESTIMATION_FLAGS_ABS_OK'."""
        return Metaclass_VisionNavigationEstimation.__constants['NAVIGATION_ESTIMATION_FLAGS_ABS_OK']


class VisionNavigationEstimation(metaclass=Metaclass_VisionNavigationEstimation):
    """
    Message class 'VisionNavigationEstimation'.

    Constants:
      NAVIGATION_ESTIMATION_FLAGS_UNKNOWN
      NAVIGATION_ESTIMATION_FLAGS_OK
      NAVIGATION_ESTIMATION_FLAGS_ABS_OK
    """

    __slots__ = [
        '_header',
        '_position',
        '_flags',
        '_pos_error',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'position': 'geographic_msgs/GeoPoint',
        'flags': 'uint8',
        'pos_error': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geographic_msgs', 'msg'], 'GeoPoint'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geographic_msgs.msg import GeoPoint
        self.position = kwargs.get('position', GeoPoint())
        self.flags = kwargs.get('flags', int())
        self.pos_error = kwargs.get('pos_error', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.position != other.position:
            return False
        if self.flags != other.flags:
            return False
        if self.pos_error != other.pos_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geographic_msgs.msg import GeoPoint
            assert \
                isinstance(value, GeoPoint), \
                "The 'position' field must be a sub message of type 'GeoPoint'"
        self._position = value

    @builtins.property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'flags' field must be an unsigned integer in [0, 255]"
        self._flags = value

    @builtins.property
    def pos_error(self):
        """Message field 'pos_error'."""
        return self._pos_error

    @pos_error.setter
    def pos_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_error = value
