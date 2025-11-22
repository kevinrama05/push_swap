#include "push_swap.h"

void push_b_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	add_front(stack_b, (*stack_a)->data, (*stack_a)->index);
	remove_front(stack_a);
	ft_putstr_fd("pb\n", 1);
	count_ops("pb", o);
}

void push_a_bench(t_dcll **stack_b, t_dcll **stack_a, t_ops *o)
{
	add_front(stack_a, (*stack_b)->data, (*stack_b)->index);
	remove_front(stack_b);
	count_ops("pa", o);
}

void rotate_a_bench(t_dcll **stack_a, t_ops *o)
{
	*stack_a = (*stack_a)->next;
	ft_putstr_fd("ra\n", 1);
	count_ops("ra", o);
}

void rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
	count_ops("rb", o);
}

void rev_rotate_a_bench(t_dcll **stack_a, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
	count_ops("rra", o);
}

void rev_rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
	count_ops("rb", o);
}

void rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
	count_ops("rr", o);
}

void rev_rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
	count_ops("rrr", o);
}

void swap_a_bench(t_dcll **stack_a, t_ops *o)
{
	int temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
	count_ops("sa", o);
}

void swap_b_bench(t_dcll **stack_b, t_ops *o)
{
	int temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
	count_ops("sb", o);
}

void swap_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	int temp = (*stack_a)->data;
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
	count_ops("ss", o);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:26 by kerama            #+#    #+#             */
/*   Updated: 2025/11/14 13:41:13 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

void	print_stacks(t_dcll **a, t_dcll **b)
{
	(void)a;
	(void)b;
	printf("----");
	sleep(2);
}

static int isqrt(int n)
{
	int guess;
	int prev;

	if (n < 0)
		return -1;
	if (n == 0 || n == 1)
		return n;

	guess = n / 2;
	prev = 0;
	while (guess != prev)
	{
		prev = guess;
		guess = (guess + n / guess) / 2;
	}
	if (guess * guess > n)
		guess--;

	return guess;
}

int list_size(t_dcll *stack)
{
	int i = 0;
	if (!stack)
		return i;
	t_dcll *temp = stack;
	while (1)
	{
		i++;
		stack = stack->next;
		if (temp == stack)
			return i;
	}
}

void push_chunk(t_dcll **stack_a, t_dcll **stack_b, int min, int max)
{
	int chunk_size = max - min + 1;
	int i = 0;
	while (i != chunk_size)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			if (!*stack_b)
				push_b(stack_a, stack_b);
			else if ((*stack_a)->index > (*stack_b)->index)
				push_b(stack_a, stack_b);
			else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index > (*stack_b)->next->index)
			{
				push_b(stack_a, stack_b);
				swap_b(stack_b);
			}
			else
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
			}
			i++;
		}
		else
			rev_rotate_a(stack_a);
	}
}

void new_chunk(int *min, int *max, int chunk)
{
	*max = *max - chunk;
	if (*max < 0)
		*max = 0;
	*min = *min - chunk;
	if (*min < 0)
		*min = 0;
}

void chunk_based_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int chunk = isqrt(size);
	if (chunk < 5)
		chunk = 5;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	int max = size - 1;
	int min = max - chunk + 1;
	if (min < 0)
		min = 0;
	int first_chunk = 1;
	while (1)
	{
		push_chunk(stack_a, stack_b, min, max);
		if (first_chunk == 0)
		{
			while ((*stack_a)->index != max + 1)
				rotate_a(stack_a);
		}
		push_a(stack_b, stack_a);
		while (*stack_b)
		{
			if ((*stack_b)->index == (*stack_a)->index - 1)
				push_a(stack_b, stack_a);
			else if ((*stack_b)->next->index == (*stack_a)->index - 1)
			{
				swap_b(stack_b);
				push_a(stack_b, stack_a);
			}
			else if ((*stack_b)->prev->index == (*stack_a)->index - 1)
			{
				rev_rotate_b(stack_b);
				push_a(stack_b, stack_a);
			}
			else if ((*stack_b)->prev->prev->index == (*stack_a)->index - 1)
			{
				rev_rotate_b(stack_b);
				rev_rotate_b(stack_b);
				push_a(stack_b, stack_a);
			}
			else
				rotate_b(stack_b);
		
		}
		first_chunk = 0;
		new_chunk(&min, &max, chunk);
		if (min == 0 && max == 0)
			break;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:26 by kerama            #+#    #+#             */
/*   Updated: 2025/11/14 13:41:13 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

static int isqrt(int n)
{
    int guess;
    int prev;

    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;

    guess = n / 2;
    prev = 0;
    while (guess != prev)
    {
        prev = guess;
        guess = (guess + n / guess) / 2;
    }
    if (guess * guess > n)
        guess--;

    return guess;
}

int list_size(t_dcll *stack)
{
	int i = 0;
	if (!stack)
		return i;
	t_dcll *temp = stack;
	while (1)
	{
		i++;
		stack = stack->next;
		if (temp == stack)
			return i;
	}
}

void push_chunk_bench(t_dcll **stack_a, t_dcll **stack_b, int min, int max, t_ops *o)
{
	int chunk_size = max - min + 1;
	int i = 0;
	while (i != chunk_size)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			if (!*stack_b)
				push_b_bench(stack_a, stack_b, o);
			else if ((*stack_a)->index > (*stack_b)->index)
				push_b_bench(stack_a, stack_b, o);
			else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index > (*stack_b)->next->index)
			{
				push_b_bench(stack_a, stack_b, o);
				swap_b_bench(stack_b, o);
			}
			else
			{
				push_b_bench(stack_a, stack_b, o);
				rotate_b_bench(stack_b, o);
			}
			i++;
		}
		else
			rev_rotate_a_bench(stack_a, o);
	}
}

void new_chunk(int *min, int *max, int chunk)
{
	*max = *max - chunk;
	if (*max < 0)
		*max = 0;
	*min = *min - chunk;
	if (*min < 0)
		*min = 0;
}

void chunk_based_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o)
{
	int chunk = isqrt(size);
	if (chunk < 5)
		chunk = 5;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	int max = size - 1;
	int min = max - chunk + 1;
	if (min < 0)
		min = 0;
	int first_chunk = 1;
	while (1)
	{
		push_chunk_bench(stack_a, stack_b, min, max, o);
		if (first_chunk == 0)
		{
			while ((*stack_a)->index != max + 1)
				rotate_a_bench(stack_a, o);
		}
		push_a_bench(stack_b, stack_a, o);
		while (*stack_b)
		{
			if ((*stack_b)->index == (*stack_a)->index - 1)
				push_a_bench(stack_b, stack_a, o);
			else if ((*stack_b)->next->index == (*stack_a)->index - 1)
			{
				swap_b_bench(stack_b, o);
				push_a_bench(stack_b, stack_a, o);
			}
			else if ((*stack_b)->prev->index == (*stack_a)->index - 1)
			{
				rev_rotate_b_bench(stack_b, o);
				push_a_bench(stack_b, stack_a, o);
			}
			else if ((*stack_b)->prev->prev->index == (*stack_a)->index - 1)
			{
				rev_rotate_b_bench(stack_b, o);
				rev_rotate_b_bench(stack_b, o);
				push_a_bench(stack_b, stack_a, o);
			}
			else
				rotate_b_bench(stack_b, o);
		}
		first_chunk = 0;
		new_chunk(&min, &max, chunk);
		if (min == 0 && max == 0)
			break;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:41:49 by kerama            #+#    #+#             */
/*   Updated: 2025/11/11 11:11:27 by kerama           ###   ########.fr       */
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

    new = create_node(data, index);
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
    if (temp->next == *head)
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
#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"
int check_if_no_dup(t_dcll *head)
{
	t_dcll *temp = head;
	while (1)
	{
		if (temp->data == temp->next->data)
			return 0;
		temp = temp->next;
		if (temp == head)
			break;
	}
	return 1;
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
			break;
	}
	last->next = copy;
	copy->prev = last;
	return (copy);
}

void push_b(t_dcll **stack_a, t_dcll **stack_b)
{
	add_front(stack_b, (*stack_a)->data, (*stack_a)->index);
	remove_front(stack_a);
	ft_putstr_fd("pb\n", 1);
}

void push_a(t_dcll **stack_b, t_dcll **stack_a)
{
	add_front(stack_a, (*stack_b)->data, (*stack_b)->index);
	remove_front(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->next;
	ft_putstr_fd("ra\n", 1);
}

void rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
}

void rev_rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
}

void rev_rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
}

void rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
}

void rev_rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
}

void swap_a(t_dcll **stack_a)
{
	int temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
}

void swap_b(t_dcll **stack_b)
{
	int temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
}

void swap_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	int temp = (*stack_a)->data;
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

float disorder(t_dcll **stack_a)
{
    int mistakes = 0;
    int total_pairs = 0;
    t_dcll *temp1;
    t_dcll *temp2;
    t_dcll *head;

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

int check_if_sorted_asc(t_dcll *stack)
{
	t_dcll *temp = stack;
	while (1)
	{
		if (temp->data > temp->next->data && temp->next != stack)
			return 0;
		temp = temp->next;
		if (temp == stack)
			break;
	}
	return 1;
}

int check_if_sorted_dec(t_dcll *stack)
{
	t_dcll *temp = stack;
	while (1)
	{
		if (temp->data < temp->next->data && temp->next != stack)
			return 0;
		temp = temp->next;
		if (temp == stack)
			break;
	}
	return 1;
}
#include <stdio.h>
#include "push_swap.h"

void print_list(t_dcll *head)
{
    t_dcll *temp;

    if (!head)
    {
        printf("(empty list)\n");
        return;
    }

    temp = head;
    printf("List: ");
    do {
        printf("[%d] ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main(void)
{
    t_dcll *head = NULL;

    printf("Adding 10, 20, 30 to the back:\n");
    add_back(&head, 10);
    add_back(&head, 20);
    add_back(&head, 30);
    print_list(head);

    printf("Adding 5 to the front:\n");
    add_front(&head, 5);
    print_list(head);

    printf("Rotating forward (r):\n");
    rotate(&head, 1);
    print_list(head);

    printf("Rotating backward (rr):\n");
    rotate(&head, -1);
    print_list(head);

    printf("Removing front node:\n");
    remove_front(&head);
    print_list(head);

    printf("Removing all nodes:\n");
    remove_front(&head);
    remove_front(&head);
    remove_front(&head);
    remove_front(&head);
    print_list(head);

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dcll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:37:48 by kerama            #+#    #+#             */
/*   Updated: 2025/11/09 12:03:43 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void free_dcll(t_dcll *head)
{
    t_dcll *curr;
    t_dcll *tmp;
    
    curr = head->next;
    if (!head)
        return;
    while (curr != head)
    {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(head);
}
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct entry_t {
    unsigned int key;
    unsigned int value;
    struct entry_t *next;
} entry_t;

typedef struct {
    size_t size;
    entry_t **entries;
} ht_t;

unsigned int hash(int key, size_t size) {
    unsigned int x = (unsigned int)key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % size;
}

entry_t *ht_pair(unsigned int key, unsigned int value) {
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

ht_t *ht_create(size_t size) {
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);
    hashtable->entries = malloc(sizeof(entry_t*) * size);
    hashtable->size = size;
    size_t i = 0;
    while (i < size)
	    hashtable->entries[i++] = NULL;

    return hashtable;
}

void ht_set(ht_t *hashtable, unsigned int key, unsigned int value, size_t size) {
    unsigned int slot = hash(key, size);
    entry_t *entry = hashtable->entries[slot];
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }
    entry_t *prev;
    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        prev = entry;
        entry = prev->next;
    }
    prev->next = ht_pair(key, value);
}

unsigned int ht_get(ht_t *hashtable, unsigned int key, size_t size) {
    unsigned int slot = hash(key, size);
    entry_t *entry = hashtable->entries[slot];
    if (entry == NULL) {
        return -1;
    }
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

void ht_dump(ht_t *hashtable, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        entry_t *entry = hashtable->entries[i];
        if (entry == NULL) {
            continue;
        }
        printf("slot[%4ld]: ", i);
        for(;;) {
            printf("%u=%u ", entry->key, entry->value);
            if (entry->next == NULL) {
                break;
            }
            entry = entry->next;
        }
        printf("\n");
    }
}

/* void free_ht(ht_t *table)
{
    size_t i;
    entry_t *current;
    entry_t *temp;

    if (!table || !table->entries)
        return;

    i = 0;
    while (i < table->size)
    {
        current = table->entries[i];
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        i++;
    }

    free(table->entries);
    free(table);
} */


void free_ht(ht_t *table) {
    if (!table || !table->entries)
        return;
    for (size_t i = 0; i < table->size; ++i) {
        entry_t *entry = table->entries[i];
        while (entry) {
            entry_t *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(table->entries);
    free(table);
}

/* int main(void) {
    ht_t *ht = ht_create(20);
    int i = 20;
    ht_set(ht, 2, 0, i);
    ht_set(ht, 6, 1, i);
    ht_set(ht, 10, 2, i);
    ht_set(ht, 18, 3, i);
    ht_set(ht, 20, 4, i);
    ht_set(ht, 26, 5, i);
    ht_set(ht, 28, 6, i);
    printf("%u\n", ht_get(ht, 2, i));
    ht_dump(ht, i);
    free_ht(ht);
    return 0;
}
 */#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
void print_list(t_dcll *head)
{
    if (!head)
        return;
    t_dcll *temp = head;
    do
    {
        printf("[%d|%d]  <-->  ", temp->data, temp->index);
        temp = temp->next;
    } while (temp != head);
    printf("[END OF CYCLE]\n");
}

void	print_stacks_main(t_dcll *a, t_dcll *b)
{
	t_dcll	*head_a = a;
	t_dcll	*head_b = b;

	if (!a && !b)
		return ;

	printf("   a   |   b\n");
	printf("---------------\n");

	while (a || b)
	{
		if (a)
		{
			printf("%5d", a->data); // right-aligned in width 5
			a = (a->next != head_a) ? a->next : NULL;
		}
		else
			printf("     "); // 5 spaces for empty slot

		printf(" | ");

		if (b)
		{
			printf("%5d", b->data);
			b = (b->next != head_b) ? b->next : NULL;
		}
		else
			printf("     ");

		printf("\n");
	}
	printf("---------------\n");
}


/* int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_putstr_fd("Error\n", 1);
        return (0);
    }
    size_t size = argc - 1;
    t_dcll *stack_a = create_stack_a(argv);
    if (stack_a == 0)
    {
    	ft_putstr_fd("Error\n", 1);
	return 0;
    }
//    float disorder_value = disorder(&stack_a);
    t_dcll *copy_a = copy_list(stack_a);
    copy_a = sort_doubly_circular(copy_a);
    if (check_if_no_dup(copy_a) == 0)
    {
    	ft_putstr_fd("Error\n", 1);
	return 0;
    }
    ht_t *hashtable = ht_create(size);
    size_t i = 0;
    while (i < size)
    {
        ht_set(hashtable, copy_a->data, i, size);
        copy_a = copy_a->next;
        i++;
    }
    t_dcll *temp = stack_a;
    while (1)
    {
        temp->index = ht_get(hashtable, temp->data, size);
        temp = temp->next;
        if (temp == stack_a)
            break;
    }
    t_dcll *stack_b = NULL;
//    printf("Disorder: %.2f%%\n\n", disorder_value * 100);
//    print_list(stack_a);
    radix_sort(&stack_a, &stack_b, (int)size);
    free_dcll(stack_a);
    free_dcll(copy_a);
    free_ht(hashtable);
    return 0;
} */

void    ht_set_hashtable(ht_t **hashtable, t_dcll *a, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ht_set(*hashtable, a->data, (size_t)i, (size_t)size);
        a = a->next;
        i++;
    }
}

void    ht_fix_stack_a(ht_t *hashtable, t_dcll **a, int size)
{
    t_dcll  *t;

    t = *a;
    while (1)
    {
        t->index = ht_get(hashtable, t->data, (size_t)size);
        t = t->next;
        if (t == *a)
            break;
    }
}

void    sort_stack(int argc, char **argv, t_flags flags)
{
    t_dcll  *stack_a;
    t_dcll  *stack_b;
    t_dcll  *copy_a;
    ht_t    *hashtable;
    int     args_count;

    args_count = count_args(flags);
    stack_a = create_stack_a(argv + args_count);
    copy_a = sort_doubly_circular(stack_a);
    if (check_if_no_dup(copy_a) == 0)
        exit_program();
    hashtable = ht_create(argc - args_count);
    ht_set_hashtable(&hashtable, copy_a, argc - args_count);
    ht_fix_stack_a(hashtable, &stack_a, argc - args_count);
    if (flags.bench == 1)
        bench_handle(&stack_a, &stack_b, argc - args_count);
    if (flags.adaptive == 1)
        adaptive_sort(&stack_a, &stack_b, argc - args_count);
    else if (flags.simple == 1)
        min_max_extraction(&stack_a, &stack_b);
    else if (flags.medium == 1)
        chunk_based_sort(&stack_a, &stack_b, argc - args_count);
    else if (flags.complex == 1)
        radix_sort(&stack_a, &stack_b, argc - args_count);
}

int	main(int argc, char **argv)
{
	t_flags	a;

    if (argc == 1)
        exit_program();
	init_flags(&a);
	check_flags(argv[1], &a);
	check_flags(argv[2], &a);
    if (check_sort_args(a) > 1)
        exit_program();
    if (!a.adaptive && !a.complex && !a.medium && !a.simple)
        a.adaptive++;
    sort_stack(argc - 1, argv + 1, a);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:42:58 by ekrama10          #+#    #+#             */
/*   Updated: 2025/11/08 11:22:10 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

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

t_dcll *merge_lists(t_dcll *a, t_dcll *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
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

t_dcll *merge_sort(t_dcll *head)
{
    t_dcll *second;
    if (!head || !head->next)
        return head;
    second = split_list(head);
    head = merge_sort(head);
    second = merge_sort(second);
    return merge_lists(head, second);
}

void make_circular(t_dcll *head)
{
    t_dcll *tail;

    if (!head)
        return;
    tail = head;
    while (tail->next)
        tail = tail->next;
    head->prev = tail;
    tail->next = head;
}

t_dcll *sort_doubly_circular(t_dcll *head)
{
    if (!head || head->next == head)
        return head;
    head->prev->next = NULL;
    head->prev = NULL;
    head = merge_sort(head);
    make_circular(head);
    return (head);
}
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_stacks(t_dcll *a, t_dcll *b)
{
	t_dcll	*head_a = a;
	t_dcll	*head_b = b;

	if (!a && !b)
		return ;

	printf("   a   |   b\n");
	printf("---------------\n");

	while (a || b)
	{
		if (a)
		{
			printf("%5d", a->data); // right-aligned in width 5
			a = (a->next != head_a) ? a->next : NULL;
		}
		else
			printf("     "); // 5 spaces for empty slot

		printf(" | ");

		if (b)
		{
			printf("%5d", b->data);
			b = (b->next != head_b) ? b->next : NULL;
		}
		else
			printf("     ");

		printf("\n");
	}
	printf("---------------\n");
	sleep(2);
}

void min_max_extraction(t_dcll **stack_a, t_dcll **stack_b)
{
	int i = 0;
	if (check_if_sorted(*stack_a) == 1)
		return ;
	t_dcll *tmp_a = *stack_a;
        t_dcll *tmp_b = *stack_b;	
	while (1)
	{
		if (tmp_a->index != i)
			rotate_a(&tmp_a);
		else
		{
			push_b(&tmp_a, &tmp_b);
			i++;
		}
		sleep(1);
		if (tmp_a == NULL)
			break;
	}
	while (tmp_b != NULL)
	{	
		push_a(&tmp_b, &tmp_a);
		sleep(1);
	}	
}
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void min_max_extraction_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	int i = 0;
	if (check_if_sorted(*stack_a) == 1)
		return ;
	t_dcll *tmp_a = *stack_a;
        t_dcll *tmp_b = *stack_b;	
	while (1)
	{
		if (tmp_a->index != i)
			rotate_a_bench(&tmp_a);
		else
		{
			push_b_bench(&tmp_a, &tmp_b);
			i++;
		}
		sleep(1);
		if (tmp_a == NULL)
			break;
	}
	while (tmp_b != NULL)
		push_a_bench(&tmp_b, &tmp_a);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:59:54 by kerama            #+#    #+#             */
/*   Updated: 2025/11/20 13:13:08 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/* t_dcll  *create_stack_a(char **args)
{
    int 	i;
	int		rank;
	t_dcll	*stack_a;

    i = 1;
	rank = 0;
	stack_a = NULL;
	while (args[i])
	{
		if (is_num(args[i]) == 0)
		{
			free_dcll(stack_a);
			return (NULL);
		}
		else
		{
			if (stack_a == NULL)
				stack_a = create_node(ft_atoi(args[i]));
			else
				add_back(&stack_a, ft_atoi(args[i]), rank);
			i++;
			rank++;
		}
	}
	return (stack_a);
} */

t_dcll	*create_stack_a(char **args)
{
	int		i;
	t_dcll	*stack_a;
	int		value;

	i = 1;
	stack_a = NULL;
	while (args[i])
	{
		if (!is_num(args[i]))
		{
			free_dcll(stack_a);
			stack_a = NULL;
			break ;
		}
		value = ft_atoi(args[i]);
		if (!stack_a)
			stack_a = create_node(value, i - 1);
		else
			add_back(&stack_a, value, i - 1);
		i++;
	}
	if (!stack_a)
		exit_program();
	return (stack_a);
}



/*
3 | 0
4 | 1
5 | 2
6 | 3
7 | 4
8 | 5
2 | 6
*/


#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"

int	check_sort_args(t_flags flags)
{
	int	i;

	i = 0;
	i = i + flags.adaptive;
	i = i + flags.simple;
	i = i + flags.complex;
	i = i + flags.medium;
	return (i);
}

void	exit_program(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	count_args(t_flags a)
{
	int	i;

	i = a.adaptive + a.bench + a.complex + a.medium + a.simple;
	return (i); 
}

void write_two_decimals(double x)
{
    int int_part = (int)x;
    int dec_part = (int)((x - int_part) * 100 + 0.5);

    ft_putnbr_fd(int_part, 2);
    ft_putchar_fd('.', 2);
    if (dec_part < 10)
        ft_putchar_fd('0', 2);
    ft_putnbt_fd(dec_part, 2);
}

void adaptive_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	float disorder_num;

	disorder_num = disorder(stack_a);
	if (disorder_num <= 0.2)
		min_max_extraction(stack_a, stack_b);
	else if (disorder_num <= 0.5)
		chunk_based_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:28:38 by kerama            #+#    #+#             */
/*   Updated: 2025/11/18 09:45:06 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int c(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_num(char *nptr)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	if (nptr[i] == '-'  || nptr[i] == '+')
		i++;
	while(nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - '0');
		if (-num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (1);
}

void number_of_ops(char p)
{
	static int ops;
	ops++;
	if (p == 'p')
		ft_putnbr_fd(ops, 1);
//	usleep(10000);
}

void init_flags(t_flags *f)
{
    f->simple = 0;
    f->medium = 0;
    f->complex = 0;
    f->adaptive = 0;
    f->bench = 0;
}

void	check_flags(char **flag, t_flags *args)
{
	if (c(flag, "--bench") == 0)
		args->bench++;
	else if (c(flag, "--simple") == 0)
		args->simple++;
	else if (c(flag, "--medium") == 0)
		args->medium++;
	else if (c(flag, "--complex") == 0)
		args->complex++;
	else if (c(flag, "--adaptive") == 0)
		args->adaptive++;
}#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int count_zero_bits(int n, int k)
{
	int block_size = 1L << (k + 1); 
	int half_block = 1L << k; 
	int total = n + 1;       

	int full_blocks = total / block_size;
	int remainder = total % block_size;

	int zeros = full_blocks * half_block;

	int extra = remainder - half_block;
	if (extra < 0)
        	extra = 0;
	if (extra > half_block)
        	extra = half_block;

    	return zeros + extra;
}

int	binary_digits(unsigned int n)
{
	int bits = 0;

	if (n == 0)
		return 1;

	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return bits;
}

void push_zeros(t_dcll **stack_a, t_dcll **stack_b, int k, int n)
{
	int i = 0;
	while (i < n)
	{
		if ((((*stack_a)->index >> k) & 1) == 0)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a);
	}
	while (*stack_b)
		push_a(stack_b, stack_a);
}

void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int num_of_zeros;
	int i = i;
	int loops = binary_digits(size - 1);
	while (i <= loops)
	{
		num_of_zeros = count_zero_bits(size - 1, i);
		if (num_of_zeros >= size - 1 - num_of_zeros)
			push_zeros(stack_a, stack_b, i, num_of_zeros);
		else
			push_ones(stack_a, stack_b, i, size - 1 - num_of_zeros);
		i++;
	}
}

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>


void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int i = 0;
	int loops = binary_digits(size - 1);
	int j = 0;
	while (i < loops)
	{
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		if (check_if_sorted_asc(*stack_a))
			break;
		j = 0;
		i++;
	}
}
#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>


void radix_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o)
{
	int i = 0;
	int loops = binary_digits(size - 1);
	int j = 0;
	while (i < loops)
	{
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b_bench(stack_a, stack_b, o);
			else
				rotate_a_bench(stack_a, o);
			j++;
		}
		while (*stack_b)
			push_a_bench(stack_b, stack_a, o);
		if (check_if_sorted_asc(*stack_a))
			break;
		j = 0;
		i++;
	}
}
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int main(void)
