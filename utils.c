#include "monty.h"
/**
 * is_empty - checks if line needs to be tokenized
 * @str: pointer to string
 * Return: 1 if it is, 0 if not
 */
int is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_list - frees a list
 * @head: linked list to free
 * Return: none
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (1)
	{
		if (head == NULL)
			break;
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
