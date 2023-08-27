#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * opcode_pall - Implements the pall opcode
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void opcode_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
