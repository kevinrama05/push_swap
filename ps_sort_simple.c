/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:35:37 by kerama            #+#    #+#             */
/*   Updated: 2025/12/20 09:33:06 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_ps_data *data)
{
	if (data->b->size == 0)
		return ;
	else
	{
		while (data->b->size != 0)
			pa(data);
	}
}

void	ft_sort_simple(t_ps_data *data)
{
	int	i;
	int	size;

	data->strategy_name = "Simple Sort";
	data->complexity_class = "O(n²)";
	size = data->a->size;
	i = 0;
	if (ft_is_sorted(data->a))
		return ;
	if (data->a->size <= 3)
		ft_tiny_sort(data);
	while (i < size && data->a->size > 3)
	{
		if (data->a->head->index != i)
			ft_smart_rotate_a(data, i, i);
		if (ft_is_sorted(data->a))
			break ;
		else
			pb(data);
		i++;
	}
	if (data->a->size == 3)
		ft_tiny_sort(data);
	ft_push_a(data);
}
