#include <stdio.h>
#include <stdlib.h>

#include "dstack.h"

uint32 my_stack_size;
stack_t *my_stack;
uint32 count;
void *sta_ptr;

uint32 Var1 = 0x11;
uint16 Var2 = 7;
uint8 Var3 = 'a';
int main()
{
    return_status_t ret = STACK_NOK;

    printf("Pls enter the stack size : ");
    scanf("%i", &my_stack_size);

    /* check on create function */
    my_stack = Creat_Stack(my_stack_size, &ret);
    printf("ret = %i\n", ret);
    if(my_stack)
    {
        printf("stack had been created. \n");
    }

    /* check on stack push */
    ret = Stack_Push(my_stack, &Var1);printf("ret Var1 = %i\n", ret);
    ret = Stack_Push(my_stack, &Var2);printf("ret Var2 = %i\n", ret);
    ret = Stack_Push(my_stack, &Var3);printf("ret Var3 = %i\n", ret);
    ret = Stack_Push(my_stack, &Var3);printf("ret Var3 = %i\n", ret);

    ret = Stack_Counter(my_stack, &count);printf("ret count = %i\n", ret);
    printf("count = %i \n", count);

    /* check on stack top */
    sta_ptr = Stack_Top(my_stack, &ret);printf("ret top = %i\n", ret);
    printf("top of stack = %c \n", *(char *)sta_ptr);

    /* check on stack pop */
    sta_ptr = Stack_Pop(my_stack, &ret);printf("ret pop = %i\n", ret);
    printf("pop from stack = %c \n", *(char *)sta_ptr);
    sta_ptr = Stack_Pop(my_stack, &ret);printf("ret pop = %i\n", ret);
    printf("pop from stack = %i \n", *(uint16 *)sta_ptr);
    sta_ptr = Stack_Pop(my_stack, &ret);printf("ret pop = %i\n", ret);
    printf("pop from stack = 0x%X \n", *(uint32 *)sta_ptr);

    /* check on destroy function */
    my_stack = Destroy_Stack(my_stack, &ret);
    printf("ret = %i\n", ret);
    if(!my_stack)
    {
        printf("stack had been destroyed. \n");
    }
    return 0;
}
