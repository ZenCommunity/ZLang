#ifndef Z_EXCEPTIONS_H
#define Z_EXCEPTIONS_H

namespace String {
    class NotFound : public std::exception {};
}

namespace Variables {
    class NotFound : public std::exception {};
}

#endif
