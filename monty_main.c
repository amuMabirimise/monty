#include "monty.h"

/**
 * main - Inteorpreter for monty files
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 on SUCCESS 1 on FAILURE
 */

FILE *file = NULL;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return (EXIT_FAILURE);
    }
    else
    {
        read_montyfile(argv[1]);
	get_free(NULL);
    }

    return (EXIT_SUCCESS);
}
