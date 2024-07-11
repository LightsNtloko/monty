#include <stdio.h>
#include "monty.h"

/**
 * pstr_op - The function that prints the string starting at the
 * top of the stack.
 * @stack: The double pointer to the top of the stack
 * @line_number: The current line number in the script file.
 *
 * Description: This function prints the string starting at the0
 * top of the stack, stopping when it encounters a value of 0 or
 * a value not in the ASCII table.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
