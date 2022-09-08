#ifndef Z_VARIABLES_H
#define Z_VARIABLES_H

typedef variant<String, Boolean> Value;

class Variable {
public:
    string _name;

    Variable(string name, Value input) : _name(name), _value(input) {};

    /**
     * Assignee the value.
     * @param value
     */
    void setValue(Value value) {
        this->_value = value;
    };

    /**
     * Returns the value.
     * @return
     */
    Value getValue() {
        return this->_value;
    };

    /**
     * Returns the name.
     * @return
     */
    string getName() const {
        return _name;
    };
    Value _value;
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
