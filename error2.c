#include "monty.h"

void handle_exception2(int err,__attribute__((unused)) char *f,
		       __attribute__((unused))int l_no,
		       __attribute__((unused))char *opcode, stack_t **top)
{
switch (err)
{
case ERRNO_D:
fprintf(stderr, ERR_DIV, l_no);
break;
case ERRNO_Z:
fprintf(stderr, ERR_DIV_BY_ZERO, l_no);
default:
break;
}
if (fp)
fclose(fp);
if ((*top))
free_stack((*top));
exit(EXIT_FAILURE);
}
