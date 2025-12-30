/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:30:04 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 18:52:49 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_error_exit();
	new->value = value;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_add_node_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (stack->size == 0)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->next = stack->head;
		stack->head->prev = new;
		stack->head = new;
	}
	stack->size++;
}

t_node	*ft_del_node_front(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size == 0)
		return (NULL);
	temp = stack->head;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = temp->next;
		stack->head->prev = NULL;
		temp->next = NULL;
	}
	stack->size--;
	return (temp);
}

void	ft_add_node_back(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (stack->size == 0)
	{
		ft_add_node_front(stack, new);
		return ;
	}
	new->prev = stack->tail;
	stack->tail->next = new;
	stack->tail = new;
	stack->size++;
}

t_node	*ft_del_node_back(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size == 0)
		return (NULL);
	if (stack->size == 1)
		return (ft_del_node_front(stack));
	temp = stack->tail;
	stack->tail = temp->prev;
	stack->tail->next = NULL;
	temp->prev = NULL;
	stack->size--;
	return (temp);
}
