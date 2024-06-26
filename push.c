#include "monty.h"

/**
 * push - The function pushes an element to the stack
 * @stack: The double pointer to the stack
 * @line_number: The line number of the current operation
 * @arg: The variable argument to push (an integer)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int n;

	if (!arg || !is_integer(arg))
	{
		usage_error(line_number);
	}

	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
