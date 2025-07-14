#include "dstack.h"

static uint8 Stack_Is_Full (stack_t* stack_ptr)
{
    return (stack_ptr->Element_Count == stack_ptr->Stack_MAX_SIZE);
}

static uint8 Stack_Is_Empty (stack_t* stack_ptr)
{
    return (stack_ptr->Element_Count == 0);
}

stack_t* Creat_Stack (uint32 MaxSize, stack_status_t *ret_status)
{
    stack_t *ptr_s = NULL;
    if(NULL == ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
        ptr_s = NULL;
    }
    else
    {
        ptr_s = (stack_t*)malloc(sizeof(stack_t));
        if(NULL == ptr_s)
        {
            *ret_status = STACK_NOK;
            ptr_s = NULL;
        }
        else
        {
            ptr_s->Stack_Top = -1;
            ptr_s->Element_Count = 0;
            ptr_s->Stack_MAX_SIZE = MaxSize;
            ptr_s->Strack_Array = (void **)calloc(ptr_s->Stack_MAX_SIZE , sizeof(void *));
            if(NULL == ptr_s->Strack_Array)
            {
                *ret_status = STACK_NOK;
                ptr_s = NULL;
                free(ptr_s);
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }
    return ptr_s;
}

stack_t* Destroy_Stack (stack_t* stack_ptr, stack_status_t *ret_status)
{
    if((NULL == stack_ptr) || (NULL == ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack_ptr->Strack_Array);
        free(stack_ptr);
        *ret_status = OK;
    }
    return NULL;
}

stack_status_t Stack_Push (stack_t* stack_ptr, void *itemptr)
{
    return_status_t ret = STACK_NOK;
    if((NULL == stack_ptr) || (NULL == itemptr))
    {
        ret = STACK_NULL_POINTER;
    }
    else
    {
        if(Stack_Is_Full(stack_ptr))
        {
            ret = STACK_FULL;
        }
        else
        {
            (stack_ptr->Stack_Top)++;
            (stack_ptr->Element_Count)++;
            stack_ptr->Strack_Array[stack_ptr->Stack_Top] = itemptr;
            ret = STACK_OK;
        }
    }
    return ret;
}

void *Stack_Pop (stack_t* stack_ptr, stack_status_t *ret_status)
{
    void *data_popped = NULL;
    if((NULL == stack_ptr) || (NULL == ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
        data_popped = NULL;
    }
    else
    {
        if(Stack_Is_Empty(stack_ptr))
        {
            *ret_status = STACK_EMPTY;
            data_popped = NULL;
        }
        else
        {
            data_popped = stack_ptr->Strack_Array[stack_ptr->Stack_Top];
            (stack_ptr->Stack_Top)--;
            (stack_ptr->Element_Count)--;
            *ret_status = STACK_OK;
        }
    }
    return data_popped;
}

void * Stack_Top (stack_t* stack_ptr, stack_status_t *ret_status)
{
    void *data_popped = NULL;
    if((NULL == stack_ptr) || (NULL == ret_status))
    {
        *ret_status = STACK_NULL_POINTER;
        data_popped = NULL;
    }
    else
    {
        if(Stack_Is_Empty(stack_ptr))
        {
            *ret_status = STACK_EMPTY;
            data_popped = NULL;
        }
        else
        {
            data_popped = stack_ptr->Strack_Array[stack_ptr->Stack_Top];
            *ret_status = STACK_OK;
        }
    }
    return data_popped;
}

stack_status_t Stack_Counter (stack_t* stack_ptr, uint32 *stack_count)
{
    return_status_t ret = STACK_NOK;
    if((NULL == stack_ptr) || (NULL == stack_count))
    {
        ret = STACK_NULL_POINTER;
    }
    else
    {
        *stack_count = stack_ptr->Element_Count;
        ret = STACK_OK;
    }
    return ret;
}

