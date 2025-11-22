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
