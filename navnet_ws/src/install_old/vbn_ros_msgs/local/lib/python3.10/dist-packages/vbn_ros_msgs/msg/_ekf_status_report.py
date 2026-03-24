# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/EKFStatusReport.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EKFStatusReport(type):
    """Metaclass of message 'EKFStatusReport'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'EKF_ATTITUDE': 1,
        'EKF_VELOCITY_HORIZ': 2,
        'EKF_VELOCITY_VERT': 4,
        'EKF_POS_HORIZ_REL': 8,
        'EKF_POS_HORIZ_ABS': 16,
        'EKF_POS_VERT_ABS': 32,
        'EKF_POS_VERT_AGL': 64,
        'EKF_CONST_POS_MODE': 128,
        'EKF_PRED_POS_HORIZ_REL': 256,
        'EKF_PRED_POS_HORIZ_ABS': 512,
        'EKF_UNINITIALIZED': 1024,
        'EKF_GPS_GLITCHING': 32768,
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
                'vbn_ros_msgs.msg.EKFStatusReport')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ekf_status_report
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ekf_status_report
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ekf_status_report
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ekf_status_report
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ekf_status_report

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'EKF_ATTITUDE': cls.__constants['EKF_ATTITUDE'],
            'EKF_VELOCITY_HORIZ': cls.__constants['EKF_VELOCITY_HORIZ'],
            'EKF_VELOCITY_VERT': cls.__constants['EKF_VELOCITY_VERT'],
            'EKF_POS_HORIZ_REL': cls.__constants['EKF_POS_HORIZ_REL'],
            'EKF_POS_HORIZ_ABS': cls.__constants['EKF_POS_HORIZ_ABS'],
            'EKF_POS_VERT_ABS': cls.__constants['EKF_POS_VERT_ABS'],
            'EKF_POS_VERT_AGL': cls.__constants['EKF_POS_VERT_AGL'],
            'EKF_CONST_POS_MODE': cls.__constants['EKF_CONST_POS_MODE'],
            'EKF_PRED_POS_HORIZ_REL': cls.__constants['EKF_PRED_POS_HORIZ_REL'],
            'EKF_PRED_POS_HORIZ_ABS': cls.__constants['EKF_PRED_POS_HORIZ_ABS'],
            'EKF_UNINITIALIZED': cls.__constants['EKF_UNINITIALIZED'],
            'EKF_GPS_GLITCHING': cls.__constants['EKF_GPS_GLITCHING'],
        }

    @property
    def EKF_ATTITUDE(self):
        """Message constant 'EKF_ATTITUDE'."""
        return Metaclass_EKFStatusReport.__constants['EKF_ATTITUDE']

    @property
    def EKF_VELOCITY_HORIZ(self):
        """Message constant 'EKF_VELOCITY_HORIZ'."""
        return Metaclass_EKFStatusReport.__constants['EKF_VELOCITY_HORIZ']

    @property
    def EKF_VELOCITY_VERT(self):
        """Message constant 'EKF_VELOCITY_VERT'."""
        return Metaclass_EKFStatusReport.__constants['EKF_VELOCITY_VERT']

    @property
    def EKF_POS_HORIZ_REL(self):
        """Message constant 'EKF_POS_HORIZ_REL'."""
        return Metaclass_EKFStatusReport.__constants['EKF_POS_HORIZ_REL']

    @property
    def EKF_POS_HORIZ_ABS(self):
        """Message constant 'EKF_POS_HORIZ_ABS'."""
        return Metaclass_EKFStatusReport.__constants['EKF_POS_HORIZ_ABS']

    @property
    def EKF_POS_VERT_ABS(self):
        """Message constant 'EKF_POS_VERT_ABS'."""
        return Metaclass_EKFStatusReport.__constants['EKF_POS_VERT_ABS']

    @property
    def EKF_POS_VERT_AGL(self):
        """Message constant 'EKF_POS_VERT_AGL'."""
        return Metaclass_EKFStatusReport.__constants['EKF_POS_VERT_AGL']

    @property
    def EKF_CONST_POS_MODE(self):
        """Message constant 'EKF_CONST_POS_MODE'."""
        return Metaclass_EKFStatusReport.__constants['EKF_CONST_POS_MODE']

    @property
    def EKF_PRED_POS_HORIZ_REL(self):
        """Message constant 'EKF_PRED_POS_HORIZ_REL'."""
        return Metaclass_EKFStatusReport.__constants['EKF_PRED_POS_HORIZ_REL']

    @property
    def EKF_PRED_POS_HORIZ_ABS(self):
        """Message constant 'EKF_PRED_POS_HORIZ_ABS'."""
        return Metaclass_EKFStatusReport.__constants['EKF_PRED_POS_HORIZ_ABS']

    @property
    def EKF_UNINITIALIZED(self):
        """Message constant 'EKF_UNINITIALIZED'."""
        return Metaclass_EKFStatusReport.__constants['EKF_UNINITIALIZED']

    @property
    def EKF_GPS_GLITCHING(self):
        """Message constant 'EKF_GPS_GLITCHING'."""
        return Metaclass_EKFStatusReport.__constants['EKF_GPS_GLITCHING']


class EKFStatusReport(metaclass=Metaclass_EKFStatusReport):
    """
    Message class 'EKFStatusReport'.

    Constants:
      EKF_ATTITUDE
      EKF_VELOCITY_HORIZ
      EKF_VELOCITY_VERT
      EKF_POS_HORIZ_REL
      EKF_POS_HORIZ_ABS
      EKF_POS_VERT_ABS
      EKF_POS_VERT_AGL
      EKF_CONST_POS_MODE
      EKF_PRED_POS_HORIZ_REL
      EKF_PRED_POS_HORIZ_ABS
      EKF_UNINITIALIZED
      EKF_GPS_GLITCHING
    """

    __slots__ = [
        '_header',
        '_flags',
        '_velocity_variance',
        '_pos_horiz_variance',
        '_pos_vert_variance',
        '_compass_variance',
        '_terrain_alt_variance',
        '_airspeed_variance',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'flags': 'uint16',
        'velocity_variance': 'float',
        'pos_horiz_variance': 'float',
        'pos_vert_variance': 'float',
        'compass_variance': 'float',
        'terrain_alt_variance': 'float',
        'airspeed_variance': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.flags = kwargs.get('flags', int())
        self.velocity_variance = kwargs.get('velocity_variance', float())
        self.pos_horiz_variance = kwargs.get('pos_horiz_variance', float())
        self.pos_vert_variance = kwargs.get('pos_vert_variance', float())
        self.compass_variance = kwargs.get('compass_variance', float())
        self.terrain_alt_variance = kwargs.get('terrain_alt_variance', float())
        self.airspeed_variance = kwargs.get('airspeed_variance', float())

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
        if self.flags != other.flags:
            return False
        if self.velocity_variance != other.velocity_variance:
            return False
        if self.pos_horiz_variance != other.pos_horiz_variance:
            return False
        if self.pos_vert_variance != other.pos_vert_variance:
            return False
        if self.compass_variance != other.compass_variance:
            return False
        if self.terrain_alt_variance != other.terrain_alt_variance:
            return False
        if self.airspeed_variance != other.airspeed_variance:
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
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'flags' field must be an unsigned integer in [0, 65535]"
        self._flags = value

    @builtins.property
    def velocity_variance(self):
        """Message field 'velocity_variance'."""
        return self._velocity_variance

    @velocity_variance.setter
    def velocity_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'velocity_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'velocity_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._velocity_variance = value

    @builtins.property
    def pos_horiz_variance(self):
        """Message field 'pos_horiz_variance'."""
        return self._pos_horiz_variance

    @pos_horiz_variance.setter
    def pos_horiz_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_horiz_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_horiz_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_horiz_variance = value

    @builtins.property
    def pos_vert_variance(self):
        """Message field 'pos_vert_variance'."""
        return self._pos_vert_variance

    @pos_vert_variance.setter
    def pos_vert_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_vert_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_vert_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_vert_variance = value

    @builtins.property
    def compass_variance(self):
        """Message field 'compass_variance'."""
        return self._compass_variance

    @compass_variance.setter
    def compass_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'compass_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'compass_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._compass_variance = value

    @builtins.property
    def terrain_alt_variance(self):
        """Message field 'terrain_alt_variance'."""
        return self._terrain_alt_variance

    @terrain_alt_variance.setter
    def terrain_alt_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'terrain_alt_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'terrain_alt_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._terrain_alt_variance = value

    @builtins.property
    def airspeed_variance(self):
        """Message field 'airspeed_variance'."""
        return self._airspeed_variance

    @airspeed_variance.setter
    def airspeed_variance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'airspeed_variance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'airspeed_variance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._airspeed_variance = value
