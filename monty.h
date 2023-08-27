#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct details_s
{
    char *buf;
    char **arr_command;

} details_t;
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void get_push(stack_t **stack, unsigned int line_number, char *temp);
int _isdigit(char *str);
void get_free(stack_t *stack);
void pall(stack_t **stack, unsigned int line_number);
void read_montyfile(const char *filename);
void free_stack(stack_t *stack);
void free_details(void);
void pint(stack_t **stack, unsigned int line_number);

/* Add other function prototypes here if needed */

void error_one(void);
void error_two(char *file);
void error_three(void);
void error_four(void);
void error_five(unsigned int line_number);
void nop_data(stack_t **stack, unsigned int line_number);

#endif
