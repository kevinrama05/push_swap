/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:50:53 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:50:54 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	min_max_extraction(t_dcll **stack_a, t_dcll **stack_b)
{
	int		i;
	t_dcll	*tmp_a;
	t_dcll	*tmp_b;

	i = 0;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (1)
	{
		if (tmp_a->index != i)
			rotate_a(&tmp_a);
		else
		{
			push_b(&tmp_a, &tmp_b);
			i++;
		}
		if (tmp_a == NULL)
			break ;
	}
	while (tmp_b != NULL)
	{
		push_a(&tmp_b, &tmp_a);
	}
}
