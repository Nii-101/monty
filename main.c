#include "monty.h"

niichar_monty_global_t niichar_global_var;

/**
 * main - The entry point
 *
 * @argc: The argument count
 *
 * @argv: string arguments vector
 *
 * Return: Returns 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file_desc;
	char *message;
	ssize_t num_lines = 0;
	size_t size = 256;
	char *splitted_lines[2] = {NULL, NULL};

	file_desc = niichar_check_input(argc, argv);
	niichar_start_global_var(file_desc, &niichar_global_var);
	num_lines = getline(&niichar_global_var.text_buffer, &size, file_desc);
	while (num_lines != -1)
	{
		splitted_lines[0] = strtok(niichar_global_var.text_buffer, " \t\n");
		if (splitted_lines[0] && splitted_lines[0][0] != '#')
		{
			f = find_niichar_opcode(splitted_lines[0]);
			if (!f)
			{
				message = malloc(sizeof(char) * NIICHAR_MAX_BUFFER_SIZE);
				snprintf(message, NIICHAR_MAX_BUFFER_SIZE, "L%u: unknown instruction %s\n",
						niichar_global_var.curr_line, splitted_lines[0]);
				niichar_print_out(message, 2);
				free(message);
				niichar_free_global_var(niichar_global_var);
				exit(EXIT_FAILURE);
			}
			niichar_global_var.arg = strtok(NULL, " \t\n");
			f(&niichar_global_var.head, niichar_global_var.curr_line);
		}
		num_lines = getline(&niichar_global_var.text_buffer, &size, file_desc);
		niichar_global_var.curr_line++;
	}

	niichar_free_global_var(niichar_global_var);

	return (0);
}

