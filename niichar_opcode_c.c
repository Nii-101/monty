#include "monty.h"

/**
 * _niichar_div - A function that divides the second element
 * by the top element of the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: Current line number;
 *
 * Return: void
 */
void _niichar_div(stack_t **linked_list_head, unsigned int curr_line)
{
	int m = 0;
	char *message;
	stack_t *new_node = NULL;

	new_node = *linked_list_head;

	for (; new_node != NULL; new_node = new_node->next, m++)
		;

	if (m < 2)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't div, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: division by zero\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n /= (*linked_list_head)->n;
	_niichar_pop(linked_list_head, curr_line);
}

/**
 * _niichar_mul - A func that multiplies the top element to
 * the second top element of the stack
 *
 * @linked_list_head: Is the head of the linked list
 *
 * @curr_line: current line number;
 *
 * Return: void
 */
void _niichar_mul(stack_t **linked_list_head, unsigned int curr_line)
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
				"L%u: can't mul, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n *= (*linked_list_head)->n;
	_niichar_pop(linked_list_head, curr_line);
}

/**
 * _niichar_mod - Func that computes the rest of the division
 *  of the second element by the top element of the stack
 *
 * @linked_list_head: Is the head of the linked list
 *
 * @curr_line: current line number;
 *
 * Return: void
 */
void _niichar_mod(stack_t **linked_list_head, unsigned int curr_line)
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
				"L%u: can't mod, stack too short\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: division by zero\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}

	new_node = (*linked_list_head)->next;
	new_node->n %= (*linked_list_head)->n;
	_niichar_pop(linked_list_head, curr_line);
}

/**
 * _niichar_pchar - A func to print the char value of the first element
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: Current line number;
 *
 * Return: void
 */
void _niichar_pchar(stack_t **linked_list_head, unsigned int curr_line)
{
	char *message;

	if (linked_list_head == NULL || *linked_list_head == NULL)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't pchar, stack empty\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}
	if ((*linked_list_head)->n < 0 || (*linked_list_head)->n >= 128)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"L%u: can't pchar, value out of range\n", curr_line);
		niichar_print_out(message, 2);
		free(message);
		niichar_free_global_var(niichar_global_var);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*linked_list_head)->n);
}

/**
 * _niichar_pstr - A func that prints the string of the stack
 *
 * @linked_list_head: The head of the linked list
 *
 * @curr_line: The current line number;
 *
 * Return: void
 */
void _niichar_pstr(stack_t **linked_list_head, unsigned int curr_line)
{
	stack_t *new_node;
	(void)curr_line;

	new_node = *linked_list_head;

	while (new_node && new_node->n > 0 && new_node->n < 128)
	{
		printf("%c", new_node->n);
		new_node = new_node->next;
	}

	printf("\n");
}

