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
	stack_t *head;
	(void)line_number;

	if (*stack == NULL)
		error_six();

	head = *stack;
	head = head->next;
	free(*stack);
	*stack = head;
	if(head != NULL)
		head->prev = NULL;
}
