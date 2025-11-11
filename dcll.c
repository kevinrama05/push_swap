/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:41:49 by kerama            #+#    #+#             */
/*   Updated: 2025/11/10 21:44:46 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_dcll  *create_node(int data, int index)
{
    t_dcll  *new;

    new = (t_dcll *)malloc(sizeof(t_dcll));
    if (!new)
        return (NULL);
    new->data = data;
    new->prev = new;
    new->next = new;
    new->index = index;
    return (new);
}

void    add_back(t_dcll **head, int data, int index)
{
    t_dcll  *new;
    t_dcll  *last_node;

    new = create_node(data, index);
    if (!*head)
        *head = new;
    last_node = (*head)->prev;
    last_node->next = new;
    new->prev = last_node;
    new->next = *head;
    (*head)->prev = new;
    new->index = index;
}

void    add_front(t_dcll **head, int data, int index)
{
    t_dcll  *new;
    t_dcll  *last_node;

    new = create_node(data, 0);
    if (!new)
        return ;
    if (!*head)
        *head = new;
    last_node = (*head)->prev;
    last_node->next = new;
    new->prev = last_node;
    new->next = *head;
    (*head)->prev = new;
    new->index = index;
    *head = new;
}

void	remove_front(t_dcll **head)
{
    t_dcll *temp;
    t_dcll *tail;

    if (!head || !*head)
        return;
    temp = *head;
    if (temp->next == temp)
    {
        free(temp);
        *head = NULL;
        return;
    }
    tail = temp->prev;
    tail->next = temp->next;
    temp->next->prev = tail;
    *head = temp->next;
    free(temp);
}
