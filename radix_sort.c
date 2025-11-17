#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int count_zero_bits(int n, int k)
{
	int block_size = 1L << (k + 1); 
	int half_block = 1L << k; 
	int total = n + 1;       

	int full_blocks = total / block_size;
	int remainder = total % block_size;

	int zeros = full_blocks * half_block;

	int extra = remainder - half_block;
	if (extra < 0)
        	extra = 0;
	if (extra > half_block)
        	extra = half_block;

    	return zeros + extra;
}

int	binary_digits(unsigned int n)
{
	int bits = 0;

	if (n == 0)
		return 1;

	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return bits;
}

void push_zeros(t_dcll **stack_a, t_dcll **stack_b, int k, int n)
{
	int i = 0;
	while (i < n)
	{
		if (((*stack_a)->index >> k) == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		i++;
	}
	while (*stack_b)
		push_a(stack_b, stack_a);
}

int list_size(t_dcll *a)
{
	int i = 0;
	t_dcll *temp = a;
	while (1)
	{
		i++;
		temp = temp->next;
		if (temp == a)
			break;
	}
	return i;
}
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
