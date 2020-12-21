#include "monty.h"
/**
  * find_opcode - finds the opcode
  * @head: Pointer to the list
  * @line_number: number of lines in the file
  * Return: -1 on failure
  */
int find_opcode(stack_t **head, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push_node_mode},
		{"pall", pall},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strncmp(GLOBALS_VAR.command, opcodes[i].opcode,
			    strlen(GLOBALS_VAR.command)) == 0)
		{
			opcodes[i].f(head, line_number);
			return (GLOBALS_VAR.return_value);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n", line_number, GLOBALS_VAR.command);
	GLOBALS_VAR.return_value = -1;
	return (GLOBALS_VAR.return_value);
}