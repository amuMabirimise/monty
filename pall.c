#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pall - Prints all elements in the stack.
 * @stack: Pointer to the stack's top.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *current = *stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
