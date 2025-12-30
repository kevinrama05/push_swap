/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:14:35 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 18:14:54 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPS_H
# define PUSH_SWAP_OPS_H

# include "push_swap_structs.h"

void	_internal_swap(t_stack *stack);
void	_internal_push(t_stack *stack_from, t_stack *stack_to);
void	_internal_rotate(t_stack *stack);
void	_internal_rrotate(t_stack *stack);

void	sa(t_ps_data *data);
void	sb(t_ps_data *data);
void	pa(t_ps_data *data);
void	pb(t_ps_data *data);
void	ra(t_ps_data *data);
void	rb(t_ps_data *data);
void	rra(t_ps_data *data);
void	rrb(t_ps_data *data);
void	ss(t_ps_data *data);
void	rr(t_ps_data *data);
void	rrr(t_ps_data *data);

#endif