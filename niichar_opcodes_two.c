#include "monty.h"

/**
 * _niichar_queue - sets the format of the data to a queue (FIFO)
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _niichar_queue(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;

	niichar_global_var.lifo = 0;
}

/**
 * _niichar_stack - sets the format fo the data to a stack (LIFO)
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _niichar_stack(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;

	niichar_global_var.lifo = 1;
}

/**
 * _niichar_add - adds the top two elements of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _niichar_add(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't add, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n += (*linked_list_head)->n;
	_niichar_pop(linked_list_head, curr_line);
}

/**
 * _niichar_nop - doesn't do anything
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _niichar_nop(stack_t **linked_list_head, unsigned int curr_line)
{
	(void)linked_list_head;
	(void)curr_line;
}

/**
 * _niichar_sub - subtracts the top element to the second top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @curr_line: line number;
 * Return: void
 */
void _niichar_sub(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int m = 0;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't sub, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n -= (*linked_list_head)->n;
	_niichar_pop(linked_list_head, curr_line);
}

