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
 * sub - subtracts the top two elements of the stack
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
handle_exception(ERRNO_SU, NULL, line_number, NULL, stack);

result_sub = (*stack)->next->n - (*stack)->n;
(*stack)->next->n = result_sub;
pop(stack, line_number);
}

/**
 * sub - subtracts the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void divide(stack_t **stack, unsigned int line_number)
{
int result_div = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_D, NULL, line_number, NULL, stack);

if (!(*stack)->n)
handle_exception(ERRNO_Z, NULL, line_number, NULL, stack);

result_div = (*stack)->next->n / (*stack)->n;
(*stack)->next->n = result_div;
pop(stack, line_number);
}

/**
 * sub - subtracts the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void mul(stack_t **stack, unsigned int line_number)
{
int result_mul = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_MUL, NULL, line_number, NULL, stack);

result_mul = (*stack)->next->n * (*stack)->n;
(*stack)->next->n = result_mul;
pop(stack, line_number);
}
