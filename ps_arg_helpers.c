/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arg_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:11:33 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/16 19:59:19 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_arg_number(const char *arg)
{
	if (ft_is_strategy_selector(arg))
		return (0);
	if (ft_strcmp(arg, "--bench") == 0)
		return (0);
	if (arg[0] == '-' && arg[1] == '-')
		return (0);
	return (1);
}

static char	**ft_join_args(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*joined;
	char	**split_res;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		if (ft_is_arg_number(argv[i]))
		{
			tmp = ft_strjoin(joined, argv[i]);
			free(joined);
			joined = ft_strjoin(tmp, " ");
			free(tmp);
		}
		i++;
	}
	split_res = ft_split(joined, ' ');
	free(joined);
	return (split_res);
}

char	**ft_collect_numbers(int argc, char **argv, t_ps_data *data)
{
	char	**res;

	if (argc == 2 && ft_is_arg_number(argv[1]))
		res = ft_split(argv[1], ' ');
	else
		res = ft_join_args(argc, argv);
	if (!res)
		ft_clean_exit(data, EXIT_FAILURE);
	return (res);
}

void	ft_index_stack(t_stack *a)
{
	t_node	*curr;
	t_node	*compare;
	int		idx;

	if (!a || a->size == 0)
		return ;
	curr = a->head;
	while (curr)
	{
		idx = 0;
		compare = a->head;
		while (compare)
		{
			if (curr->value > compare->value)
				idx++;
			compare = compare->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}

void	ft_assign_strategy_details(t_ps_data *data, const char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		data->flag_simple = 1;
		data->strategy_name = "Simple Sort (e.g., Insertion)";
		data->complexity_class = "O(n2)";
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		data->flag_medium = 1;
		data->strategy_name = "Medium Sort (e.g., Chunking)";
		data->complexity_class = "O(n√n)";
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		data->flag_complex = 1;
		data->strategy_name = "Complex Sort (e.g., Radix)";
		data->complexity_class = "O(n log n)";
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		data->flag_adaptive = 1;
		data->strategy_name = "Adaptive Sort";
		data->complexity_class = "Determined at Runtime";
	}
}
