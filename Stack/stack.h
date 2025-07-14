#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#include "datatypes.h"
#define STACK_MAX_SIZE 5
#define STACK_DEBUG
typedef struct
{
    uint32 stack_pointer;
    uint32 data[STACK_MAX_SIZE];
}stack_t;

typedef enum
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL
}stack_status;

return_status_t satck_ptr_inti(stack_t *ptr_s);
return_status_t satck_push(stack_t *ptr_s, uint32 value);
return_status_t satck_pop(stack_t *ptr_s, uint32 *value);
return_status_t satck_top(stack_t *ptr_s, uint32 *value);
return_status_t satck_size(stack_t *ptr_s, uint32 *stack_size);
return_status_t satck_display(stack_t *ptr_s);
#endif // STACK_H
