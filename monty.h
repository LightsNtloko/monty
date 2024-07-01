#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef HAVE_SSIZE_T
typedef long ssize_t;
#endif

/* Data structures */

/**
 * struct stack_s - A doubly linked list representation of a sack (or queue)
 * @n: The integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: This is a doubly linked structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - This is a opcode and its function
 * @opcode: The opcode
 * @f: The function to handle the opcode
 *
 * Description: The opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, ...);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *arg);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void execute_instruction(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number);
void free_stack(stack_t *stack);
int is_integer(const char *str);
void error_exit(char *message);
void usage_error(unsigned int line_number);
void open_file_error(char *filename);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MONTY_H */
