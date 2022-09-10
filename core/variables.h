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
};

class Value {
public:
    Type _type = _UNDEFINED;

    union {
        Number * _number;
        String * _string;
        Boolean * _boolean;
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

class Storage {
public:
    vector<Variable *> variables;

    /**
     * Insert variable into stack.
     * @param variable
     */
    void insert(Variable * variable) {
        variables.push_back(variable);
    };

    /**
     * Get variable from stack.
     * @param name
     * @return
     */
    Variable * get(String * name) {
        for (Variable * variable : variables)
        {
            if (variable->getName()
                        ->equals(name)
                        ->isTrue()) {
                return variable;
            }
        }
        throw Variables::NotFound();
    };

    /**
     * Debug
     * @param name
     */
    void debug() {
        cout << "============ START DEBUG ============" << endl;
        for (Variable * variable : variables)
        {
            if (variable->getValue())
            cout << "Name: " << *variable->getName() << "     Value: ";
            switch (variable->getValue()->_type) {
                case _UNDEFINED:
                    cout << "UNDEFINED" << endl;
                    break;
                case _STRING:
                    cout << *variable->getValue()->getString() << endl;
                    break;
                case _BOOLEAN:
                    cout << *variable->getValue()->getBoolean() << endl;
                    break;
                case _NUMBER:
                    cout << *variable->getValue()->getNumber() << endl;
                    break;
            }
        }
        cout << "============  END DEBUG  ============" << endl;
    };

    /**
     * Determines if the given string exists as variable on the stack.
     * @param name
     * @return
     */
    Boolean * exists(String * name) {
        return new Boolean(ranges::any_of(variables, [name](Variable * variable) {
            return variable->getName()
                           ->equals(name)->isTrue();
        }));
    };
};
#endif
