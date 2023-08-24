#include "monty.h"

/**
 * handle_exception2 - checks for any exception thrown by the script
 * and returns the corresponding error message
 *
 * @err: error number
 * @l_no: line number of the error
 * @top: top of the stack
 *
 * Return: always void
 */
void handle_exception2(int err, int l_no, stack_t **top)
{
switch (err)
{
case ERRNO_D:
fprintf(stderr, ERR_DIV, l_no);
break;
case ERRNO_Z:
fprintf(stderr, ERR_DIV_BY_ZERO, l_no);
break;
case ERRNO_MUL:
fprintf(stderr, ERR_MUL, l_no);
break;
case ERRNO_MOD:
fprintf(stderr, ERR_MOD, l_no);
default:
break;
}
if (fp)
fclose(fp);
if ((*top))
free_stack((*top));
exit(EXIT_FAILURE);
}
