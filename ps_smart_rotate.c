/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:56:48 by kerama            #+#    #+#             */
/*   Updated: 2025/12/17 12:03:58 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_element(t_stack *tmp, int min, int max)
{
	int	i;

	i = 1;
	while (i < tmp->size / 2)
	{
		if (tmp->head->index >= min && tmp->head->index <= max)
			return (0);
		else
			tmp->head = tmp->head->next;
		i++;
	}
	return (1);
	
}

void	ft_smart_rotate_b(t_ps_data *data, int min, int max)
{
	int		i;

	i = 0;
	if (data->b->tail->index >= min && data->b->tail->index <= max)
		rrb(data);
	else if (data->b->head->next->index >= min && data->b->head->next->index <= max)
		sb(data);
	else
	{
		i = ft_find_element(data->b, min, max);
		if (i == 0)
		{
			while (!(data->b->head->index >= min && data->b->head->index <= max))
				rb(data);
		}
		else
		{
			while (!(data->b->head->index >= min && data->b->head->index <= max))
				rrb(data);
		}
	}
}

void	ft_smart_rotate_a(t_ps_data *data, int min, int max)
{
	int		i;

	i = 0;
	if (data->a->tail->index >= min && data->a->tail->index <= max)
		rra(data);
	else if (data->a->head->next->index >= min && data->a->head->next->index <= max)
		sa(data);
	else
	{
		i = ft_find_element(data->a, min, max);
		if (i == 0)
		{
			while (!(data->a->head->index >= min && data->a->head->index <= max))
				ra(data);
		}
		else
		{
			while (!(data->a->head->index >= min && data->a->head->index <= max))
				rra(data);
		}
	}
}
