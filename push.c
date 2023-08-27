#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * opcode_push - Implements the push opcode
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
    char *tokenized_line = strtok(NULL, " \n");
    int value;

    if (tokenized_line == NULL || !is_integer(tokenized_line))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    value = atoi(tokenized_line);
	push(stack, value);
}
