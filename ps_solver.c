/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:32:25 by kerama            #+#    #+#             */
/*   Updated: 2025/12/18 11:46:21 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_sort_adaptive(t_ps_data *data, float disorder)
// {
// 	if (disorder <= 0.2)
// 		ft_sort_simple(data);
// 	else if (disorder <= 0.5)
// 		ft_sort_chunk(data);
// 	else
// 		ft_sort_radix(data);
// }

void	ft_tiny_sort(t_ps_data *data)
{
	int		a;
	int		b;
	int		c;

	a = data->a->head->index;
	b = data->a->head->next->index;
	c = data->a->tail->index;
	if (data->a->size == 2 && a > b)
		sa(data);
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
}

int	ft_is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size < 2)
		return (1);
	current = a->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_solve(t_ps_data *data)
{
 	// float	disorder;

	// if (ft_is_sorted(data->a))
	// {
	// 	data->strategy_name = "already sorted";
	// 	data->complexity_class = "O(1)";
	// 	return ;
	// }
	// ft_sort_simple(data);
	// disorder = ft_calculate_disorder(data->a);
	// if (data->flag_adaptive == 1)
	// 	ft_sort_adaptive(data, disorder);
	// else if (data->flag_simple == 1)
	// 	ft_sort_simple(data);
	// else if (data->flag_medium == 1)
		ft_sort_chunk(data);
	// else if (data->flag_complex == 1)
	// 	ft_sort_radix(data);
	// if (data->flag_bench == 1)
	// 	ft_print_benchmark(data);
}
