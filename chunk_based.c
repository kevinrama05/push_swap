/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:26 by kerama            #+#    #+#             */
/*   Updated: 2025/11/13 11:52:35 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"


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
	if (*stack == NULL)
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
	t_dcll *tmp_a = *stack_a;
	t_dcll *tmp_b = *stack_b;
	while (list_size(*stack_b) != max - min + 1)
	{
		if (max >= tmp_a->index && tmp_a->index >= min)
		{
			if (tmp_a->index > tmp_b->index)
				push_b(stack_a, stack_b);
			else if (tmp_a->index < tmp_b->index && tmp_a->index > tmp_b->next->index)
			{
				push_b(stack_a, stack_b);
				swap_b(stack_b);
			}
			else
			{
				push_b(stack_a, stack_b);
				rev_rotate_b(stack_b);
			}
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
	t_dcll *tmp_a = *stack_a;
	t_dcll *tmp_b = *stack_b;
	int chunk = isqrt(size);
	if (chunk < 5)
		chunk = 5;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	int max = size;
	int min = size - chunk + 1;
	if (min < 0)
		min = 0;
	while (1)
	{
		push_chunk(&tmp_a, &tmp_b, min, max);
		if (min != size)
			while (tmp_a->index != max + 1)
				rotate_a(&tmp_a);
		push_a(&tmp_b, &tmp_a);
		while (tmp_b != NULL)
		{
			if (tmp_b->index == tmp_a->index - 1)
				push_a(&tmp_b, &tmp_a);
			else if (tmp_b->next->index == tmp_a->index - 1)
			{
				swap_b(&tmp_b);
				push_b(&tmp_b, &tmp_a);
			}
			else if (tmp_b->prev->index == tmp_a->index - 1)
			{
				rev_rotate_b(&tmp_b);
				push_b(&tmp_b, &tmp_a);
			}
			else if (tmp_b->prev->prev->index == tmp_a->index - 1)
			{
				rev_rotate_b(&tmp_b);
				rev_rotate_b(&tmp_b);
				push_b(&tmp_b, &tmp_a);
			}
			else
				rotate_b(&tmp_b);
		
		}
		new_chunk(&min, &max, chunk);
		if (min == 0 && max == 0)
			break;
	}
}
