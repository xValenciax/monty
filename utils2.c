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
