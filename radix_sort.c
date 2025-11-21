#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>


void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int i = 0;
	int loops = binary_digits(size - 1);
	int j = 0;
	while (i < loops)
	{
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		if (check_if_sorted_asc(*stack_a))
			break;
		j = 0;
		i++;
	}
}
