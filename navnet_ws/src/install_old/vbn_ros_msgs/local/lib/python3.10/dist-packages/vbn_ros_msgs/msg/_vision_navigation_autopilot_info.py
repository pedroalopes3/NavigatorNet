# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/VisionNavigationAutopilotInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisionNavigationAutopilotInfo(type):
    """Metaclass of message 'VisionNavigationAutopilotInfo'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN': 0,
        'VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING': 1,
        'VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS': 2,
        'VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING': 4,
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
                'vbn_ros_msgs.msg.VisionNavigationAutopilotInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vision_navigation_autopilot_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vision_navigation_autopilot_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vision_navigation_autopilot_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vision_navigation_autopilot_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vision_navigation_autopilot_info

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN': cls.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN'],
            'VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING': cls.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING'],
            'VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS': cls.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS'],
            'VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING': cls.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING'],
        }

    @property
    def VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN(self):
        """Message constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN'."""
        return Metaclass_VisionNavigationAutopilotInfo.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN']

    @property
    def VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING(self):
        """Message constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING'."""
        return Metaclass_VisionNavigationAutopilotInfo.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING']

    @property
    def VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS(self):
        """Message constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS'."""
        return Metaclass_VisionNavigationAutopilotInfo.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS']

    @property
    def VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING(self):
        """Message constant 'VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING'."""
        return Metaclass_VisionNavigationAutopilotInfo.__constants['VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING']


class VisionNavigationAutopilotInfo(metaclass=Metaclass_VisionNavigationAutopilotInfo):
    """
    Message class 'VisionNavigationAutopilotInfo'.

    Constants:
      VISION_NAVIGATION_AUTOPILOT_ALARMS_UNKNOWN
      VISION_NAVIGATION_AUTOPILOT_ALARMS_IS_FLYING
      VISION_NAVIGATION_AUTOPILOT_ALARMS_GNSS
      VISION_NAVIGATION_AUTOPILOT_ALARMS_HEADING
    """

    __slots__ = [
        '_header',
        '_time_msec',
        '_alarms',
        '_lat',
        '_lng',
        '_alt_msl',
        '_pos_variance_x',
        '_pos_variance_y',
        '_pos_variance_z',
        '_vx',
        '_vy',
        '_vz',
        '_roll',
        '_pitch',
        '_yaw',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'time_msec': 'uint32',
        'alarms': 'uint8',
        'lat': 'float',
        'lng': 'float',
        'alt_msl': 'float',
        'pos_variance_x': 'float',
        'pos_variance_y': 'float',
        'pos_variance_z': 'float',
        'vx': 'float',
        'vy': 'float',
        'vz': 'float',
        'roll': 'float',
        'pitch': 'float',
        'yaw': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.time_msec = kwargs.get('time_msec', int())
        self.alarms = kwargs.get('alarms', int())
        self.lat = kwargs.get('lat', float())
        self.lng = kwargs.get('lng', float())
        self.alt_msl = kwargs.get('alt_msl', float())
        self.pos_variance_x = kwargs.get('pos_variance_x', float())
        self.pos_variance_y = kwargs.get('pos_variance_y', float())
        self.pos_variance_z = kwargs.get('pos_variance_z', float())
        self.vx = kwargs.get('vx', float())
        self.vy = kwargs.get('vy', float())
        self.vz = kwargs.get('vz', float())
        self.roll = kwargs.get('roll', float())
        self.pitch = kwargs.get('pitch', float())
        self.yaw = kwargs.get('yaw', float())

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
        if self.time_msec != other.time_msec:
            return False
        if self.alarms != other.alarms:
            return False
        if self.lat != other.lat:
            return False
        if self.lng != other.lng:
            return False
        if self.alt_msl != other.alt_msl:
            return False
        if self.pos_variance_x != other.pos_variance_x:
            return False
        if self.pos_variance_y != other.pos_variance_y:
            return False
        if self.pos_variance_z != other.pos_variance_z:
            return False
        if self.vx != other.vx:
            return False
        if self.vy != other.vy:
            return False
        if self.vz != other.vz:
            return False
        if self.roll != other.roll:
            return False
        if self.pitch != other.pitch:
            return False
        if self.yaw != other.yaw:
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
    def time_msec(self):
        """Message field 'time_msec'."""
        return self._time_msec

    @time_msec.setter
    def time_msec(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_msec' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'time_msec' field must be an unsigned integer in [0, 4294967295]"
        self._time_msec = value

    @builtins.property
    def alarms(self):
        """Message field 'alarms'."""
        return self._alarms

    @alarms.setter
    def alarms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'alarms' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'alarms' field must be an unsigned integer in [0, 255]"
        self._alarms = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lat' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lat' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lat = value

    @builtins.property
    def lng(self):
        """Message field 'lng'."""
        return self._lng

    @lng.setter
    def lng(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lng' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lng' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lng = value

    @builtins.property
    def alt_msl(self):
        """Message field 'alt_msl'."""
        return self._alt_msl

    @alt_msl.setter
    def alt_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'alt_msl' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alt_msl' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alt_msl = value

    @builtins.property
    def pos_variance_x(self):
        """Message field 'pos_variance_x'."""
        return self._pos_variance_x

    @pos_variance_x.setter
    def pos_variance_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_variance_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_variance_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_variance_x = value

    @builtins.property
    def pos_variance_y(self):
        """Message field 'pos_variance_y'."""
        return self._pos_variance_y

    @pos_variance_y.setter
    def pos_variance_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_variance_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_variance_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_variance_y = value

    @builtins.property
    def pos_variance_z(self):
        """Message field 'pos_variance_z'."""
        return self._pos_variance_z

    @pos_variance_z.setter
    def pos_variance_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_variance_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_variance_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_variance_z = value

    @builtins.property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vx = value

    @builtins.property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vy = value

    @builtins.property
    def vz(self):
        """Message field 'vz'."""
        return self._vz

    @vz.setter
    def vz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vz = value

    @builtins.property
    def roll(self):
        """Message field 'roll'."""
        return self._roll

    @roll.setter
    def roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'roll' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._roll = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value
