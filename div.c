#include "monty.h"

/**
 * _div - The function that devides the second top element of the stack by the
 * top element of the stack.
 * @stack: The double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
