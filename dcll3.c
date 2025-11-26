/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:53:40 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:54:13 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	swap_b(t_dcll **stack_b)
{
	int	temp;

	temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_dcll **stack_a, t_dcll **stack_b)
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
}

float	disorder(t_dcll **stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_dcll	*temp1;
	t_dcll	*temp2;
	t_dcll	*head;

	mistakes = 0;
	total_pairs = 0;
	if (!stack_a || !*stack_a)
		return (0.0f);
	head = *stack_a;
	temp1 = head;
	while (temp1->next != head)
	{
		temp2 = temp1->next;
		while (temp2 != head)
		{
			total_pairs++;
			if (temp1->data > temp2->data)
				mistakes++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

int	check_if_sorted_asc(t_dcll *stack)
{
	t_dcll	*temp;

	temp = stack;
	if (list_size(stack) == 1)
		return (1);
	while (1)
	{
		if (temp->data > temp->next->data && temp->next != stack)
			return (0);
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (1);
}

int	check_if_sorted_dec(t_dcll *stack)
{
	t_dcll	*temp;

	temp = stack;
	while (1)
	{
		if (temp->data < temp->next->data && temp->next != stack)
			return (0);
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (1);
}
