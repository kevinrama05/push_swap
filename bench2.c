/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:03:30 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 15:04:14 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

char	*flag_str(t_flags flag)
{
	if (flag.adaptive)
		return ("Adaptive");
	else if (flag.simple)
		return ("Simple");
	else if (flag.medium)
		return ("Medium");
	else
		return ("Complex");
}

char	*complexity(t_flags flag, double disorder)
{
	if (flag.complex)
		return ("O(n log n)");
	else if (flag.medium)
		return ("O(n√n)");
	else if (flag.simple)
		return ("O(n²)");
	else
	{
		if (disorder <= 0.2)
			return ("O(n²)");
		else if (disorder <= 0.5)
			return ("O(n√n)");
		else
			return ("O(n log n)");
	}
}

int	total_ops(t_ops o)
{
	int	i;

	i = 0;
	i += o.sa;
	i += o.sb;
	i += o.ss;
	i += o.pa;
	i += o.pb;
	i += o.ra;
	i += o.rb;
	i += o.rr;
	i += o.rra;
	i += o.rrb;
	i += o.rrr;
	return (i);
}

void	bench_handle(t_dcll *a, t_dcll *b, int size, t_flags flag)
{
	t_ops	o;
	float	d;

	d = disorder(&a);
	if (list_size(a) == 1)
		d = 0;
	init_ops(&o);
	if (flag.adaptive)
		adaptive_sort_bench(&a, &b, size, &o);
	else if (flag.simple)
		min_max_extraction_bench(&a, &b, &o);
	else if (flag.medium)
		chunk_based_sort_bench(&a, &b, size, &o);
	else if (flag.complex)
		radix_sort_bench(&a, &b, size, &o);
	ft_printf("[bench] disorder: %f%%\n", d);
	ft_printf("[bench] strategy: %s / %s\n", flag_str(flag), complexity(flag,
			d));
	ft_printf("[bench] total_ops: %i\n", total_ops(o));
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", o.sa, o.sb, o.ss,
		o.pa, o.pb);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n", o.ra,
		o.rb, o.rr, o.rra, o.rrb, o.rrr);
}
