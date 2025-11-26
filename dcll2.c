/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:44:53 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 15:08:21 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	check_if_no_dup(t_dcll *head)
{
	t_dcll	*temp;

	temp = head;
	while (1)
	{
		if (temp->data == temp->next->data)
			return (0);
		temp = temp->next;
		if (temp == head)
			break ;
	}
	return (1);
}

t_dcll	*copy_list(t_dcll *head)
{
	t_dcll	*copy;
	t_dcll	*temp;
	t_dcll	*new_node;
	t_dcll	*last;

	if (!head)
		return (NULL);
	copy = NULL;
	temp = head;
	last = NULL;
	while (1)
	{
		new_node = create_node(temp->data, temp->index);
		if (!new_node)
			return (NULL);
		if (!copy)
		{
			copy = new_node;
			last = copy;
		}
		else
		{
			last->next = new_node;
			new_node->prev = last;
			last = new_node;
		}
		temp = temp->next;
		if (temp == head)
			break ;
	}
	last->next = copy;
	copy->prev = last;
	return (copy);
}
