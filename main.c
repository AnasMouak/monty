#include "monty.h"

global_t global;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: This is the main function for the Monty program.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	global.mode = STACK;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(1024);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 1024, file))
	{
		line_number++;
		parse_line(line, &stack, line_number);
	}

	free(line);
	fclose(file);
	free_stack(&stack);

	return (0);
}

