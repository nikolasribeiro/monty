#include "monty.h"

global_variables_t var_global;
/**
 * main - program that prints its
 * name, followed by a new line.
 * @argc: argument count
 * @argv: array of strings
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
		_error1(1);

	open_file(argv[1], &stack);
	free_nodes(stack);
	return (0);
}

/**
 * free_nodes - function that
 * frees a doubly linked list dlist_t.
 * @stack: Stack
 * Return: void
 */
void free_nodes(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		/*freeing each node allocated with malloc*/
		free(temp);
	}
}
