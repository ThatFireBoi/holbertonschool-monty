#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}

/**
 * open_file - opens file
 * @filename: file to open
 * @stack: doubly linked list
 * Return: Success
 */
int open_file(char *filename, stack_t **stack)
{
	char *line = NULL;
	size_t len;
	FILE *fd;
	char *command;
	unsigned int line_number = 0;

	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fd) != EOF)
	{
		command = strtok(line, " \n\t\r$");
		line_number++;
		if (command)
			parse_command(stack, command, line_number);
	}
	fclose(fd);
	free(line);
	return (EXIT_SUCCESS);
}

void parse_command(stack_t **stack, char *op, unsigned int line_number)
{
	int i;

	instruction_t comm[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; comm[i].opcode; i++)
	{
		if (strcmp(op, comm[i].opcode) == 0)
		{
			comm[i].f(stack, line_number);
			return;
		}
	}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%i: unkown instructions %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
