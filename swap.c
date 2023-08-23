#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps the two elements of the stack
 * @stack: pointers to the stack structure
 */

void swap(stack_t **stack, unsigned int line_number)
{
	if (stack->top < 1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE)
	}

	int temp = stack->data[stack->top];

	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}
