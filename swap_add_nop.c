#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;

	if (first->next != NULL)
	{
		first->next->prev = first;
	}
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * nop - does not do anything
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

