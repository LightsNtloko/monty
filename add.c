#include "monty.h"

/**
 * add - The function that adds the two elements of the stack
 * @stack: The double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;
	free(temp);
}
