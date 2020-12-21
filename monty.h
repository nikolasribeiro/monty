#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - hold global variables
 * @return_value: return value of functions
 * @mode: mode of list
 * @command: byte code command
 * @push_value: argument to push command
 */
typedef struct global_s
{
	int return_value;
	int mode;
	char *command;
	char *push_value;
} global_t;

/* global variables */
extern global_t GLOBALS_VAR;
global_t GLOBALS_VAR;


/* print stack opcodes */
void pall(stack_t **h, unsigned int line_number);


/* push stack opcodes */
void push_node(stack_t **head, int n);
void push_node_mode(stack_t **head, unsigned int line_number);
void push_node_end(stack_t **head, int n);

/* find opcode function pointer */
int find_opcode(stack_t **head, unsigned int line_number);

/* function UTILITIES */
int is_empty(char *str);
void free_list(stack_t *head);


#endif