/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:04:42 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 15:04:56 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap_a_bench(t_dcll **stack_a, t_ops *o)
{
	int	temp;

	temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
	count_ops("sa", o);
}

void	swap_b_bench(t_dcll **stack_b, t_ops *o)
{
	int	temp;

	temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
	count_ops("sb", o);
}

void	swap_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	int	temp;

	temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("ss\n", 1);
	count_ops("ss", o);
}

void	init_ops(t_ops *o)
{
	o->sa = 0;
	o->sb = 0;
	o->ss = 0;
	o->pa = 0;
	o->pb = 0;
	o->ra = 0;
	o->rb = 0;
	o->rr = 0;
	o->rra = 0;
	o->rrb = 0;
	o->rrr = 0;
}
void	count_ops(char *ops, t_ops *o)
{
	if (c(ops, "sa") == 0)
		o->sa++;
	else if (c(ops, "sb") == 0)
		o->sb++;
	else if (c(ops, "ss") == 0)
		o->ss++;
	else if (c(ops, "pa") == 0)
		o->pa++;
	else if (c(ops, "pb") == 0)
		o->pb++;
	else if (c(ops, "ra") == 0)
		o->ra++;
	else if (c(ops, "rb") == 0)
		o->rb++;
	else if (c(ops, "rr") == 0)
		o->rr++;
	else if (c(ops, "rra") == 0)
		o->rra++;
	else if (c(ops, "rrb") == 0)
		o->rrb++;
	else if (c(ops, "rrr") == 0)
		o->rrr++;
}
