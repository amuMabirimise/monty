#include "monty.h"

/**
 * get_free - Frees a stack_t stack
 * @stack: Pointer to the top of the stack
 */
void get_free(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

