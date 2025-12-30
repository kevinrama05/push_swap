/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:26:09 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/21 12:28:49 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_free_param_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	main_free(t_ps_data *data)
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
}

static int	ft_push_swap(int argc, char **argv)
{
	t_ps_data	*data;
	char		**num_args;
	int			num_count;

	data = ft_init_data();
	if (!data)
		return (1);
	num_args = ft_parse_arguments(data, argc, argv);
	if (!num_args)
		ft_clean_exit(data, EXIT_FAILURE);
	num_count = ft_get_num_count(num_args);
	ft_build_stack_a(data, num_count, num_args);
	ft_free_param_array(num_args);
	ft_index_stack(data->a);
	ft_solve(data);
	if (data->flag_bench)
		ft_print_benchmark(data);
	main_free(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (ft_push_swap(argc, argv));
}
