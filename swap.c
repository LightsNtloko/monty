#include "monty.h"

/**
 * swap - The function swaps the top two elements of the stack
 * @stack: The double pointer to the stack
 * @line_number: The current line number in the script
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	if (second->next)
	{
		second->next->prev = first;
	}

	second->next = first;
	second->prev = first->prev;
	first->prev = second;

	*stack = second;
}
