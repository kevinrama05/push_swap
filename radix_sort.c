/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:52:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:52:05 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	binary_digits(unsigned int n)
{
	int	bits;

	bits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

void	radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size)
{
	int	i;
	int	loops;
	int	j;

	i = 0;
	loops = binary_digits(size - 1);
	j = 0;
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
			break ;
		j = 0;
		i++;
	}
}
