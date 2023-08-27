#include <stdio.h>
#include <stdlib.h>
#include "custom_types.h"
#include "custom_getline.h"

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	 size_t bufsize = *n;
    char *buffer = *lineptr;
    ssize_t num_chars = 0;
    int c;
    char *new_buffer = realloc(buffer, bufsize);

    if (!lineptr || !n || !stream) {
        return -1;
    }
	if (buffer == NULL) {
        buffer = malloc(bufsize);
        if (!buffer) {
            return -1;
        }
    }

    while (1) {
        c = fgetc(stream);

        if (c == EOF) {
            if (num_chars == 0) {
                free(buffer);
                return -1;
            }
            break;
        }

	if ((size_t)num_chars >= bufsize - 1) {
            bufsize += 256;
            if (!new_buffer) {
                free(buffer);
                return (-1);
            }
            buffer = new_buffer;
        }

        buffer[num_chars++] = (char)c;

        if (c == '\n') {
            break;
        }
    }

    buffer[num_chars] = '\0';
    *lineptr = buffer;
    *n = bufsize;

    return (num_chars);
}
