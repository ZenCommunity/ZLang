#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

class Output : public Object {
    Value * value;

    void read() {
    }

    /**
     * Get Number
     */
    void printNumber() {
        getline(cin, value->getString()->value_);
        value->getNumber()->value_ = stof(value->getString()->value_);
    }

    /**
     * Get String
     */
    void printString() {
        getline(cin, value->getString()->value_);
    }

    /**
     * Get Boolean
     */
    void printBoolean() {
        getline(cin, value->getString()->value_);
        value->getBoolean()->value_ = TRUE;
    }
};

struct Echo
{
    template< typename T >
    void operator() ( const T & value ) const
    {
        std::cout << value;
    }
};

ostream & operator << (ostream & os, const String * instance) {
    cout << instance->value_;
    return os;
}

ostream & operator << (ostream & os, const Boolean * instance) {
    cout << instance->value_;
    return os;
}

ostream & operator << (ostream & os, const Object * instance) {
    cout << instance->value_;
    return os;
}
#endif
