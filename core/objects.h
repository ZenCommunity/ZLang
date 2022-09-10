#ifndef Z_OBJECTS_H
#define Z_OBJECTS_H

#include <boost/json/src.hpp>

class Object {
public:
    boost::json::object * value_;
    /**
     * Boolean Constructor.
     * @param value
     */
    Object() {
        value_ = new boost::json::object();
    }

    /**
     * Boolean Echo.
     * @param stream
     * @param boolean_
     * @return ostream
     */
    friend std::ostream& operator<< (ostream& stream, const Object& object_) {
        cout << object_.value_;
        return stream;
    }
};

#endif
