#ifndef MAIN_NIICHAR_MONTY_H_
#define MAIN_NIICHAR_MONTY_H_
#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

#define NIICHAR_MAX_BUFFER_SIZE 1024

/**
 * struct stack_s - d_linked_list_head linked
 * list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: d_linked_list_head linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO Holberton project
 *        */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *  * struct globals - structure to store opcode functions
 *   * @lifo: is stack or queue
 *    * @curr_line: current line
 *     * @arg: second parameter inside the current line
 *      * @head: d_linked_list_head linked list
 *       * @file_desc: file descriptor
 *        * @text_buffer: input text
 *         *
 *          * Description: d_linked_list_head linked list node structure
 *           * for niichar-monty
 *            */
typedef struct globals
{
	int lifo;
	unsigned int curr_line;
	char *arg;
	stack_t *head;
	FILE *file_desc;
	char *text_buffer;
} niichar_monty_global_t;

extern niichar_monty_global_t niichar_global_var;

/*Genral functions*/
void niichar_print_out(char *message, int message_type);
void niichar_free_global_var(niichar_monty_global_t global_var);
void niichar_start_global_var(FILE *file_desc, niichar_monty_global_t *global_var);
FILE *niichar_check_input(int argc, char *argv[]);

/* Specific opcode func to execute*/
void (*find_niichar_opcode(char *opcode))(stack_t **stack,
		unsigned int line_number);

void _niichar_push(stack_t **d_linked_list_head_stack, unsigned int line_number);
void _niichar_pall(stack_t **d_linked_list_head_stack, unsigned int line_number);
void _niichar_pint(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_pop(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_swap(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_queue(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_stack(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_add(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_nop(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_sub(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_div(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_mul(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_mod(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_pchar(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_pstr(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_rotl(stack_t **d_linked_list_head, unsigned int line_number);
void _niichar_rotr(stack_t **d_linked_list_head, unsigned int line_number);

/* Helper functions*/
stack_t *niichar_add_node_end(stack_t **head, const int n);
stack_t *niichar_add_node_start(stack_t **head, const int n);
void niichar_free_d_linked_list(stack_t *head);
#endif /* MAIN_NIICHAR_MONTY_H_ */
