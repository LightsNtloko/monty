#include "monty.h"

/**
 * queue_op - The function sets the mode to queue (FIFO)
 * @stack: The double pointer to the stack
 * @line_number: The line number of the current operation.
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_vars.mode = 1;
}
