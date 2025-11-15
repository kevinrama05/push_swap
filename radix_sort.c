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
		if ((((*stack_a)->index >> k) & 1) == 0)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a);
	}
	while (*stack_b)
		push_a(stack_b, stack_a);
}

void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int num_of_zeros;
	int i = i;
	int loops = binary_digits(size - 1);
	while (i <= loops)
	{
		num_of_zeros = count_zero_bits(size - 1, i);
		if (num_of_zeros >= size - 1 - num_of_zeros)
			push_zeros(stack_a, stack_b, i, num_of_zeros);
		else
			push_ones(stack_a, stack_b, i, size - 1 - num_of_zeros);
		i++;
	}
}
