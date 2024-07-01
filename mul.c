#include "monty.h"

/**
 * mul - The function that multiplies the second top element of the
 * stack with the top element
 * @stack: The double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
