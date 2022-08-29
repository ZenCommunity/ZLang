#ifndef Z_TYPES_H
#define Z_TYPES_H

#define NPOS string::npos
#define TRUE 1
#define FALSE 0

typedef bool boolean;
typedef int integer;
typedef variant<integer, string, boolean> value;

#endif
