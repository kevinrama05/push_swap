/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:26:09 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/20 00:09:49 by ekrama10         ###   ########.fr       */
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

// static int        is_num(char *nptr)
// {
//         int                        i;
//         long long        num;

//         i = 0;
//         num = 0;
//         if (nptr[i] == '-' || nptr[i] == '+')
//                 i++;
//         while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
//         {
//                 num = (num * 10) + (nptr[i] - '0');
//                 if (-num < INT_MIN || num > INT_MAX)
//                         return (0);
//                 i++;
//         }
//         if (nptr[i] != '\0')
//                 return (0);
//         return (1);
// }

// static void	ft_check_args(t_ps_data *data, char **argv)
// {
// 	int	i;

// 	ft_parse_flags(data, argv);
// 	i = 1 + data->args_num;
// 	while (argv[i])
// 	{
// 		if (is_num(argv[i]) == 0)
// 			ft_clean_exit(data, EXIT_FAILURE);
// 		i++;
// 	}
// }

static int	ft_push_swap(int argc, char **argv)
{
	t_ps_data	*data;
	char		**num_args;
	int			num_count;

	data = ft_init_data();
	if (!data)
		return (1);
	// ft_check_args(data, argv);
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
	ft_clean_exit(data, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (ft_push_swap(argc, argv));
}
