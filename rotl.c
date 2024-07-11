#include "monty.h"

/**
 * rot1 - The function that rotates the stack to the top.
 * @stack: The double pointer to the top of the stack.
 * @line_number: The number of the current operation.
 */
void rotl(stack_t **stack, unsigned int line_number)
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

	*stack = top->next;
	(*stack)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;

	(void)line_number;
}
