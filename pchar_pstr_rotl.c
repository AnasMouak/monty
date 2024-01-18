#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	top = *stack;
	bottom = top;
	while (bottom->next)
	{
		bottom = bottom->next;
	}

	*stack = top->next;
	top->next->prev = NULL;
	top->next = NULL;
	bottom->next = top;
	top->prev = bottom;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *first;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}

	if (last->prev)
	{
		last->prev->next = NULL;
	}
	first = *stack;
	*stack = last;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
}
