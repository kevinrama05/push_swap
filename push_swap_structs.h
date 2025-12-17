/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgramozi <vgramozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:12:17 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/14 18:45:00 by vgramozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			name;
}					t_stack;

typedef struct s_ps_counts
{
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				total_ops;
}					t_ps_counts;

typedef struct s_ps_data
{
	t_stack			*a;
	t_stack			*b;
	t_ps_counts		*counts;
	int				flag_bench;
	int				flag_simple;
	int				flag_medium;
	int				flag_complex;
	int				flag_adaptive;
	char			*strategy_name;
	char			*complexity_class;
}					t_ps_data;

#endif