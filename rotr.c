#include "monty.h"

/**
 * rotr - The function that rotates the stack to the bottom of the stack.
 * @stack: The double pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	*stack = bottom;

	(void)line_number;
}
