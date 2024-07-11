#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pchar_op - The function prints the char at the top of of the stack
 * @stack: the double pointer to the top of the stack.
 * @line_number: The current line number in the script file.
 *
 * Description: If the stack is empty, prints an error message and exits with
 * EXIT_FAILURE. If the value at the top of the stack is not a valid ASCII
 * character (0-127), prints an error message and exits with EXIT_FAILURE.
 * Otherwise, prints the corresponding ASCII character followed by a newline.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	int value;

	value = top->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}
