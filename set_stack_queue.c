#include "monty.h"

/**
 * set_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global.mode = STACK;
}

/**
 * set_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global.mode = QUEUE;
}

