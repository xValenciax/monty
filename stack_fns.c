#include "monty.h"

/**
 * is_empty - checks if stack contains elements
 *
 * @top: top of the stack
 *
 * Return: 1 (empty), 0 (otherwise)
 */
int is_empty(stack_t *top)
{
return (top == NULL);
}

/**
 * push - pushes a new element to the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void push(stack_t **stack, unsigned int line_number)
{
int data;
stack_t *new_top = malloc(sizeof(stack_t));
long curr_file_pos;

if (!new_top)
handle_exception(ERRNO_M, NULL, -1, NULL);

curr_file_pos = ftell(fp);
data = extract_push_val(line_number);
fseek(fp, curr_file_pos, SEEK_SET);

new_top->n = data;
new_top->prev = NULL;
if (is_empty((*stack)))
{
new_top->next = NULL;
(*stack) = new_top;
}
else
{
new_top->next = (*stack);
(*stack)->prev = new_top;
(*stack) = new_top;
}
}

/**
 * pop - removes a new element from the top of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *old_top;
if (is_empty((*stack)))
handle_exception(ERRNO_PO, NULL, line_number, NULL);

old_top = (*stack);
(*stack) = (*stack)->next;
if ((*stack) && (*stack)->prev)
(*stack)->prev = NULL;
free(old_top);
}

/**
 * display - displays stack elements to stdout
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void display(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *curr_top = *stack;
if (is_empty(curr_top))
return;
while (curr_top != NULL)
{
printf("%d\n", curr_top->n);
curr_top = curr_top->next;
}
}

/**
 * get_stack_top - returns the top of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void get_stack_top(stack_t **stack, unsigned int line_number)
{
if (is_empty((*stack)))
handle_exception(ERRNO_PI, NULL, line_number, NULL);

printf("%d\n", ((*stack)->n));
}

