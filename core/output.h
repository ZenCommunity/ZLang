#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

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

#endif
