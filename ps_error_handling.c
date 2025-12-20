/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:21:40 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/20 01:41:15 by ekrama10         ###   ########.fr       */
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

static int	ft_check_duplicates(t_stack *a)
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
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_build_stack_a(t_ps_data *data, int num_count, char **num_args)
{
	int		i;
	int		num;
	int		j;
	t_node	*new_node;

	i = 0;
	while (i < num_count)
	{
		num = ft_check_int_and_range(num_args[i], data);
		new_node = ft_new_node(num);
		ft_add_node_back(data->a, new_node);
		i++;
	}
	if (ft_check_duplicates(data->a))
	{
		j = 0;
		while (num_args[j])
		{
			free(num_args[j]);
			j++;
		}
		free(num_args);
		ft_free_and_exit(data);
	}
}

void	ft_free_and_exit(t_ps_data *data)
{
	if (data)
	{
		if (data->a)
		{
			ft_free_stack(data->a);
			free(data->a);
		}
		if (data->b)
		{
			ft_free_stack(data->b);
			free(data->b);
		}
		if (data->counts)
			free(data->counts);
		free(data);
	}
	ft_error_exit();
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
