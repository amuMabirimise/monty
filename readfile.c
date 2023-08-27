#include "monty.h"

/* Function to read Monty file and process commands */
void read_montyfile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    stack_t *stack = NULL;
    char line[100];
    int line_number = 1;

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }


    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "push", strlen("push")) == 0)
        {

            char *arg = line + strlen("push") + 1;
            get_push(&stack, line_number, arg);
	}
        else if (strncmp(line, "pall", strlen("pall")) == 0)
        {
            pall(&stack, line_number);
        }

        line_number++;
    }
	fclose(file);

     get_free(stack);
}
