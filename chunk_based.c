/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:26 by kerama            #+#    #+#             */
/*   Updated: 2025/11/13 13:51:10 by ekrama10         ###   ########.fr       */
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
		if (max >= (*stack_a)->index && (*stack_a)->index >= min)
		{
			if ((*stack_a)->index > (*stack_b)->index)
			{push_b(stack_a, stack_b);print_stacks(stack_a, stack_b);}
			else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index > (*stack_b)->next->index)
			{
				print_stacks(stack_a, stack_b);
				push_b(stack_a, stack_b);
				print_stacks(stack_a, stack_b);
				swap_b(stack_b);
			}
			else
			{
				print_stacks(stack_a, stack_b);
				push_b(stack_a, stack_b);
				print_stacks(stack_a, stack_b);
				rev_rotate_b(stack_b);
			}
			i++;
		}
		else
		{	print_stacks(stack_a, stack_b);
			rev_rotate_a(stack_a);}
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
	int max = size;
	int min = size - chunk + 1;
	if (min < 0)
		min = 0;
	while (1)
	{
		push_chunk(stack_a, stack_b, min, max);
		if (min != size)
			while ((*stack_a)->index != max + 1)
			{rotate_a(stack_a);print_stacks(stack_a, stack_b);}
		print_stacks(stack_a, stack_b);
		push_a(stack_b, stack_a);
		while (stack_b != NULL)
		{
			if ((*stack_b)->index == (*stack_a)->index - 1)
			{push_a(stack_b, stack_a);print_stacks(stack_a, stack_b);}
			else if ((*stack_b)->next->index == (*stack_a)->index - 1)
			{
				print_stacks(stack_a, stack_b);
				swap_b(stack_b);
				print_stacks(stack_a, stack_b);
				push_b(stack_b, stack_a);
			}
			else if ((*stack_b)->prev->index == (*stack_a)->index - 1)
			{
				print_stacks(stack_a, stack_b);
				rev_rotate_b(stack_b);
				print_stacks(stack_a, stack_b);
				push_b(stack_b, stack_a);
			}
			else if ((*stack_b)->prev->prev->index == (*stack_a)->index - 1)
			{
				print_stacks(stack_a, stack_b);
				rev_rotate_b(stack_b);
				print_stacks(stack_a, stack_b);
				rev_rotate_b(stack_b);
				print_stacks(stack_a, stack_b);
				push_b(stack_b, stack_a);
			}
			else
			{rotate_b(stack_b);print_stacks(stack_a, stack_b);}
		
		}
		new_chunk(&min, &max, chunk);
		if (min == 0 && max == 0)
			break;
	}
}
