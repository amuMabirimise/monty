#include "monty.h"

/**
 * nop_data - Does nothing.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 *
 * Description: Implements the nop opcode. It doesn't perform any operations.
 */
void nop_data(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
