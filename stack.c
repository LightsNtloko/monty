#include "monty.h"

/**
 * stack_op - The functiion sets the mode to stack (LIFO)
 * @stack: the double pointer to the stack
 * @line_number: The line number of the current operation
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_vars.mode = 0;
}
