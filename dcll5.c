/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:55:27 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:55:58 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	push_b(t_dcll **stack_a, t_dcll **stack_b)
{
	add_front(stack_b, (*stack_a)->data, (*stack_a)->index);
	remove_front(stack_a);
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_dcll **stack_b, t_dcll **stack_a)
{
	add_front(stack_a, (*stack_b)->data, (*stack_b)->index);
	remove_front(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->next;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
}
