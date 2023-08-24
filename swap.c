#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps the two elements of the stack
 * @stack: pointers to the stack structure
 * @line_number: Line number of the instruction
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
