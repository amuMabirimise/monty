#include "monty.h"
details_t details;
/**
 * free_details - Frees memory allocated for details structure
 */
void free_details(void)
{
    if (details.buf != NULL)
    {
        free(details.buf);
        details.buf = NULL;
    }

    if (details.arr_command != NULL)
    {
        free(details.arr_command);
        details.arr_command = NULL;
    }
}

/**
 * free_stack - Frees a stack_t stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *n;

    while (stack != NULL)
    {
        n = stack;
        stack = stack->next;
        free(n);
    }
}

