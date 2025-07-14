#ifndef DATATYPES_H
#define  DATATYPES_H

#define ZERO_INIT 0

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef float float32;
typedef signed short sint16;
typedef signed int sint32;

typedef enum return_status
{
    NOK,
    OK
}return_status_t;
#endif // DATATYPES_H
