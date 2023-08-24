#include "monty.h"

/**
 * free_malloc - free stack to memory.
 * @head: head of the stack.
 * Return: Always 0.
 */

void free_malloc(stack_t *head)
{
	stack_t *lista = head;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		lista = head;
		head = head->next;
		free(lista);
	}
}
/**
 * f_monty - Perform some operation related to Monty.
 * @stack: Pointer to the head of the stack.
 * @command_f: String representing the command.
 * @line_numb: Line number in the file where the command was encountered.
 *
 * Description: This function performs some Monty-specific operation based on
 * the given command and the current state of the stack.
 */
void f_monty(stack_t **stack, char *command_f, unsigned int line_numb)
{
	instruction_t f_monty[] = {
		{"pall", pall}, {"push", push}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod}, {NULL, NULL}};
	unsigned int i = 0;
	int checker = 0;

	while (i < 11 && command_f != NULL)
	{
		if (command_f[0] == '#')
			break;
		if (strcmp(f_monty[i].opcode, command_f) == 0)
		{
			f_monty[i].f(stack, line_numb);
			checker = 1;
			break;
		}
		i++;
	}
	if (checker == 0 && command_f[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_numb, command_f);
		free(command_f);
		var_glob[1] = 1;
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - Does nothing (no operation).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{

(void)stack;
(void)line_number;
}
