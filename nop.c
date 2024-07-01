#include "monty.h"

/**
 * nop - The function that dousn't do anything
 * @stack: The double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
