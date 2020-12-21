#include "monty.h"
/**
 * main - entry point for Monty project
 * @ac: number of arguments
 * @av: array of pointers to those arguments
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	unsigned int line_number; size_t line_len; FILE * fp;
	char *line;
	stack_t *list_head; int len;

	GLOBALS_VAR.return_value = 0;
	GLOBALS_VAR.mode = 0;
	GLOBALS_VAR.command = NULL;
	GLOBALS_VAR.push_value = NULL;

	line = NULL; list_head = NULL; len = 0; line_number = 0; line_len = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((len = getline(&line, &line_len, fp)) != -1)
	{
		line_number++;

		if (!(line[0] == '\n') && !(line[0] == '#') && !is_empty(line))
		{
			if (GLOBALS_VAR.command[0] == '#')
				continue;

			GLOBALS_VAR.return_value = find_opcode(&list_head, line_number);
            
			if (GLOBALS_VAR.return_value == -1)
			{
				break;
			}
		}
	}
	free(line); free_list(list_head); fclose(fp);
	if (GLOBALS_VAR.return_value == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
