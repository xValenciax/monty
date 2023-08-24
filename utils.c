#include "monty.h"

/**
 * _isdigit - checks if input is digit or not
 *
 * @c: char to be checked
 *
 * Return: 1 if char is digit, 0 otherwise
 */

int _isdigit(int c)
{
if (c >= 48 && c < 58)
return (1);

return (0);
}

/**
 * _islower - checks whether char is lower or upper case
 *
 * @c: character to be checked
 *
 * Return: 1 if char is lowercase, 0 otherwise
 */

int _islower(int c)
{
if (c >= 97 && c <= 122)
return (1);
return (0);
}

/**
 * extract_push_val - extracts the data from push instruction
 *
 * @line_number: number of the line of the instruction
 *
 * Return: the data found in the instructions
 */
int extract_push_val(stack_t **stack, unsigned int line_number)
{
char line_buff[BUFF_SIZE], curr_buff[32];
unsigned int i = 0, ind = 0, val = 0, line_count = 1;
int is_neg = 0;

memset(curr_buff, 0, BUFF_SIZE);
fseek(fp, 0, SEEK_SET);
while (fgets(line_buff, BUFF_SIZE, fp))
{
while (line_count == line_number && line_buff[i])
{
if (_isdigit(line_buff[i]))
{
if (line_buff[i - 1] == '-')
is_neg = 1;
while (_isdigit(line_buff[i]))
curr_buff[ind] = line_buff[i], ind++, i++;

if (_islower(line_buff[i]))
handle_exception(ERRNO_P, NULL, line_number, NULL, stack);
}

if (ind > 0)
{
curr_buff[ind + 1] = '\0';
val = atoi(curr_buff);
return (is_neg ? (-1 * val) : (val));
}
i++;
}
line_count++;
}
handle_exception(ERRNO_P, NULL, line_number, NULL, stack);
return (val);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void swap(stack_t **stack, unsigned int line_number)
{
int temp = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_S, NULL, line_number, NULL, stack);

temp = (*stack)->next->n;
(*stack)->next->n = (*stack)->n;
(*stack)->n = temp;
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: top of the stack
 * @line_number: line number of the instruction
 *
 * Return: always void
 */
void add(stack_t **stack, unsigned int line_number)
{
int result_add = 0;
unsigned int len = stack_len((*stack));

if (len < 2)
handle_exception(ERRNO_A, NULL, line_number, NULL, stack);

result_add = (*stack)->n + (*stack)->next->n;
(*stack)->next->n = result_add;
pop(stack, line_number);
}
