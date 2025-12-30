/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:53:50 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 22:54:14 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps_data *data)
{
	if (data->a->size < 2)
		return ;
	_internal_rrotate(data->a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	data->counts->rra_count++;
	data->counts->total_ops++;
}

void	rrb(t_ps_data *data)
{
	if (data->b->size < 2)
		return ;
	_internal_rrotate(data->b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	data->counts->rrb_count++;
	data->counts->total_ops++;
}

void	rrr(t_ps_data *data)
{
	if (data->a->size < 2 && data->b->size < 2)
		return ;
	_internal_rrotate(data->a);
	_internal_rrotate(data->b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	data->counts->rrr_count++;
	data->counts->total_ops++;
}
