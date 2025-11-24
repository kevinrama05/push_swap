#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>


void radix_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o)
{
	int i = 0;
	int loops = binary_digits(size - 1);
	int j = 0;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	while (i < loops)
	{
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b_bench(stack_a, stack_b, o);
			else
				rotate_a_bench(stack_a, o);
			j++;
		}
		while (*stack_b)
			push_a_bench(stack_b, stack_a, o);
		if (check_if_sorted_asc(*stack_a))
			break;
		j = 0;
		i++;
	}
}
