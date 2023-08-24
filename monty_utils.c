#include "monty.h"

FILE *fp;

/**
 * extract_opcode - extracts opcode from instruction
 *
 * @instr: instruction string
 * @stack: top of the stack
 * @l_num: line number of instruction
 * @instrs: array of available instructions
 *
 * Return: return op_code
 */
int extract_opcode(char *instr, stack_t **stack, unsigned int l_num, instruction_t instrs[])
{
int i = 0, buff_ind = 0, instr_found = -1;
char curr_buff[BUFF_SIZE];

memset(curr_buff, '\0', BUFF_SIZE);

for (; i < (int)strlen(instr) + 1; i++)
{
if (_islower(instr[i]))
curr_buff[buff_ind] = instr[i], buff_ind++;
if ((instr[i] == ' ' || i == (int)strlen(instr) - 1) && buff_ind > 0)
{
curr_buff[buff_ind + 1] = '\0';
break;
}
}

if (curr_buff[0] == '\0' || !strcmp(curr_buff, "nop"))
return (1);

i = 0;
while (i < NO_FEATURES)
{
instr_found = 0;
if (instrs[i].opcode && !strcmp(instrs[i].opcode, curr_buff))
{
instrs[i].f(stack, l_num), instr_found = 1;
break;
}
i++;
}

if (!instr_found)
handle_exception(ERRNO_I, NULL, l_num, curr_buff, stack);

return (0);
}

/**
 * exec_instructions - executes an instruction
 *
 * @stack: top of the stack
 *
 * Return: always void
 */
void exec_instructions(stack_t **stack)
{
char buff[BUFF_SIZE];
unsigned int l_num = 0;
instruction_t instrs[] = {
{"push", push},
{"pall", display},
{"pint", get_stack_top},
{"pop", pop},
{"swap", swap},
{"add", add},
{"sub", sub},
{NULL, NULL}
};

memset(buff, 0, BUFF_SIZE);
while (fgets(buff, BUFF_SIZE, fp))
{
l_num++;
extract_opcode(buff, stack, l_num, instrs);
}
}

/**
 * monty - main function that runs the whole script
 *
 * @argc: count of the arguments
 * @args: array containing the arguments
 *
 * Return: always void
 */
void monty(int argc, char *args[])
{
int ret = check_input(argc, args);
stack_t *stack = NULL;

if (ret < 0)
handle_exception(ret, args[1], -1, NULL, &stack);

fp = fopen(args[1], "r");
exec_instructions(&stack);
if (stack)
free_stack(stack);
if (fp)
fclose(fp);
}
