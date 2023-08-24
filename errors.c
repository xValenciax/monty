#include "monty.h"

/**
 * handle_exception - checks for any exception thrown by the script
 * and returns the corresponding error message
 *
 * @err: error number
 * @f: name of the user passed file
 * @l_no: line number of the error
 * @opcode: instruction's opcode
 * @top: top of the stack
 *
 * Return: always void
 */
void handle_exception(int err, char *f, int l_no, char *opcode, stack_t **top)
{
switch (err)
{
case ERRNO_F:
fprintf(stderr, ERR_FILE, f);
break;
case ERRNO_U:
fprintf(stderr, ERR_USAGE);
break;
case ERRNO_I:
fprintf(stderr, ERR_INST, l_no, opcode);
break;
case ERRNO_M:
fprintf(stderr, ERR_MLOC);
break;
case ERRNO_P:
fprintf(stderr, ERR_PUSH, l_no);
break;
case ERRNO_PI:
fprintf(stderr, ERR_PINT, l_no);
break;
case ERRNO_PO:
fprintf(stderr, ERR_POP, l_no);
break;
case ERRNO_S:
fprintf(stderr, ERR_SWAP, l_no);
break;
case ERRNO_A:
fprintf(stderr, ERR_ADD, l_no);
break;
case ERRNO_SU:
fprintf(stderr, ERR_SUB, l_no);
break;
default:
handle_exception2(err, f, l_no, opcode, top);
}
if (fp)
fclose(fp);
if ((*top))
free_stack((*top));
exit(EXIT_FAILURE);
}

/**
 * check_input - checks for errors in user input
 *
 * @argc: count of arguments
 * @args: array containing arguments
 *
 * Return: 0 (Success), negative number (Failure)
 */
int check_input(int argc, char *args[])
{
FILE *fp_test = NULL;

if (argc != 2)
return (ERRNO_U);

fp_test = fopen(args[1], "r");
if (!fp_test)
return (ERRNO_F);

fclose(fp_test);
return (0);
}
