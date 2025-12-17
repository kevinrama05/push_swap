/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_memory_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:23:04 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 18:50:46 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_counts	*ft_init_counts(void)
{
	t_ps_counts	*counts;

	counts = (t_ps_counts *)malloc(sizeof(t_ps_counts));
	if (!counts)
		return (NULL);
	counts->sa_count = 0;
	counts->sb_count = 0;
	counts->ss_count = 0;
	counts->pa_count = 0;
	counts->pb_count = 0;
	counts->ra_count = 0;
	counts->rb_count = 0;
	counts->rr_count = 0;
	counts->rra_count = 0;
	counts->rrb_count = 0;
	counts->rrr_count = 0;
	counts->total_ops = 0;
	return (counts);
}

t_stack	*ft_init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

t_ps_data	*ft_init_data(void)
{
	t_ps_data	*data;

	data = (t_ps_data *)malloc(sizeof(t_ps_data));
	if (!data)
		ft_error_exit();
	data->a = ft_init_stack('a');
	data->b = ft_init_stack('b');
	data->counts = ft_init_counts();
	if (!data->a || !data->b || !data->counts)
		ft_clean_exit(data, EXIT_FAILURE);
	data->flag_bench = 0;
	data->flag_simple = 0;
	data->flag_medium = 0;
	data->flag_complex = 0;
	data->flag_adaptive = 0;
	data->strategy_name = NULL;
	data->complexity_class = NULL;
	return (data);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	ft_clean_exit(t_ps_data *data, int success_code)
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
	exit(success_code);
}
