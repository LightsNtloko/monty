#include "monty.h"

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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		error_exit("USAGE: monty file");
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		open_file_error(argv[1]);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode;
		char *arg;

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
 */
void execute_instruction(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", (void (*)(stack_t **, unsigned int, ...))push},
		{"pall", (void (*)(stack_t **, unsigned int, ...))pall},
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
 * The ustom getline function for reading lines in C89
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf;
	int c;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (1);
	}
	if (*lineptr == NULL) {
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	buf = *lineptr;
	while ((c = fgetc(stream)) != EOF) {
		if (i + 1 >= *n) {
			size_t new_size = *n * 2;
			char *new_buf = realloc(buf, new_size);
			if (new_buf == NULL)
			{
				return (-1);
			}
			*n = new_size;
			buf = new_buf;
			*lineptr = new_buf;
		}
		buf[i++] = c;
		if (c == '\n') {
			break;
		}
	}
		if (i == 0)
			return (-1);
		buf[i] = '\0';
		return (i);
}
