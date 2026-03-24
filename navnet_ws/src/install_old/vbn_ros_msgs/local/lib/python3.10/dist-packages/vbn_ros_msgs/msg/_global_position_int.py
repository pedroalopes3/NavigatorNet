# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/GlobalPositionInt.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GlobalPositionInt(type):
    """Metaclass of message 'GlobalPositionInt'."""

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
                'vbn_ros_msgs.msg.GlobalPositionInt')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__global_position_int
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__global_position_int
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__global_position_int
            cls._TYPE_SUPPORT = module.type_support_msg__msg__global_position_int
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__global_position_int

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


class GlobalPositionInt(metaclass=Metaclass_GlobalPositionInt):
    """Message class 'GlobalPositionInt'."""

    __slots__ = [
        '_header',
        '_time_boot_ms',
        '_lat',
        '_lon',
        '_alt',
        '_relative_alt',
        '_vx',
        '_vy',
        '_vz',
        '_hdg',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'time_boot_ms': 'uint32',
        'lat': 'int32',
        'lon': 'int32',
        'alt': 'int32',
        'relative_alt': 'int32',
        'vx': 'int16',
        'vy': 'int16',
        'vz': 'int16',
        'hdg': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.lat = kwargs.get('lat', int())
        self.lon = kwargs.get('lon', int())
        self.alt = kwargs.get('alt', int())
        self.relative_alt = kwargs.get('relative_alt', int())
        self.vx = kwargs.get('vx', int())
        self.vy = kwargs.get('vy', int())
        self.vz = kwargs.get('vz', int())
        self.hdg = kwargs.get('hdg', int())

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
        if self.time_boot_ms != other.time_boot_ms:
            return False
        if self.lat != other.lat:
            return False
        if self.lon != other.lon:
            return False
        if self.alt != other.alt:
            return False
        if self.relative_alt != other.relative_alt:
            return False
        if self.vx != other.vx:
            return False
        if self.vy != other.vy:
            return False
        if self.vz != other.vz:
            return False
        if self.hdg != other.hdg:
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
    def time_boot_ms(self):
        """Message field 'time_boot_ms'."""
        return self._time_boot_ms

    @time_boot_ms.setter
    def time_boot_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_boot_ms' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'time_boot_ms' field must be an unsigned integer in [0, 4294967295]"
        self._time_boot_ms = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lat' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lat' field must be an integer in [-2147483648, 2147483647]"
        self._lat = value

    @builtins.property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lon' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lon' field must be an integer in [-2147483648, 2147483647]"
        self._lon = value

    @builtins.property
    def alt(self):
        """Message field 'alt'."""
        return self._alt

    @alt.setter
    def alt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'alt' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'alt' field must be an integer in [-2147483648, 2147483647]"
        self._alt = value

    @builtins.property
    def relative_alt(self):
        """Message field 'relative_alt'."""
        return self._relative_alt

    @relative_alt.setter
    def relative_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'relative_alt' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'relative_alt' field must be an integer in [-2147483648, 2147483647]"
        self._relative_alt = value

    @builtins.property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vx' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'vx' field must be an integer in [-32768, 32767]"
        self._vx = value

    @builtins.property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vy' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'vy' field must be an integer in [-32768, 32767]"
        self._vy = value

    @builtins.property
    def vz(self):
        """Message field 'vz'."""
        return self._vz

    @vz.setter
    def vz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vz' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'vz' field must be an integer in [-32768, 32767]"
        self._vz = value

    @builtins.property
    def hdg(self):
        """Message field 'hdg'."""
        return self._hdg

    @hdg.setter
    def hdg(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hdg' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'hdg' field must be an unsigned integer in [0, 65535]"
        self._hdg = value
