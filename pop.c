#include "monty.h"

/**
 * pop - The function removes the top element of the stack
 * @stack: The double pointer to the stack
 * @line_number: The current line number in the script
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
