#ifndef Z_VARIABLES_H
#define Z_VARIABLES_H

//typedef union _Value {
//    String * _string;
//    Boolean * _boolean;
//} Value;

enum Type {
    _UNDEFINED = 0x00000000,
    _STRING = 0x00000001,
    _BOOLEAN = 0x00000002,
    _NUMBER = 0x00000003,
    _OBJECT = 0x00000004,
};

class Value {
public:
    Type _type = _UNDEFINED;

    union {
        Number * _number;
        String * _string;
        Boolean * _boolean;
        Object * _object;
    } _value{};

    Value() {}

    Value(String * value) {
        _value._string = value;
        _type = Type::_STRING;
    }

    Value(Boolean * value) {
        _value._boolean = value;
        _type = Type::_BOOLEAN;
    }

    Value(Number * value) {
        _value._number = value;
        _type = Type::_NUMBER;
    }

    Value(Object * value) {
        _value._object = value;
        _type = Type::_NUMBER;
    }

    /**
     * Get String
     * @return
     */
    String * getString() {
        return _value._string;
    }

    /**
     * Get Boolean
     * @return
     */
    Boolean * getBoolean() {
        return _value._boolean;
    }

    /**
     * Get Number
     * @return
     */
    Number * getNumber() {
        return _value._number;
    }

    /**
     * Get Object
     * @return
     */
    Object * getObject() {
        return _value._object;
    }
};

class Variable {
public:
    String * _name;
    Value * _value;

    Variable(String * name) {
        _name = name;
        _value = {};
    };

    Variable(String * name, Value * value) {
        _name = name;
        _value = value;
    };

    /**
     * Assignee the value.
     * @param value
     */
    void setValue(Value * value) {
        _value = value;
    };

    /**
     * Returns the value.
     * @return
     */
    auto getValue() {
        return _value;
    };

    /**
     * Returns the name.
     * @return
     */
    String * getName() const {
        return _name;
    };
};
#endif
