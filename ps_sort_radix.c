/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:30:40 by kerama            #+#    #+#             */
/*   Updated: 2025/12/21 12:11:43 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	pb_or_ra(t_ps_data *data, int i)
{
	if (((data->a->head->index >> i) & 1) == 0)
		pb(data);
	else
		ra(data);
}

void	ft_sort_radix(t_ps_data *data)
{
	int	n;
	int	size;
	int	i;
	int	j;

	data->strategy_name = "Complex";
	data->complexity_class = "O(n log n)";
	if (data->a->size == 3)
		ft_tiny_sort(data);
	if (data->a->size <= 10)
		ft_sort_simple(data);
	if (ft_is_sorted(data->a))
		return ;
	n = ft_num_of_bytes(data->a->size - 1);
	size = data->a->size;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j++ < size)
			pb_or_ra(data, i);
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}
