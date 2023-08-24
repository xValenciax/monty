#include "monty.h"

/**
 * stack_len - returns the length of the stack
 *
 * @top: top of the stack
 *
 * Return: length of the stack
 */
unsigned int stack_len(stack_t *top)
{
unsigned int len = 0;

while (top)
{
top = top->next;
len++;
}

return (len);
}

/**
 * free_stack - frees all stack members
 *
 * @stack: top of the stack
 *
 * Return: always void
 */
void free_stack(stack_t *stack)
{
stack_t *tmp = NULL;
while (stack)
{
tmp = stack;
stack = stack->next;
free(tmp);
}
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void sub(stack_t **stack, unsigned int line_number)
{
int result_sub = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_A, NULL, line_number, NULL, stack);

result_sub = (*stack)->next->n - (*stack)->n;
(*stack)->next->n = result_sub;
pop(stack, line_number);
}
