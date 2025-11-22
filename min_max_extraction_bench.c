#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void min_max_extraction_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	int i = 0;
	if (check_if_sorted(*stack_a) == 1)
		return ;
	t_dcll *tmp_a = *stack_a;
        t_dcll *tmp_b = *stack_b;	
	while (1)
	{
		if (tmp_a->index != i)
			rotate_a_bench(&tmp_a);
		else
		{
			push_b_bench(&tmp_a, &tmp_b);
			i++;
		}
		sleep(1);
		if (tmp_a == NULL)
			break;
	}
	while (tmp_b != NULL)
		push_a_bench(&tmp_b, &tmp_a);
}
