#include "monty.h"

/**
 * queue - The function switches the mode of the stack to queue (FIFO)
 * @stack: The double pointer to the stack (unused)
 * @line_number: The current line number (unused)
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.mode = 1;
}
