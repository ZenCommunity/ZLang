#ifndef Z_INPUT_H
#define Z_INPUT_H

class Input {
    Value * value;

    Input() {}

    void read() {
    }

    /**
     * Get Number
     */
    void getNumber() {
        getline(cin, value->getString()->value_);
        value->getNumber()->value_ = stof(value->getString()->value_);
    }

    /**
     * Get String
     */
    void getString() {
        getline(cin, value->getString()->value_);
    }

    /**
     * Get Boolean
     */
    void getBoolean() {
        getline(cin, value->getString()->value_);
        value->getBoolean()->value_ = TRUE;
    }
};
#endif
