#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the value on the stack
 * @stack: Pointer to the stack structures
 */

void pall(Stack *stack)
{
	for (int i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->data[i])
	}
}
