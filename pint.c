#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 *
 * Description: Implements the pint opcode. If the stack is empty, prints an error message.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        get_free(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
    fflush(stdout);
}
