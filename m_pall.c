#include "monty.h"

/**
 * pall - prints all the values on the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
 */

void pall(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	stack_t *current = *stack;
	(void)line_number; /* Unused, but required to match the function signature */
	(void)cmd;
	(void)fd;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
