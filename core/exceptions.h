#ifndef Z_EXCEPTIONS_H
#define Z_EXCEPTIONS_H

class BaseException : public std::exception {
private:
    string message_ = "Something went wrong";
public:
    BaseException() = default;
    char * what () {
        return message_.data();
    }
};

namespace StringException {
    class NotFound : public BaseException {
    private:
        string message_ = "String Not Found";
    };
}

namespace Variables {
    class NotFound : public BaseException {
    private:
        string message_ = "Variable Not Found";
    };
}

namespace Syntax {
    class Error : public BaseException {
    private:
        string message_ = "Syntax Error";
    };
}

#endif
