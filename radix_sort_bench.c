/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_bench.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:52:06 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:52:07 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	radix_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o)
{
	int	i;
	int	loops;
	int	j;

	i = 0;
	loops = binary_digits(size - 1);
	j = 0;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
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
			break ;
		j = 0;
		i++;
	}
}
