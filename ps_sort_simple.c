/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:35:37 by kerama            #+#    #+#             */
/*   Updated: 2025/12/17 11:39:35 by kerama           ###   ########.fr       */
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

	data->strategy_name = "Simple Sort";
	data->complexity_class = "O(n^2)";
/* 	// --- TEMPORARY CRASH AVOIDANCE ---
	// For MVP run: sort two elements if possible
	sa(data);
	sa(data);
	pb(data);
	if (data->a->size == 2 && data->a->head->value > data->a->head->next->value)
		sa(data);
	// ---------------------------------
	// The actual complex N=3, N=4, N=5 logic will go here next. */
	i = 0;
	if (ft_is_sorted(data->a))
		return ;
	if (data->a->size <= 3)
		ft_tiny_sort(data);
	while (i < data->a->size && data->a->size > 3)
	{
		if (data->a->head->index != i)
			ft_smart_rotate_a(data, i, i);
		if (ft_is_sorted(data->a))
		{	
			ft_push_a(data);
			return ;
		}
		else
			pb(data);
		i++;
	}
	ft_tiny_sort(data);
	ft_push_a(data);
}
