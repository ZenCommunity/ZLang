#ifndef Z_NUMBERS_H
#define Z_NUMBERS_H

class Number {
public:
    /**
     * Value
     */
    float value_;

    /**
     * Boolean Constructor.
     * @param value
     */
    explicit Number(float value) : value_(value) {}

    /**
     * Number Echo.
     * @param stream
     * @param number_
     * @return ostream
     */
    friend std::ostream& operator<< (ostream& stream, const Number& number_) {
        cout << number_.value_;
        return stream;
    }
};

#endif
