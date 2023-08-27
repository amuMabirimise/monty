#include "monty.h"

/**
 * pop_data - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 *
 * Description: Implements the pop opcode. Removes the top element from the stack.
 * If the stack is empty, prints an error message.
 */
void pop_data(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_details();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
	(*stack)->prev = NULL;
	free(temp);
}
