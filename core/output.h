#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

ostream & operator << (ostream & os, const Value & instance) {
    std::visit( Echo {}, instance._value);
    return os;
}

#endif
