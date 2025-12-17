/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:15:12 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 23:15:42 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_count_mistakes(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;

	mistakes = 0;
	i = a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes);
}

float	ft_calculate_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	long	n;

	if (!a || a->size < 2)
		return (0.0f);
	n = a->size;
	total_pairs = (n * (n - 1)) / 2;
	mistakes = ft_count_mistakes(a);
	return ((float)mistakes / (float)total_pairs);
}

static void	ft_print_row_1(t_ps_counts *c)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(c->sa_count, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(c->sb_count, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(c->ss_count, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(c->pa_count, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(c->pb_count, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_row_2(t_ps_counts *c)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(c->ra_count, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(c->rb_count, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(c->rr_count, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(c->rra_count, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(c->rrb_count, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(c->rrr_count, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_benchmark(t_ps_data *data)
{
	float d;
	int frac;

	if (!data->flag_bench)
		return ;
    // TODO: Calculate disorder before sorting and store it in t_ps_data
	d = ft_calculate_disorder(data->a);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(d * 100), 2);
	ft_putstr_fd(".", 2);
	frac = (int)(d * 10000) % 100;
	if (frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(data->strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(data->complexity_class, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(data->counts->total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_print_row_1(data->counts);
	ft_print_row_2(data->counts);
}
