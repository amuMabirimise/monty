#include "monty.h"

/**
 * get_push - function that pushes an element onto top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * @temp: Pointer to instruction
 * Description: Implements the push opcode.
 * If the input is not a valid integer, it prints an error message and exits.
 * Otherwise, it creates a new node and pushes it onto the stack.
 * Return: None
 */
void get_push(stack_t **stack, unsigned int line_number, char *temp)
{
    stack_t *new_top;
	extern FILE *file;
    (void)line_number;

    if (temp == NULL || _isdigit(temp) == 1)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        /* Assuming `file` is a global FILE pointer declared in monty.h */
        fclose(file);
        get_free(*stack);
        exit(EXIT_FAILURE);
    }

    new_top = malloc(sizeof(stack_t));
    if (new_top == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    new_top->n = atoi(temp);
    new_top->next = NULL;
    new_top->prev = NULL;

    if (*stack)
    {
        new_top->next = *stack;
        (*stack)->prev = new_top;
    }

    *stack = new_top;
}

/**
 * _isdigit - Checks if a string is a valid integer.
 * @str: The string to be checked.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int _isdigit(char *str)
{
    int i = 0;

    if (str[i] == '-')
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            return 1;
        }
        i++;
    }

    return 0;
}

