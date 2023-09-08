#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes An Element To The Stack.
 * @stack: Pointer To The head
 * @line_number: The Line Number
 * Return:Void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (scanf(" %d ", &value) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - Prints All The Values On The Stack
 * @stack: Pointer To The Head
 * @line_number: Line Number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}
