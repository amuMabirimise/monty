#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes a value onto the stack
 * @stack: Pointer to the stack structure
 * @value: Value to be pushed onto the stasck
 */

void get_push(stack_t **stack, unsigned int line_number) 
{
	if (isStackFull(stack))
	{
		fprintf(stderr, "Stack overflow\n");
		exit(EXIT_FAILURE);
	}

	stack->data[++stack->top] = value;
}
