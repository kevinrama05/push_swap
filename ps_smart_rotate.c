/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:56:48 by kerama            #+#    #+#             */
/*   Updated: 2025/12/20 09:17:37 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_element_a(t_ps_data *d, int min, int max)
{
	t_node	*head_temp;
	t_node	*tail_temp;

	head_temp = d->a->head;
	tail_temp = d->a->tail;
	while (head_temp)
	{
		if (head_temp->index >= min && head_temp->index <= max)
			return (1);
		else if (tail_temp->index >= min && tail_temp->index <= max)
			return (-1);
		head_temp = head_temp->next;
		tail_temp = tail_temp->prev;
	}
	return (0);
}

static int	ft_find_element_b(t_ps_data *d, int min, int max)
{
	t_node	*head_temp;
	t_node	*tail_temp;
	int		dist_head;
	int		dist_tail;

	head_temp = d->b->head;
	tail_temp = d->b->tail;
	dist_head = 1;
	dist_tail = -1;
	while (head_temp)
	{
		if (head_temp->index >= min && head_temp->index <= max)
			break ;
		if (tail_temp->index >= min && tail_temp->index <= max)
			break ;
		dist_head++;
		dist_tail--;
		head_temp = head_temp->next;
		tail_temp = tail_temp->prev;
	}
	if (-dist_tail < dist_head)
		return (dist_tail);
	return (dist_head);
}

void	ft_smart_rotate_b(t_ps_data *data, int min, int max)
{
	int		i;

	i = 0;
	if (data->b->head->index >= min && data->b->head->index <= max)
		return ;
	if (data->b->tail->index >= min && data->b->tail->index <= max)
		rrb(data);
	else if (data->b->head->next->index >= min
		&& data->b->head->next->index <= max)
		sb(data);
	else
	{
		i = ft_find_element_b(data, min, max);
		if (i == 0)
		{
			while (data->b->head->index > max || data->b->head->index < min)
				rb(data);
		}
		else
		{
			while (data->b->head->index < min || data->b->head->index > max)
				rrb(data);
		}
	}
}

void	ft_smart_rotate_a(t_ps_data *data, int min, int max)
{
	int		i;

	i = 0;
	if (data->a->head->index >= min && data->a->head->index <= max)
		return ;
	if (data->a->tail->index >= min && data->a->tail->index <= max)
		rra(data);
	else
	{
		i = ft_find_element_a(data, min, max);
		if (i == 1)
		{
			while (data->a->head->index > max || data->a->head->index < min)
				ra(data);
		}
		else
		{
			while (data->a->head->index > max || data->a->head->index < min)
				rra(data);
		}
	}
}
