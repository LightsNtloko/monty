#include "monty.h"

/**
 * sub - The function that subtracts the top element of the stack from the
 * second top element.
 * @stack:The double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
