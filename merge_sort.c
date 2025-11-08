/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:42:58 by ekrama10          #+#    #+#             */
/*   Updated: 2025/11/08 10:46:45 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

/* =============================
   Node utilities
   ============================= */

t_dcll *new_node(int data)
{
    t_dcll *node = malloc(sizeof(t_dcll));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

void append(t_dcll **head, int data)
{
    t_dcll *node = new_node(data);
    if (!*head)
    {
        *head = node;
        node->next = node->prev = node; // circular
        return;
    }
    t_dcll *tail = (*head)->prev;
    tail->next = node;
    node->prev = tail;
    node->next = *head;
    (*head)->prev = node;
}

void print_list(t_dcll *head)
{
    if (!head)
        return;
    t_dcll *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

/* =============================
   Split list into two halves
   ============================= */
t_dcll *split_list(t_dcll *head)
{
    t_dcll *slow = head;
    t_dcll *fast = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    t_dcll *second = slow->next;
    slow->next = NULL;
    if (second)
        second->prev = NULL;

    return second;
}

/* =============================
   Merge two sorted lists
   ============================= */
t_dcll *merge_lists(t_dcll *a, t_dcll *b)
{
    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data)
    {
        a->next = merge_lists(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = merge_lists(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

/* =============================
   Merge sort (recursive)
   ============================= */
t_dcll *merge_sort(t_dcll *head)
{
    if (!head || !head->next)
        return head;

    t_dcll *second = split_list(head);

    head = merge_sort(head);
    second = merge_sort(second);

    return merge_lists(head, second);
}

/* =============================
   Make list circular again
   ============================= */
void make_circular(t_dcll *head)
{
    if (!head)
        return;

    t_dcll *tail = head;
    while (tail->next)
        tail = tail->next;

    head->prev = tail;
    tail->next = head;
}

/* =============================
   Main sort entry
   ============================= */
t_dcll *sort_doubly_circular(t_dcll *head)
{
    if (!head || head->next == head)
        return head;

    // Break circular link temporarily
    head->prev->next = NULL;
    head->prev = NULL;

    // Sort using merge sort
    head = merge_sort(head);

    // Reconnect circular structure
    make_circular(head);

    return head;
}

/* =============================
   Example usage
   ============================= */
int main(void)
{
    t_dcll *head = NULL;

    add_back(&head, 65);
    add_back(&head, 85);
    add_back(&head, 79);
    add_back(&head, 10);
    add_back(&head, 89);

    printf("Original list:\n");
    print_list(head);

    head = sort_doubly_circular(head);

    printf("Sorted list:\n");
    print_list(head);

    return 0;
}
