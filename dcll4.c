/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:54:47 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:54:59 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	rev_rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
}

void	rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
}

void	swap_a(t_dcll **stack_a)
{
	int	temp;

	temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
}
