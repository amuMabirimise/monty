#include "monty.h"
/**
 * main - Interpreter for monty files
 * @argc: arguments count
 * @argv: array of arguments
 * Return: 0 on SUCCESS 1 on FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		error_one();
	else
	{
		read_montyfile(argv[1]);
	}

	return (0);
}
