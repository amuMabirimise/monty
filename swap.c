#include "monty.h"

/**
 * swap_data - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 *
 * Description: Implements the swap opcode. Swaps the values of the top two elements.
 * If the stack contains less than two elements, prints an error message.
 */
void swap_data(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_details();
	exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
