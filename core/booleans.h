#ifndef Z_BOOLEANS_H
#define Z_BOOLEANS_H

class Boolean {
public:
    /**
     * Value
     */
    boolean value_;

    /**
     * Boolean Constructor.
     * @param value
     */
    explicit Boolean(boolean value) : value_(value) {}

    /**
     * Boolean Echo.
     * @param stream
     * @param boolean_
     * @return ostream
     */
    friend std::ostream& operator<< (ostream& stream, const Boolean& boolean_) {
        cout << boolean_.value_;
        return stream;
    }

    /**
     * Returns true if value is true.
     * @return
     */
    boolean isTrue() const
    {
        return value_ == TRUE;
    }

    /**
     * Returns true if value is false.
     * @return
     */
    boolean isFalse() const
    {
        return value_ == FALSE;
    }
};

#endif
