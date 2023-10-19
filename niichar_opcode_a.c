#include "monty.h"

/**
 * _niichar_push - A function pushes an element to the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: Current line number
 *
 * Return: void
 */
void _niichar_push(stack_t **linked_list_head, unsigned int curr_line)
{
	int j, n;
	char *message;

	if (!niichar_global_var.arg)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: usage: push integer\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	for (j = 0; niichar_global_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(niichar_global_var.arg[j]) && niichar_global_var.arg[j] != '-')
		{
			message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
			snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
					"L%u: usage: push integer\n", curr_line);
			niichar_print_out(message, 2);
			free(message);
			niichar_free_global_var(niichar_global_var);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(niichar_global_var.arg);

	if (niichar_global_var.lifo == 1)
		niichar_add_node_start(linked_list_head, n);
	else
		niichar_add_node_end(linked_list_head, n);
}

/**
 * _niichar_pall - A function that prints all values on the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: Current line numbers
 *
 * Return: void
 */
void _niichar_pall(stack_t **linked_list_head, unsigned int curr_line)
{
	stack_t *new_node;
	(void)curr_line;

	new_node = *linked_list_head;

	while (new_node)
	{
		printf("%d\n", new_node->n);
		new_node = new_node->next;
	}
}

/**
 * _niichar_pint - A func that prints the value at the top of the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: The current line number
 *
 * Return: void
 */
void _niichar_pint(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	(void)curr_line;

	if (*linked_list_head == NULL)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't pint, stack empty\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*linked_list_head)->n);
}

/**
 * _niichar_pop - A func that removes the top element of the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: Current line number
 *
 * Return: void
 */
void _niichar_pop(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	stack_t *new_node;

	if (linked_list_head == NULL || *linked_list_head == NULL)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't pop an empty stack\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}
	new_node = *linked_list_head;
	*linked_list_head = (*linked_list_head)->next;
	free(new_node);
}

/**
 * _niichar_swap - Func that swaps the top two elements of the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: The current line number
 *
 * Return: void
 */
void _niichar_swap(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;
	int a = 0;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, a++)
		;

	if (a < 2)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't swap, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = *linked_list_head;
	*linked_list_head = (*linked_list_head)->next;
	new_node->next = (*linked_list_head)->next;
	new_node->prev = *linked_list_head;
	(*linked_list_head)->next = new_node;
	(*linked_list_head)->prev = NULL;
}

