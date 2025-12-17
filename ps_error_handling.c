/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:21:40 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/16 19:38:37 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_int_and_range(const char *arg, t_ps_data *data)
{
	long	num_l;
	int		i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		ft_clean_exit(data, EXIT_FAILURE);
	while (arg[i])
	{
		if (!ft_is_digit(arg[i]))
			ft_clean_exit(data, EXIT_FAILURE);
		i++;
	}
	num_l = ft_atol(arg);
	if (num_l < INT_MIN || num_l > INT_MAX)
		ft_clean_exit(data, EXIT_FAILURE);
	return ((int)num_l);
}

static void	ft_check_duplicates(t_stack *a, t_ps_data *data)
{
	t_node	*current;
	t_node	*runner;

	current = a->head;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				ft_clean_exit(data, EXIT_FAILURE);
			runner = runner->next;
		}
		current = current->next;
	}
}

void	ft_build_stack_a(t_ps_data *data, int num_count, char **num_args)
{
	int		i;
	int		num;
	t_node	*new_node;

	i = 0;
	while (i < num_count)
	{
		num = ft_check_int_and_range(num_args[i], data);
		new_node = ft_new_node(num);
		ft_add_node_back(data->a, new_node);
		i++;
	}
	ft_check_duplicates(data->a, data);
}

// void	ft_is_sorted(t_ps_data *data)
// {
// 	t_node	*current;

// 	if (data->a->size < 2)
// 		ft_clean_exit(data, EXIT_SUCCESS);
// 	current = data->a->head;
// 	while (current && current->next)
// 	{
// 		if (current->value > current->next->value)
// 			return ;
// 		current = current->next;
// 	}
// 	ft_clean_exit(data, EXIT_SUCCESS);
// }
