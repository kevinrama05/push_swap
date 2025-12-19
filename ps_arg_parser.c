/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arg_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:10:21 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/19 14:34:50 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_strategy_selector(const char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0 || ft_strcmp(arg, "--medium") == 0
		|| ft_strcmp(arg, "--complex") == 0 || ft_strcmp(arg,
			"--adaptive") == 0)
		return (1);
	return (0);
}

void	ft_set_strategy(t_ps_data *data, const char *arg)
{
	if (data->flag_simple || data->flag_medium || data->flag_complex
		|| data->flag_adaptive)
		ft_error_exit();
	ft_assign_strategy_details(data, arg);
}

void	ft_parse_flags(t_ps_data *data, char **argv)
{
	if (ft_is_strategy_selector(argv[1]))
		ft_set_strategy(data, argv[1]);
	else if (ft_strcmp(argv[1], "--bench") == 0)
	{
		data->flag_bench = 1;
		data->args_num++;
	}
	if (ft_is_strategy_selector(argv[2]))
		ft_set_strategy(data, argv[2]);
	else if (ft_strcmp(argv[2], "--bench") == 0)
	{
		data->flag_bench = 1;
		data->args_num++;
	}
	if (data->args_num == 0)
	{
		data->flag_adaptive = 1;
	}
}

int	ft_get_num_count(char **num_args)
{
	int	count;

	count = 0;
	while (num_args && num_args[count])
		count++;
	return (count);
}

char	**ft_parse_arguments(t_ps_data *data, int argc, char **argv)
{
	char **num_args;

	ft_parse_flags(data, argv);
	num_args = ft_collect_numbers(argc, argv, data);
	if (!num_args || !num_args[0])
	{
		if (argc > 1 && !num_args)
			ft_error_exit();
		ft_clean_exit(data, EXIT_SUCCESS);
	}
	return (num_args);
}
