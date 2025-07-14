#include "stack.h"

static stack_status stack_full(stack_t *ptr_s)
{
    if(NULL == ptr_s)
    {
        printf("You passed NULL pointer to function stack full");
    }
    else if ((STACK_MAX_SIZE - 1) == ptr_s->stack_pointer)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

static stack_status stack_empty(stack_t *ptr_s)
{
    if(NULL == ptr_s)
    {
        printf("You passed NULL pointer to function stack full");
    }
    else if (-1 == ptr_s->stack_pointer)
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

return_status_t satck_ptr_inti(stack_t *ptr_s)
{
    return_status_t ret = NOK;
    if(NULL == ptr_s)
    {
        ret = NOK;
    }
    else
    {
        ptr_s->stack_pointer = -1;
        ret = OK;
    }
    return ret;
}

return_status_t satck_push(stack_t *ptr_s, uint32 value)
{
    return_status_t ret = NOK;
    if((NULL == ptr_s) || (STACK_FULL == stack_full(ptr_s)))
    {
        #ifdef STACK_DEBUG
        printf("Error stack is full !! , can't push (%i)\n", value);
        #endif // STACK_DEBUG
        ret = NOK;
    }
    else
    {
        ptr_s->stack_pointer++;
        ptr_s->data[ptr_s->stack_pointer] = value;
        #ifdef STACK_DEBUG
        printf("The value (%i) pushed to the stack. \n", value);
        #endif // STACK_DEBUG
        ret = OK;

    }
    return ret;
}

return_status_t satck_pop(stack_t *ptr_s, uint32 *value)
{
    return_status_t ret = NOK;
    if((NULL == ptr_s) || (NULL == value) ||(STACK_EMPTY == stack_empty(ptr_s)))
    {
        #ifdef STACK_DEBUG
        printf("Error stack is full !! , can't push (%i)\n", value);
        #endif // STACK_DEBUG
        ret = NOK;
    }
    else
    {
        *value = ptr_s->data[ptr_s->stack_pointer];
        ptr_s->stack_pointer--;
        #ifdef STACK_DEBUG
        printf("The top value on the stack is (%i) \n", *value);
        #endif // STACK_DEBUG
        ret = OK;
    }
    return ret;
}

return_status_t satck_top(stack_t *ptr_s, uint32 *value)
{
    return_status_t ret = NOK;
    if((NULL == ptr_s) || (NULL == value) ||(STACK_EMPTY == stack_empty(ptr_s)))
    {
        #ifdef STACK_DEBUG
        printf("Error stack is full !! , can't push (%i)\n", value);
        #endif // STACK_DEBUG
        ret = NOK;
    }
    else
    {
        *value = ptr_s->data[ptr_s->stack_pointer];
        #ifdef STACK_DEBUG
        printf("The top value (%i) is popped \n", *value);
        #endif // STACK_DEBUG
        ret = OK;
    }
    return ret;
}

return_status_t satck_size(stack_t *ptr_s, uint32 *stack_size)
{
    return_status_t ret = NOK;
    if((NULL == ptr_s) || (NULL == stack_size))
    {
        #ifdef STACK_DEBUG
        printf("Error in stack size function. \n");
        #endif // STACK_DEBUG
        ret = NOK;
    }
    else
    {
        *stack_size = (ptr_s->stack_pointer + 2);
        #ifdef STACK_DEBUG
        printf("The size of stack is (%i) \n", *stack_size);
        #endif // STACK_DEBUG
        ret = OK;
    }
    return ret;
}

return_status_t satck_display(stack_t *ptr_s)
{
    uint32 index = ZERO_INIT;
    return_status_t ret = NOK;
    if((NULL == ptr_s))
    {
        #ifdef STACK_DEBUG
        printf("Error in stack display function. \n");
        #endif // STACK_DEBUG
        ret = NOK;
    }
    else
    {
        printf("The data on the stack : ");
        for(index = ZERO_INIT; index <= ptr_s->stack_pointer; index++)
        {
            printf("%i\t", ptr_s->data[index]);
        }
        printf("\n");
        ret = OK;
    }
    return ret;
}
