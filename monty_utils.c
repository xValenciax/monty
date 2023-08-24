#include "monty.h"

FILE *fp;

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
 * extract_opcode - extracts opcode from instruction
 *
 * @instr: instruction string
 *
 * Return: return op_code
 */
char *extract_opcode(char *instr)
{
int i = 0, buff_ind = 0;
char curr_buff[BUFF_SIZE], *op_code = NULL;

for (; i < (int)strlen(instr) + 1; i++)
{
if (_islower(instr[i]))
curr_buff[buff_ind] = instr[i], buff_ind++;

if ((instr[i] == ' ' || i == (int)strlen(instr) - 1) && buff_ind > 0)
{
curr_buff[i] = '\0';
op_code = curr_buff;
break;
}
}

return (op_code);
}

/**
 * exec_instruction - executes an instruction
 *
 * @stack: top of the stack
 *
 * Return: always void
 */
void exec_instructions(stack_t **stack)
{
char buff[BUFF_SIZE], *op = NULL;
unsigned int i = 0, l_num = 0, instr_found = -1;
instruction_t instrs[] = {
{"push", push},
{"pall", display},
{"pint", get_stack_top},
{"pop", pop},
{"swap", swap},
{"add", add},
{NULL, NULL}
};
while (fgets(buff, BUFF_SIZE, fp))
{
i = 0;
l_num++;
op = extract_opcode(buff);
if (!strcmp(op, "nop"))
continue;

while (op && i < NO_FEATURES)
{
instr_found = 0;
if (!strcmp(instrs[i].opcode, op))
{
instrs[i].f(stack, l_num), instr_found = 1;
break;
}

i++;
}
if (!instr_found)
handle_exception(ERRNO_I, NULL, l_num, op);
}
}

/**
 * monty - main function that runs the whole script
 *
 * @argc: count of the arguments
 * @argv: array containing the arguments
 *
 * Return: always void
 */
void monty(int argc, char *args[])
{
int ret = check_input(argc, args);
stack_t *stack = NULL;

if (ret < 0)
handle_exception(ret, args[1], -1, NULL);

fp = fopen(args[1], "r");
exec_instructions(&stack);
fclose(fp);
}
