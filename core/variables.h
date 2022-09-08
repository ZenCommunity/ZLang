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
};

class Value {
public:
    Value(String * value) {
        _value._string = value;
        _type = Type::_STRING;
    }

    Value(Boolean * value) {
        _value._boolean = value;
        _type = Type::_BOOLEAN;
    }

    union {
        String * _string;
        Boolean * _boolean;
    } _value{};

    Type _type = _UNDEFINED;
};

class Variable {
public:
    string _name;
    Value * _value;

    Variable(string name) {
        _name = name;
        _value = {};
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
        return _value->_value;
    };

    /**
     * Returns the name.
     * @return
     */
    string getName() const {
        return _name;
    };
};

class Storage {
public:
    std::vector<Variable> variables;

    /**
     * Insert variable into stack.
     * @param variable
     */
    void insert(Variable & variable) {
        variables.push_back(variable);
    };

    /**
     * Get variable from stack.
     * @param name
     * @return
     */
    Variable get(string & name) {
        for (Variable variable : variables)
        {
            if (variable._name == name) {
                return variable;
            }
        }
        throw Variables::NotFound();
    };

    /**
     * Determines if the given string exists as variable on the stack.
     * @param name
     * @return
     */
    boolean exists(string & name) {
        return std::ranges::any_of(variables, [name](Variable & variable)
        {
            return variable._name == name;
        });
    };
};
#endif
