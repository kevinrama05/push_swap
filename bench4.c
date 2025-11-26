/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:05:15 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 15:05:28 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
	count_ops("rb", o);
}

void	rev_rotate_a_bench(t_dcll **stack_a, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
	count_ops("rra", o);
}

void	rev_rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
	count_ops("rrb", o);
}

void	rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
	count_ops("rr", o);
}

void	rev_rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
	count_ops("rrr", o);
}
