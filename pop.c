#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Remove and retturns the top element of the stack
 * @stack: Pointer to the stack structure
 *
 * Return: Value of the removed top element
 */

void pop_data(stack_t **stack, unsigned int line_number)
{
	if (isStackEmpty(stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	return (stack->data[stack->top--]);
}
