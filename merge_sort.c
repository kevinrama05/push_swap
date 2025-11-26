/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:42:58 by ekrama10          #+#    #+#             */
/*   Updated: 2025/11/26 14:51:00 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_dcll	*split_list(t_dcll *head)
{
	t_dcll	*slow;
	t_dcll	*fast;
	t_dcll	*second;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	second = slow->next;
	slow->next = NULL;
	if (second)
		second->prev = NULL;
	return (second);
}

t_dcll	*merge_lists(t_dcll *a, t_dcll *b)
{
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->data <= b->data)
	{
		a->next = merge_lists(a->next, b);
		a->next->prev = a;
		a->prev = NULL;
		return (a);
	}
	else
	{
		b->next = merge_lists(a, b->next);
		b->next->prev = b;
		b->prev = NULL;
		return (b);
	}
}

t_dcll	*merge_sort(t_dcll *head)
{
	t_dcll	*second;

	if (!head || !head->next)
		return (head);
	second = split_list(head);
	head = merge_sort(head);
	second = merge_sort(second);
	return (merge_lists(head, second));
}

void	make_circular(t_dcll *head)
{
	t_dcll	*tail;

	if (!head)
		return ;
	tail = head;
	while (tail->next)
		tail = tail->next;
	head->prev = tail;
	tail->next = head;
}

t_dcll	*sort_doubly_circular(t_dcll *head)
{
	if (!head || head->next == head)
		return (head);
	head->prev->next = NULL;
	head->prev = NULL;
	head = merge_sort(head);
	make_circular(head);
	return (head);
}
