#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}

/**
 * div_stack - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int divisor;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= divisor;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = product;
}

/**
 * mod - computes the remainder of the division
 * of the second top element by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = remainder;
	pop(stack, line_number);
}

