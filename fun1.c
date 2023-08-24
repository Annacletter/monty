#include "monty.h"

/**
 * pall - runs all elements of stack.
 * @stack: head stack.
 * @line_number: shows line number.
 * Return: Always 0.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void)line_number;
	while (h != NULL)
	{
		printf("%i\n", h->n);
		h = h->next;
	}
}

/**
 * push - Executes the pint opcode.
 * @stack: head stack.
 * @line_number: shows line number in a file.
 * Return: Always 0.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *copy = *stack;
	(void)line_number;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		var_glob[1] = 1;
		return;
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		var_glob[1] = 1;
		return;
	}
	node->prev = NULL;
	node->n = var_glob[0];
	node->next = *stack;
	if (*stack)
		copy->prev = node;
	*stack = node;
}
/**
 * pint - shows pint opcode.
 * @stack: head stack.
 * @line_number: line number in a file.
 * Return: Always 0.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		var_glob[1] = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes an element which is on top of the stack.
 * @stack: head of stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(stack);
		var_glob[1] = 1;
		return;
	}
	if (node)
	{

		*stack = (node)->next;
		free(node);
	}
}

/**
 * swap - switches two element in stack.
 * @stack: head of stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int i, j = 0;
	stack_t *copy_stack = *stack;

	while (copy_stack != NULL)
	{
		i++;
		copy_stack = copy_stack->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(stack);
		var_glob[1] = 1;
		return;
	}
	j = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = j;
}
