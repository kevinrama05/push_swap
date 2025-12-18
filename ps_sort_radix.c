#include "push_swap.h"

static int	ft_num_of_bytes(int num)
{
	int	n;

	n = 0;
	while (num != 0)
	{
		num = num / 2;
		n++;
	}
	return (n);
}

void	ft_sort_radix(t_ps_data *data)
{
	int	n;
	int	size;
	int	i;
	int	j;

	data->strategy_name = "Complex";
	
	n = ft_num_of_bytes(data->a->size - 1);
	size = data->a->size;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < size)
		{
			if (((data->a->head->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}