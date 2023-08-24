#include "monty.h"

/**
 * mod - calculates the moduluo of the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void mod(stack_t **stack, unsigned int line_number)
{
int result_mod = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_MOD, NULL, line_number, NULL, stack);

if (!(*stack)->n)
handle_exception(ERRNO_Z, NULL, line_number, NULL, stack);

result_mod = (*stack)->next->n % (*stack)->n;
(*stack)->next->n = result_mod;
pop(stack, line_number);
}

