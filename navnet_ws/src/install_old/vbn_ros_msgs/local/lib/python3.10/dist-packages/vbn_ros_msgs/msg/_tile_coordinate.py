# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vbn_ros_msgs:msg/TileCoordinate.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TileCoordinate(type):
    """Metaclass of message 'TileCoordinate'."""

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
                'vbn_ros_msgs.msg.TileCoordinate')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tile_coordinate
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tile_coordinate
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tile_coordinate
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tile_coordinate
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tile_coordinate

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TileCoordinate(metaclass=Metaclass_TileCoordinate):
    """Message class 'TileCoordinate'."""

    __slots__ = [
        '_z',
        '_x',
        '_y',
        '_similarity_score',
        '_source_type',
    ]

    _fields_and_field_types = {
        'z': 'int32',
        'x': 'int32',
        'y': 'int32',
        'similarity_score': 'double',
        'source_type': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.z = kwargs.get('z', int())
        self.x = kwargs.get('x', int())
        self.y = kwargs.get('y', int())
        self.similarity_score = kwargs.get('similarity_score', float())
        self.source_type = kwargs.get('source_type', str())

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
        if self.z != other.z:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.similarity_score != other.similarity_score:
            return False
        if self.source_type != other.source_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'z' field must be an integer in [-2147483648, 2147483647]"
        self._z = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'x' field must be an integer in [-2147483648, 2147483647]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'y' field must be an integer in [-2147483648, 2147483647]"
        self._y = value

    @builtins.property
    def similarity_score(self):
        """Message field 'similarity_score'."""
        return self._similarity_score

    @similarity_score.setter
    def similarity_score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'similarity_score' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'similarity_score' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._similarity_score = value

    @builtins.property
    def source_type(self):
        """Message field 'source_type'."""
        return self._source_type

    @source_type.setter
    def source_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'source_type' field must be of type 'str'"
        self._source_type = value
