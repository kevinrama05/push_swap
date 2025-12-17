/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:01:21 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/15 19:15:17 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps_data *data)
{
	if (data->a->size < 2)
		return ;
	_internal_swap(data->a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	data->counts->sa_count++;
	data->counts->total_ops++;
}

void	sb(t_ps_data *data)
{
	if (data->b->size < 2)
		return ;
	_internal_swap(data->b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	data->counts->sb_count++;
	data->counts->total_ops++;
}

void	ss(t_ps_data *data)
{
	if (data->a->size < 2 && data->b->size < 2)
		return ;
	_internal_swap(data->a);
	_internal_swap(data->b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	data->counts->ss_count++;
	data->counts->total_ops++;
}
