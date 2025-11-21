#include "push_swap.h"

void count_ops(char *op, t_opscount *opscount)
{
	if (c(op, "sa") == 0)
		opscount->sa++;
	else if (c(op, "sb") == 0)
		opscount->sb++;
	else if (c(op, "ss") == 0)
		opscount->ss++;
	else if (c(op, "ra") == 0)
		opscount->ra++;
	else if (c(op, "rb") == 0)
		opscount->rb++;
	else if (c(op, "rr") == 0)
		opscount->rr++;
	else if (c(op, "rrb") == 0)
		opscount->rrb++;
	else if (c(op, "rra") == 0)
		opscount->rra++;
	else if (c(op, "rrr") == 0)
		opscount->rrr++;
	else if (c(op, "pa") == 0)
		opscount->pa++;
	else if (c(op, "pb") == 0)
		opscount->pb++;
}


