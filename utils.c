#include "monty.h"

/**
 * free_stack - The function frees a stack
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * is_integer - The function checks if a string is a valid integer
 * @str: The sting to check
 *
 * Return: 1 if the string is a integer, o otherwise
 */
int is_integer(const char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * error_exit - The function prints an error message and exit the program
 * @message: The error message to print
 */
void error_exit(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * usage_error - The function that prints a usage error message and exit the program
 * @line_number: The line number where the error occurred
 */
void usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - The function prints an error message if the file
 * can't be opened and exits
 * @filename: The name of the file that can't be opened
 */
void open_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
