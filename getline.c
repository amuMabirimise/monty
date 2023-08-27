#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * custom_getline - Reads a line from a file stream.
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 * Return: Number of characters read, or -1 on failure.
 */

size_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *new_lineptr = (char *)realloc(*lineptr, *n);
	size_t i = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
	*n = 128;
	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
		*n *= 2;
		if (new_lineptr == NULL)
		{
		return (-1);
		}
		*lineptr = new_lineptr;
	}

	(*lineptr)[i++] = c;

		if (c == '\n')
		{
			break;
		}
	}

	(*lineptr)[i] = '\0';

	if (i == 0 && c == EOF)
	{
		return (-1);
	}

	return (i);
}
