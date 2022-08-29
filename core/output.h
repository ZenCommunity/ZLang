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

ostream & operator << (ostream & os, const Value & instance) {
    std::visit( Echo {}, instance._value);
    return os;
}

#endif
