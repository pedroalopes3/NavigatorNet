# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/AHRS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AHRS(type):
    """Metaclass of message 'AHRS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'vbn_ros_msgs.msg.AHRS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ahrs
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ahrs
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ahrs
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ahrs
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ahrs

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AHRS(metaclass=Metaclass_AHRS):
    """Message class 'AHRS'."""

    __slots__ = [
        '_header',
        '_omega_ix',
        '_omega_iy',
        '_omega_iz',
        '_accel_weight',
        '_renorm_val',
        '_error_rp',
        '_error_yaw',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'omega_ix': 'float',
        'omega_iy': 'float',
        'omega_iz': 'float',
        'accel_weight': 'float',
        'renorm_val': 'float',
        'error_rp': 'float',
        'error_yaw': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.omega_ix = kwargs.get('omega_ix', float())
        self.omega_iy = kwargs.get('omega_iy', float())
        self.omega_iz = kwargs.get('omega_iz', float())
        self.accel_weight = kwargs.get('accel_weight', float())
        self.renorm_val = kwargs.get('renorm_val', float())
        self.error_rp = kwargs.get('error_rp', float())
        self.error_yaw = kwargs.get('error_yaw', float())

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
        if self.omega_ix != other.omega_ix:
            return False
        if self.omega_iy != other.omega_iy:
            return False
        if self.omega_iz != other.omega_iz:
            return False
        if self.accel_weight != other.accel_weight:
            return False
        if self.renorm_val != other.renorm_val:
            return False
        if self.error_rp != other.error_rp:
            return False
        if self.error_yaw != other.error_yaw:
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
    def omega_ix(self):
        """Message field 'omega_ix'."""
        return self._omega_ix

    @omega_ix.setter
    def omega_ix(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'omega_ix' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'omega_ix' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._omega_ix = value

    @builtins.property
    def omega_iy(self):
        """Message field 'omega_iy'."""
        return self._omega_iy

    @omega_iy.setter
    def omega_iy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'omega_iy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'omega_iy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._omega_iy = value

    @builtins.property
    def omega_iz(self):
        """Message field 'omega_iz'."""
        return self._omega_iz

    @omega_iz.setter
    def omega_iz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'omega_iz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'omega_iz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._omega_iz = value

    @builtins.property
    def accel_weight(self):
        """Message field 'accel_weight'."""
        return self._accel_weight

    @accel_weight.setter
    def accel_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'accel_weight' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'accel_weight' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._accel_weight = value

    @builtins.property
    def renorm_val(self):
        """Message field 'renorm_val'."""
        return self._renorm_val

    @renorm_val.setter
    def renorm_val(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'renorm_val' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'renorm_val' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._renorm_val = value

    @builtins.property
    def error_rp(self):
        """Message field 'error_rp'."""
        return self._error_rp

    @error_rp.setter
    def error_rp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_rp' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'error_rp' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._error_rp = value

    @builtins.property
    def error_yaw(self):
        """Message field 'error_yaw'."""
        return self._error_yaw

    @error_yaw.setter
    def error_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error_yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'error_yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._error_yaw = value
