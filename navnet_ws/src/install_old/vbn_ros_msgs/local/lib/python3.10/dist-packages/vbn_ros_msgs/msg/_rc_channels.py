# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/RCChannels.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RCChannels(type):
    """Metaclass of message 'RCChannels'."""

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
                'vbn_ros_msgs.msg.RCChannels')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rc_channels
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rc_channels
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rc_channels
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rc_channels
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rc_channels

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


class RCChannels(metaclass=Metaclass_RCChannels):
    """Message class 'RCChannels'."""

    __slots__ = [
        '_header',
        '_time_boot_ms',
        '_chancount',
        '_chan1_raw',
        '_chan2_raw',
        '_chan3_raw',
        '_chan4_raw',
        '_chan5_raw',
        '_chan6_raw',
        '_chan7_raw',
        '_chan8_raw',
        '_chan9_raw',
        '_chan10_raw',
        '_chan11_raw',
        '_chan12_raw',
        '_chan13_raw',
        '_chan14_raw',
        '_chan15_raw',
        '_chan16_raw',
        '_chan17_raw',
        '_chan18_raw',
        '_rssi',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'time_boot_ms': 'uint32',
        'chancount': 'uint8',
        'chan1_raw': 'uint16',
        'chan2_raw': 'uint16',
        'chan3_raw': 'uint16',
        'chan4_raw': 'uint16',
        'chan5_raw': 'uint16',
        'chan6_raw': 'uint16',
        'chan7_raw': 'uint16',
        'chan8_raw': 'uint16',
        'chan9_raw': 'uint16',
        'chan10_raw': 'uint16',
        'chan11_raw': 'uint16',
        'chan12_raw': 'uint16',
        'chan13_raw': 'uint16',
        'chan14_raw': 'uint16',
        'chan15_raw': 'uint16',
        'chan16_raw': 'uint16',
        'chan17_raw': 'uint16',
        'chan18_raw': 'uint16',
        'rssi': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.time_boot_ms = kwargs.get('time_boot_ms', int())
        self.chancount = kwargs.get('chancount', int())
        self.chan1_raw = kwargs.get('chan1_raw', int())
        self.chan2_raw = kwargs.get('chan2_raw', int())
        self.chan3_raw = kwargs.get('chan3_raw', int())
        self.chan4_raw = kwargs.get('chan4_raw', int())
        self.chan5_raw = kwargs.get('chan5_raw', int())
        self.chan6_raw = kwargs.get('chan6_raw', int())
        self.chan7_raw = kwargs.get('chan7_raw', int())
        self.chan8_raw = kwargs.get('chan8_raw', int())
        self.chan9_raw = kwargs.get('chan9_raw', int())
        self.chan10_raw = kwargs.get('chan10_raw', int())
        self.chan11_raw = kwargs.get('chan11_raw', int())
        self.chan12_raw = kwargs.get('chan12_raw', int())
        self.chan13_raw = kwargs.get('chan13_raw', int())
        self.chan14_raw = kwargs.get('chan14_raw', int())
        self.chan15_raw = kwargs.get('chan15_raw', int())
        self.chan16_raw = kwargs.get('chan16_raw', int())
        self.chan17_raw = kwargs.get('chan17_raw', int())
        self.chan18_raw = kwargs.get('chan18_raw', int())
        self.rssi = kwargs.get('rssi', int())

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
        if self.chancount != other.chancount:
            return False
        if self.chan1_raw != other.chan1_raw:
            return False
        if self.chan2_raw != other.chan2_raw:
            return False
        if self.chan3_raw != other.chan3_raw:
            return False
        if self.chan4_raw != other.chan4_raw:
            return False
        if self.chan5_raw != other.chan5_raw:
            return False
        if self.chan6_raw != other.chan6_raw:
            return False
        if self.chan7_raw != other.chan7_raw:
            return False
        if self.chan8_raw != other.chan8_raw:
            return False
        if self.chan9_raw != other.chan9_raw:
            return False
        if self.chan10_raw != other.chan10_raw:
            return False
        if self.chan11_raw != other.chan11_raw:
            return False
        if self.chan12_raw != other.chan12_raw:
            return False
        if self.chan13_raw != other.chan13_raw:
            return False
        if self.chan14_raw != other.chan14_raw:
            return False
        if self.chan15_raw != other.chan15_raw:
            return False
        if self.chan16_raw != other.chan16_raw:
            return False
        if self.chan17_raw != other.chan17_raw:
            return False
        if self.chan18_raw != other.chan18_raw:
            return False
        if self.rssi != other.rssi:
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
    def chancount(self):
        """Message field 'chancount'."""
        return self._chancount

    @chancount.setter
    def chancount(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chancount' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'chancount' field must be an unsigned integer in [0, 255]"
        self._chancount = value

    @builtins.property
    def chan1_raw(self):
        """Message field 'chan1_raw'."""
        return self._chan1_raw

    @chan1_raw.setter
    def chan1_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan1_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan1_raw' field must be an unsigned integer in [0, 65535]"
        self._chan1_raw = value

    @builtins.property
    def chan2_raw(self):
        """Message field 'chan2_raw'."""
        return self._chan2_raw

    @chan2_raw.setter
    def chan2_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan2_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan2_raw' field must be an unsigned integer in [0, 65535]"
        self._chan2_raw = value

    @builtins.property
    def chan3_raw(self):
        """Message field 'chan3_raw'."""
        return self._chan3_raw

    @chan3_raw.setter
    def chan3_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan3_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan3_raw' field must be an unsigned integer in [0, 65535]"
        self._chan3_raw = value

    @builtins.property
    def chan4_raw(self):
        """Message field 'chan4_raw'."""
        return self._chan4_raw

    @chan4_raw.setter
    def chan4_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan4_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan4_raw' field must be an unsigned integer in [0, 65535]"
        self._chan4_raw = value

    @builtins.property
    def chan5_raw(self):
        """Message field 'chan5_raw'."""
        return self._chan5_raw

    @chan5_raw.setter
    def chan5_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan5_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan5_raw' field must be an unsigned integer in [0, 65535]"
        self._chan5_raw = value

    @builtins.property
    def chan6_raw(self):
        """Message field 'chan6_raw'."""
        return self._chan6_raw

    @chan6_raw.setter
    def chan6_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan6_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan6_raw' field must be an unsigned integer in [0, 65535]"
        self._chan6_raw = value

    @builtins.property
    def chan7_raw(self):
        """Message field 'chan7_raw'."""
        return self._chan7_raw

    @chan7_raw.setter
    def chan7_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan7_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan7_raw' field must be an unsigned integer in [0, 65535]"
        self._chan7_raw = value

    @builtins.property
    def chan8_raw(self):
        """Message field 'chan8_raw'."""
        return self._chan8_raw

    @chan8_raw.setter
    def chan8_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan8_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan8_raw' field must be an unsigned integer in [0, 65535]"
        self._chan8_raw = value

    @builtins.property
    def chan9_raw(self):
        """Message field 'chan9_raw'."""
        return self._chan9_raw

    @chan9_raw.setter
    def chan9_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan9_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan9_raw' field must be an unsigned integer in [0, 65535]"
        self._chan9_raw = value

    @builtins.property
    def chan10_raw(self):
        """Message field 'chan10_raw'."""
        return self._chan10_raw

    @chan10_raw.setter
    def chan10_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan10_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan10_raw' field must be an unsigned integer in [0, 65535]"
        self._chan10_raw = value

    @builtins.property
    def chan11_raw(self):
        """Message field 'chan11_raw'."""
        return self._chan11_raw

    @chan11_raw.setter
    def chan11_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan11_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan11_raw' field must be an unsigned integer in [0, 65535]"
        self._chan11_raw = value

    @builtins.property
    def chan12_raw(self):
        """Message field 'chan12_raw'."""
        return self._chan12_raw

    @chan12_raw.setter
    def chan12_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan12_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan12_raw' field must be an unsigned integer in [0, 65535]"
        self._chan12_raw = value

    @builtins.property
    def chan13_raw(self):
        """Message field 'chan13_raw'."""
        return self._chan13_raw

    @chan13_raw.setter
    def chan13_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan13_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan13_raw' field must be an unsigned integer in [0, 65535]"
        self._chan13_raw = value

    @builtins.property
    def chan14_raw(self):
        """Message field 'chan14_raw'."""
        return self._chan14_raw

    @chan14_raw.setter
    def chan14_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan14_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan14_raw' field must be an unsigned integer in [0, 65535]"
        self._chan14_raw = value

    @builtins.property
    def chan15_raw(self):
        """Message field 'chan15_raw'."""
        return self._chan15_raw

    @chan15_raw.setter
    def chan15_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan15_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan15_raw' field must be an unsigned integer in [0, 65535]"
        self._chan15_raw = value

    @builtins.property
    def chan16_raw(self):
        """Message field 'chan16_raw'."""
        return self._chan16_raw

    @chan16_raw.setter
    def chan16_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan16_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan16_raw' field must be an unsigned integer in [0, 65535]"
        self._chan16_raw = value

    @builtins.property
    def chan17_raw(self):
        """Message field 'chan17_raw'."""
        return self._chan17_raw

    @chan17_raw.setter
    def chan17_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan17_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan17_raw' field must be an unsigned integer in [0, 65535]"
        self._chan17_raw = value

    @builtins.property
    def chan18_raw(self):
        """Message field 'chan18_raw'."""
        return self._chan18_raw

    @chan18_raw.setter
    def chan18_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chan18_raw' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'chan18_raw' field must be an unsigned integer in [0, 65535]"
        self._chan18_raw = value

    @builtins.property
    def rssi(self):
        """Message field 'rssi'."""
        return self._rssi

    @rssi.setter
    def rssi(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rssi' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rssi' field must be an unsigned integer in [0, 255]"
        self._rssi = value
