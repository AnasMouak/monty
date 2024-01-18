#include "monty.h"

/**
 * parse_line - parses a line of input and executes the opcode
 * @line: line of input to parse
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
	{
		return;
	}

	exec_opcode(opcode, stack, line_number);
}

/**
 * free_stack - frees a stack
 * @stack: double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * reverse_stack - reverses a stack
 * @stack: double pointer to the head of the stack
 */
void reverse_stack(stack_t **stack)
{
	stack_t *temp = NULL;
	stack_t *current = *stack;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		*stack = temp->prev;
	}
}
