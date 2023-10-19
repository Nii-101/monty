#include "monty.h"

/**
 *niichar_print_out - Funtion to print to the terminal
 *
 * @message: a pointer to the message to be written
 *
 * @message_type: The type of output to the terminal
 *
 * Return: void
 */
void niichar_print_out(char *message, int message_type)
{
	write(message_type, message, strlen(message));
}

/**
 * niichar_free_global_var - A function that frees the global variables
 *
 * @global_var: A global variable to be freed
 *
 * Return: void
 */
void niichar_free_global_var(niichar_monty_global_t global_var)
{
	niichar_free_d_linked_list(global_var.head);
	free(global_var.text_buffer);
	fclose(global_var.file_desc);
}

/**
 * niichar_start_global_var - A functio that nitializes the global variables
 *
 * @file_desc: The file descriptor
 *
 * @global_var: A pointer to a global variable
 *
 * Return: void
 *
 */
void niichar_start_global_var(FILE *file_desc,
		niichar_monty_global_t *global_var)
{
	global_var->lifo = 1;
	global_var->curr_line = 1;
	global_var->arg = NULL;
	global_var->head = NULL;
	global_var->file_desc = file_desc;
	global_var->text_buffer = NULL;
}

/**
 * niichar_check_input - A function that checks if
 *  the file exists and if the file can be opened
 *
 * @argc: Argument count
 *
 * @argv: Argument vector
 *
 * Return: Returns file struct
 *
 */
FILE *niichar_check_input(int argc, char *argv[])
{
	FILE *file_desc;
	char *message;

	if (argc == 1 || argc > 2)
	{
		niichar_print_out("USAGE: monty file\n", 2);
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(argv[1], "r");

	if (file_desc == NULL)
	{
		message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
		snprintf(message, NIICHAR_MAX_BUFFER_SIZE,
				"Error: Can't open file %s\n", argv[1]);
		niichar_print_out(message, 2);
		free(message);
		exit(EXIT_FAILURE);
	}

	return (file_desc);
}

/**
 * find_niichar_opcode - Func that chooses the correct opcode to execute
 *
 * @line_number: The line number
 *
 * Return: A pointer to the function that executes the opcode
 *
 */
void (*find_niichar_opcode(char *opcode))(stack_t **stack,
		unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _niichar_push},
		{"pall", _niichar_pall},
		{"pint", _niichar_pint},
		{"pop", _niichar_pop},
		{"swap", _niichar_swap},
		{"queue", _niichar_queue},
		{"stack", _niichar_stack},
		{"add", _niichar_add},
		{"nop", _niichar_nop},
		{"sub", _niichar_sub},
		{"mul", _niichar_mul},
		{"div", _niichar_div},
		{"mod", _niichar_mod},
		{"pchar", _niichar_pchar},
		{"pstr", _niichar_pstr},
		{"rotl", _niichar_rotl},
		{"rotr", _niichar_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);
}

