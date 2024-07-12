#include "monty.h"

/**
 * push_to_queue - The function pushes an element to the queue
 * @stack: The double pointer to the stack
 * @new_node: The new node to be added
 */
void push_to_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * push - The function pushes an element to the stack or queue
 * @stack: The double pointer to the stack
 * @line_number: The line number of the current operation
 * @arg: The variable argument to push (an integer)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	stack_t *temp;
	int n;

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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
	new_node->next = NULL;

	if (global_vars.mode == 0)
	{
		new_node->next = *stack;
		if (*stack)
		{
			(*stack)->prev = new_node;
		}
		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new_node;
		}
		else
		{
			temp = *stack;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}
