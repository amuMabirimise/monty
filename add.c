#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - adding the top element of the stack
 * @stack: double pointers
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack - > < 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int second_top = pop(stack);

	 stack->data[stack->top] += second_top;
}
