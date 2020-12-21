#include "monty.h"
/**
 * pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * @line_num: line number in the file with Monty bye code
 * Return: none
 */
void pall(stack_t **h, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	temp = *h;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	GLOBALS_VAR.return_value = 0;
}
