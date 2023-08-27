#include "stack.h"
#include "custom_types.h"
#include "custom_getline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack's top.
 * @line_number: Line number in the Monty file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	 char *line = NULL;
	 size_t len = 0;
	 ssize_t read;
	 char *arg = strtok(NULL, " \t\n");
	 int value = atoi(arg);
	 stack_t *new_node = malloc(sizeof(stack_t));

	read = custom_getline(&line, &len, stdin);
	if (read == -1)
	if (!arg) {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
	 if (!new_node) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;

    free(line);
}
