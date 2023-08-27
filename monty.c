#include "stack.h"
#include "custom_types.h"
#include "custom_getline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	ssize_t read;
	char *opcode = strtok(line, " \t\n");
	stack_t *stack = NULL;

    if (argc != 2) {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    if (!file) {
        printf("Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

     while ((read = custom_getline(&line, &len, file)) != -1){
        line_number++;

        if (!opcode) {
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            push(&stack, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        } else {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free(line);
            return (EXIT_FAILURE);
        }
    }

    fclose(file);
    free(line);
    return (EXIT_SUCCESS);
}
