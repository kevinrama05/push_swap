#include "push_swap.h"

void count_ops(char c, char *ops)
{
    static t_opscount opscount;

    if (c(ops, "sa") == 0)
        opscount.sa++;
    else if (c(ops, "sb") == 0)
        opscount.sb++;
    else if (c(ops, "ss") == 0)
        opscount.ss++;
    else if (c(ops, "ra") == 0)
        opscount.ra++;
    
}