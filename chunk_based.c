/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:26 by kerama            #+#    #+#             */
/*   Updated: 2025/11/11 12:17:16 by kerama           ###   ########.fr       */
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

void sort_b(t_dcll **stack_b, int min, int max)
{
    if (check_if_sorted_dec(*stack_b) == 1)
        return ;
    t_dcll *temp = *stack_b;
    while (1)
    {
        if (temp->index == max && temp->prev->index == min)
        {
            if (check_if_sorted_dec(temp) == 1)
                return ;
        }
        if (temp->index == min && )
    }
}