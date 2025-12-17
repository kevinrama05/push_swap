/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_internal_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:42:11 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 22:55:19 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_internal_swap(t_stack *stack)
{
	int	temp_value;
	int	temp_index;

	if (!stack || stack->size < 2)
		return ;
	temp_value = stack->head->value;
	temp_index = stack->head->index;
	stack->head->value = stack->head->next->value;
	stack->head->index = stack->head->next->index;
	stack->head->next->value = temp_value;
	stack->head->next->index = temp_index;
}

void	_internal_push(t_stack *src, t_stack *dest)
{
	t_node	*node_to_push;

	if (!src || src->size == 0)
		return ;
	node_to_push = ft_del_node_front(src);
	if (node_to_push)
		ft_add_node_front(dest, node_to_push);
}

void	_internal_rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	stack->head->prev = NULL;
	temp->next = NULL;
	ft_add_node_back(stack, temp);
}

void	_internal_rrotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	temp = ft_del_node_back(stack);
	if (temp)
		ft_add_node_front(stack, temp);
}
