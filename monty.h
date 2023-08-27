#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
size_t custom_getline(char **lineptr, size_t *n, FILE *stream);

int is_integer(const char *str);
void push(stack_t **stack, int value);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void free_stack(stack_t *stack);

#endif
