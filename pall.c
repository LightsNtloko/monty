#include "monty.h"

/**
 * pall - The function prints all values on the stack from top to bottom
 * @stack: The double pointer to the stack
 * @line_number: The line number of the current operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
