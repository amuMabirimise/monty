#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the value on the stack
 * @stack: Pointer to the stack structures
 */

void pall_data(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;
	
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
