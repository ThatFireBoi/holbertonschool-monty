#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @param: The value to adds on the stack
  *
  * Return: Nothing
  */

void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	if (!tokens[1] || !isdigit(*tokens[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(tokens[1]);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
