#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include "getline.c"
/**
 * main - Entry point for the Monty program
 * @argc: Argument count
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    char *opcode = strtok(line, " \n");
    stack_t *stack = NULL;
    int i = 0;
        char *current_opcode = NULL;
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

	while (getline(&line, &len, file) != -1)
    {
        line_number++;
        if (opcode == NULL || opcode[0] == '#')
            continue;

        while ((current_opcode = opcodes[i].opcode) != NULL)
        {
            if (strcmp(opcode, current_opcode) == 0)
            {
                opcodes[i].f(&stack, line_number);
                break;
            }
            i++;
        }

        if (current_opcode == NULL)
        {
            printf("L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(stack);
            return (EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (EXIT_SUCCESS);
}
