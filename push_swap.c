#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"

int	check_sort_args(t_flags flags)
{
	int	i;

	i = 0;
	i = i + flags.adaptive;
	i = i + flags.simple;
	i = i + flags.complex;
	i = i + flags.medium;
	return (i);
}

void	exit_program(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	count_args(t_flags a)
{
	int	i;

	i = a.adaptive + a.bench + a.complex + a.medium + a.simple;
	return (i); 
}

void adaptive_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	float disorder_num;

	disorder_num = disorder(stack_a);
	if (disorder_num <= 0.2)
		min_max_extraction(stack_a, stack_b);
	else if (disorder_num <= 0.5)
		chunk_based_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}

void adaptive_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o)
{
	float disorder_num;
	disorder_num = disorder(stack_a);
	if (list_size(*stack_a) == 1)
		disorder_num = 0;
	if (disorder_num <= 0.2)
		min_max_extraction_bench(stack_a, stack_b, o);
	else if (disorder_num <= 0.5)
		chunk_based_sort_bench(stack_a, stack_b, size, o);
	else
		radix_sort_bench(stack_a, stack_b, size, o);
}