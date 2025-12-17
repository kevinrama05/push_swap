/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:52:30 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 22:54:21 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps_data *data)
{
	if (data->a->size < 2)
		return ;
	_internal_rotate(data->a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	data->counts->ra_count++;
	data->counts->total_ops++;
}

void	rb(t_ps_data *data)
{
	if (data->b->size < 2)
		return ;
	_internal_rotate(data->b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	data->counts->rb_count++;
	data->counts->total_ops++;
}

void	rr(t_ps_data *data)
{
	if (data->a->size < 2 && data->b->size < 2)
		return ;
	_internal_rotate(data->a);
	_internal_rotate(data->b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	data->counts->rr_count++;
	data->counts->total_ops++;
}
