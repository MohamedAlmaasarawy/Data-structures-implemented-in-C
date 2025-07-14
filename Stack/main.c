#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "stack.h"

stack_t my_stact;

uint32 pop_top_stack = ZERO_INIT;
uint32 top_stack = ZERO_INIT;
uint32 stack_size = ZERO_INIT;

int main()
{
    return_status_t L_ret = NOK;
    L_ret = satck_ptr_inti(&my_stact);
    if(NOK == L_ret)
    {
        printf("stack pointer failed to initialized");
    }
    else
    {
        L_ret = satck_push(&my_stact, 11);
        L_ret = satck_push(&my_stact, 22);
        L_ret = satck_push(&my_stact, 33);
        L_ret = satck_push(&my_stact, 44);
        L_ret = satck_push(&my_stact, 55);
        L_ret = satck_push(&my_stact, 58);
        L_ret = satck_push(&my_stact, 59);
        L_ret = satck_pop(&my_stact, &pop_top_stack);
        L_ret = satck_pop(&my_stact, &pop_top_stack);
        L_ret = satck_display(&my_stact);
    }

    printf("==================================\n");

    L_ret = satck_pop(&my_stact, &top_stack);
    if(NOK == L_ret)
    {
        printf("Error !! \n");
    }
    else
    {
        printf("top stack = %i \n", top_stack);
    }

    printf("==================================\n");

    L_ret = satck_size(&my_stact, &stack_size);

    if(NOK == L_ret)
    {
        printf("Error !! \n");
    }
    else
    {
        printf("Size of stack is = %i \n", stack_size);
    }

    return 0;
}
