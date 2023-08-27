#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where pall is called
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

