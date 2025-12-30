/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:00:04 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 23:04:38 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps_data *data)
{
	if (data->b->size == 0)
		return ;
	_internal_push(data->b, data->a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	data->counts->pa_count++;
	data->counts->total_ops++;
}

void	pb(t_ps_data *data)
{
	if (data->a->size == 0)
		return ;
	_internal_push(data->a, data->b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	data->counts->pb_count++;
	data->counts->total_ops++;
}
