#include "monty.h"

#define MAX_LINE_LENGTH 1024

static int expand_buffer(char **lineptr, size_t *n);
static ssize_t read_line_into_buffer(char **lineptr, size_t *n, FILE *stream);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * main - The enty point for the Monty interpreter
 * @argc: The variable argument count
 * @argv: Thr variable argument vector
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	char *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			execute_instruction(opcode, arg, &stack, line_number);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * execute_instruction - The function executes the given opcode
 * @opcode: The opcode to execute
 * @arg: The variable argument
 * @stack: The double pointer to the stack
 * @line_number: The line number of the current operation
 *
 * Description: This function executes the specified Monty opcode,
 * handling 'push', 'pall', and any other valid opcodes.
 */
void execute_instruction(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", (void (*)(stack_t **, unsigned int, ...))push},
		{"pall", (void (*)(stack_t **, unsigned int, ...))pall},
		{"pint", (void (*)(stack_t **, unsigned int, ...))pint},
		{"pop", (void (*)(stack_t **, unsigned int, ...))pop},
		{"swap", (void (*)(stack_t **, unsigned int, ...))swap},
		{"add", (void (*)(stack_t **, unsigned int, ...))add},
		{"sub", (void (*)(stack_t **, unsigned int, ...))sub},
		{"div", (void (*)(stack_t **, unsigned int, ...))_div},
		{"nop", (void (*)(stack_t **, unsigned int, ...))nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				((void (*)(stack_t **, unsigned int, char *))
				 instructions[i].f)(stack, line_number, arg);
			}
			else
			{
				instructions[i].f(stack, line_number);
			}
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * getline - The ustom getline function for reading lines in C89
 * @lineptr: The pointer to the buffer storing the line read
 * @n: The pointer to the size of the buffer
 * @stream: The file stream from which to read
 *
 * Description: This function reads a line from the specified stream
 * into the buffer pointed to by lineptr. If the buffer is NULL or
 * the stream is NULL, it returns 1. If memory allocation fails, it
 * returns -1. Otherwise, it returns the number of characters read.
 *
 * Return: The number of characters read on success, or -1 on failure.
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (1);
	}
	if (*lineptr == NULL)
	{
		*n = MAX_LINE_LENGTH;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	return (read_line_into_buffer(lineptr, n, stream));
}

/**
 * read_line_into_buffer - The function reads a line from stream
 * into the line buffer.
 * @lineptr: The pointer to the buffer storing the line read
 * @n: The pointer to the size of the buffer
 * @stream: The file stream from which to read
 *
 * Return: Number of characters read on success, -1 on failure
 */
static ssize_t read_line_into_buffer(char **lineptr, size_t *n, FILE *stream)
{
	char *buf = *lineptr;
	int c;
	size_t i = 0;

	while ((c = fgetc(stream)) != EOF)
	{
		if (i + 1 >= *n && expand_buffer(lineptr, n) == -1)
		{
			return (-1);
		}
		buf = *lineptr;
		buf[i++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	if (i == 0)
	{
		return (-1);
	}
	buf[i] = '\0';
	return (i);
}

/**
 * expand_buffer - The function expands the line buffer size
 * @lineptr: The pointer to the buffer storing the line read
 * @n: The pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
static int expand_buffer(char **lineptr, size_t *n)
{
	size_t new_size = *n * 2;
	char *new_buf = realloc(*lineptr, new_size);

	if (new_buf == NULL)
	{
		return (-1);
	}

	*n = new_size;
	*lineptr = new_buf;
	return (0);
}
