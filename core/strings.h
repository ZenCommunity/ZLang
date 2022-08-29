#ifndef Z_STRINGS_H
#define Z_STRINGS_H

namespace String {
    /**
     * Returns a substring given the min and max.
     * @param input
     * @param min
     * @param max
     * @return string
     */
    string sub(string &input, size_t min, size_t max) {
        return input.substr(min, max);
    };

    /**
     * Returns the length of the input.
     * @param input
     * @return size_t
     */
    size_t count(string &input) {
        return input.length();
    };

    /**
     * Returns the position of the given value.
     * @param input
     * @param search
     * @return size_at
     */
    size_t at(string &input, string &search) {
        return input.find(search);
    };

    /**
     * Determines if the given string contains the given value.
     * @param input
     * @param search
     * @return boolean
     */
    boolean contains(string &input, string &search) {
        return at(input, search) != NPOS;
    };

    /**
     * Returns everything after the given value.
     * @param input
     * @param search
     * @return string
     */
    string after(string &input, string &search) {
        size_t position = at(input, search);

        if (position == NPOS)
            throw String::NotFound();

        return sub(input, position + count(search), count(input) - count(search));
    };

    /**
     * Returns everything after the last occurrence.
     * @param input
     * @param search
     * @return string
     */
    string afterLast(string &input, string &search) {
        string copied = string(input);
        size_t position = at(copied, search);

        if (position == NPOS)
            throw String::NotFound();

        while (position != NPOS) {
            copied = sub(copied, position + count(search), count(input) - count(search));
            position = at(copied, search);
        }

        return copied;
    };

    /**
     * Returns everything before the given value.
     * @param input
     * @param search
     * @return string
     */
    string before(string &input, string &search) {
        size_t position = at(input, search);

        if (position == NPOS)
            throw String::NotFound();

        return sub(input, 0, position);
    };

    /**
     * Returns everything before the last occurrence.
     * @param input
     * @param search
     * @return string
     */
    string beforeLast(string &input, string &search) {
        string copied = string(input);
        size_t position = at(copied, search);
        size_t result;

        if (position == NPOS)
            throw String::NotFound();

        while (position != NPOS) {
            result = position;
            copied = sub(copied, position + count(search), count(input) - count(search));
            position = at(copied, search);
        }

        return sub(input, 0, result);
    };

    /**
     * Returns the portion of a string between two values.
     * @param input
     * @param start
     * @param end
     * @return string
     */
    string between(string &input, string &start, string &end) {
        string copied = string(input);
        copied = afterLast(copied, start);
        return beforeLast(copied, end);
    };

    /**
     * Returns the smallest possible portion of a string between two values.
     * @param input
     * @param start
     * @param end
     * @return
     */
    string betweenFirst(string &input, string &start, string &end) {
        string copied = string(input);
        copied = after(copied, start);
        return before(copied, end);
    };
}

#endif
