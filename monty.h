#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define ERR_FILE "Error: Can't open file %s\n"
#define ERRNO_F -1

#define ERR_USAGE "USAGE: monty file\n"
#define ERRNO_U -2

#define ERR_INST "L%d: unknown instruction %s\n"
#define ERRNO_I -3

#define ERR_MLOC "Error: malloc failed\n"
#define ERRNO_M -4

#define ERR_PUSH "L%d: usage: push integer\n"
#define ERRNO_P -5

#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERRNO_PI -6

#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERRNO_PO -7

#define ERR_SWAP "L%d: can't swap, stack too short\n"
#define ERRNO_S -8

#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERRNO_A -9

#define BUFF_SIZE 1024

#define NO_FEATURES 6

extern FILE *fp;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Monty Utils */
void monty(int argc, char *args[]);
void exec_instructions(stack_t **stack);

/* Error Handling */
int check_input(int argc, char *args[]);
void handle_exception(int err, char *f, int l_no, char *opcode);
char *extract_opcode(char *instr);

/* Stack Operations */
int is_empty(stack_t *top);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void display(stack_t **stack, unsigned int line_number);
void get_stack_top(stack_t **stack, unsigned int line_number);
unsigned int stack_len(stack_t *top);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* General Utils */
int _isdigit(int c);
int _islower(int c);
int extract_push_val(unsigned int line_number);

#endif
