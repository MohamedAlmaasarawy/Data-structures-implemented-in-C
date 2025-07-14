#ifndef DSTACK_H
#define DSTACK_H

#include "datatypes.h"
#include <stdlib.h>
typedef struct
{
    void **Strack_Array;
    uint32 Element_Count;
    uint32 Stack_MAX_SIZE;
    sint32 Stack_Top;
}stack_t;

typedef enum
{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}stack_status_t;

stack_t *Creat_Stack (uint32 MaxSize, stack_status_t *ret_status);
stack_t *Destroy_Stack (stack_t* stack_ptr, stack_status_t *ret_status);
stack_status_t Stack_Push (stack_t* stack_ptr, void *itemptr);
void *Stack_Pop (stack_t* stack_ptr, stack_status_t *ret_status);
void *Stack_Top (stack_t* stack_ptr, stack_status_t *ret_status);
stack_status_t Stack_Counter (stack_t* stack_ptr, uint32 *stack_count);
#endif // DSTACK_H
