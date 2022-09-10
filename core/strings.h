#ifndef Z_STRINGS_H
#define Z_STRINGS_H

#define NPOS string::npos

class String {
public:
    /**
     * Value
     */
    string value_;

    /**
     * String Constructor.
     * @param value
     */
    explicit String(string value) : value_(std::move(value)) {}

    /**
     * String Echo.
     * @param stream
     * @param string_
     * @return ostream
     */
    friend std::ostream& operator<< (ostream& stream, const String& string_) {
        cout << string_.value_;
        return stream;
    }

    /**
     * Returns the length of the input.
     * @return size_t
     */
    size_t count() {
        return value_.length();
    };

    /**
     * Returns the position of the given value.
     * @param search
     * @return size_at
     */
    size_t at(String * search) {
        return value_.find(search->value_);
    };

    /**
     * Returns a substring given the min and max.
     * @param min
     * @param max
     * @return string
     */
    String * sub(size_t min, size_t max) {
        return new String(value_.substr(min, max));
    };

    /**
     * Determines if the given string is at the start.
     * @param search
     * @return Boolean
     */
    Boolean * startsWith(String * search) {
        return new Boolean(this->at(search) == 0);
    }

    /**
     * Determines if the string is empty.
     * @return Boolean
     */
    Boolean * isEmpty() {
        return new Boolean(this->value_ == "");
    }

    /**
     * Determines if the given string is equals to the current.
     * @param search
     * @return Boolean
     */
    Boolean * equals(String * search) {
        return new Boolean(this->value_ == search->value_);
    }

    /**
     * Determines if the given string is at the start.
     * @param search
     * @return Boolean
     */
    Boolean * endsWith(String * search) {
        return new Boolean(this->at(search) == (this->count() - search->count()));
    }

    /**
     * Determines if the given string contains the given value.
     * @param search
     * @return Boolean
     */
    Boolean * contains(String * search) {
        return new Boolean(this->at(search) != NPOS);
    };

    /**
     * Returns everything after the given value.
     * @param search
     * @return string
     */
    String * after(String * search) {
        size_t position = this->at(search);

        if (position == NPOS)
            throw StringException::NotFound();

        return this->sub(position + search->count(), this->count() - search->count());
    };

    /**
     * Determines if the given string matches to the given pattern.
     * @param pattern
     * @return Boolean
     */
    Boolean * matches(String * pattern) {
        return new Boolean(regex_match(this->value_, regex(pattern->value_)) == TRUE);
    }

    /**
     * Returns a copy of the parameter.
     * @return String
     */
    String * copy() {
        return new String(value_);
    }

    /**
     * Returns everything after the last occurrence.
     * @param search
     * @return string
     */
    String * afterLast(String * search) {
        String * copy = this->copy();
        size_t position = copy->at(search);
        if (position == NPOS)
            throw StringException::NotFound();

        while (position != NPOS) {
            copy = copy->sub(position + search->count(), this->count() - search->count());
            position = copy->at(search);
        }
        return copy;
    };

    /**
     * Returns everything before the given value.
     * @param search
     * @return String
     */
    String * before(String * search) {
        size_t position = this->at(search);

        if (position == NPOS)
            throw StringException::NotFound();

        return this->sub(0, position);
    };

    /**
     * Returns everything before the last occurrence.
     * @param search
     * @return String
     */
    String * beforeLast(String * search) {
        String * copy = this->copy();
        size_t position = this->at(search);
        size_t result;

        if (position == NPOS)
            throw StringException::NotFound();

        while (position != NPOS) {
            result = position;
            copy = copy->sub(position + search->count(), this->count() - search->count());
            position = copy->at(search);
        }

        return this->sub(0, result);
    };

    /**
     * Returns the portion of a string between two values.
     * @param start
     * @param end
     * @return String
     */
    String * between(String * start, String * end) {
        String * copy = this->copy();
        copy = copy->afterLast(start);
        return copy->beforeLast(end);
    };

    /**
     * Returns the smallest possible portion of a string between two values.
     * @param start
     * @param end
     * @return String
     */
    String * betweenFirst(String * start, String * end) {
        String * copy = this->copy();
        copy = copy->after(start);
        return copy->before(end);
    };
};

#endif
