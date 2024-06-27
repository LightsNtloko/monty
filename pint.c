#include "monty.h"

/**
 * pint - The function prints the value at the top of the stack
 * @stack: The double pointer to the stack
 * @line_number: The current line number in the script file
 *
 * Description: The function checks If the stack is empty,
 * prints an error message and exits.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
