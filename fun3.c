#include "monty.h"

/**
 * add - sums up two elements.
 * @stack: head stack.
 * @line_number: line number in file.
 * Return: Always 0.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		var_glob[1] = 1;
		return;
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * sub - substracts top elements of the stack.
 * @stack: head stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		var_glob[1] = 1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
/**
 * _div - divides second top elements of the stack.
 * @stack: head stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		var_glob[1] = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		var_glob[1] = 1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies second top elements of the stack.
 * @stack: head stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		var_glob[1] = 1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - calculates the remainder of the division , second top elements stack.
 * @stack: head stack.
 * @line_number: line number.
 * Return: Always 0.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		var_glob[1] = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		var_glob[1] = 1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
