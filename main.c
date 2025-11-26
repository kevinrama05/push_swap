/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:51:03 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:58:49 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ht_create_hashtable(ht_t **hashtable, t_dcll *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ht_set(*hashtable, a->data, (size_t)i, (size_t)size);
		a = a->next;
		i++;
	}
}

void	ht_fix_stack_a(ht_t *hashtable, t_dcll **a, int size)
{
	t_dcll	*t;

	t = *a;
	while (1)
	{
		t->index = ht_get(hashtable, t->data, (size_t)size);
		t = t->next;
		if (t == *a)
			break ;
	}
}

void	sort_stack(int argc, char **argv, t_flags flags)
{
	t_dcll	*stack_a;
	t_dcll	*stack_b;
	t_dcll	*copy_a;
	ht_t	*hashtable;

	stack_a = create_stack_a(argv + flags.args);
	stack_b = NULL;
	if (stack_a == stack_a->next)
	{
		if (flags.bench)
		{
			bench_handle(stack_a, stack_b, argc - flags.args, flags);
			free_dcll(stack_a);
			return ;
		}
		else
		{
			free_dcll(stack_a);
			return ;
		}
	}
	copy_a = copy_list(stack_a);
	copy_a = sort_doubly_circular(copy_a);
	if (check_if_no_dup(copy_a) == 0)
	{
		free_dcll(stack_a);
		free_dcll(copy_a);
		exit_program();
	}
	hashtable = ht_create(argc - flags.args);
	ht_create_hashtable(&hashtable, copy_a, argc - flags.args);
	ht_fix_stack_a(hashtable, &stack_a, argc - flags.args);
	if (flags.bench == 1)
		bench_handle(stack_a, stack_b, argc - flags.args, flags);
	else if (flags.adaptive == 1)
		adaptive_sort(&stack_a, &stack_b, argc - flags.args);
	else if (flags.simple == 1)
		min_max_extraction(&stack_a, &stack_b);
	else if (flags.medium == 1)
		chunk_based_sort(&stack_a, &stack_b, argc - flags.args);
	else if (flags.complex == 1)
		radix_sort(&stack_a, &stack_b, argc - flags.args);
	free_dcll(stack_a);
	free_dcll(copy_a);
	free_ht(hashtable);
}

void	check_args(char *arg)
{
	if (is_num(arg) == 1)
		exit(1);
	else
		exit_program();
}

int	main(int argc, char **argv)
{
	t_flags	a;

	if (argc == 1)
		exit_program();
	if (argc == 2)
		check_args(argv[1]);
	init_flags(&a);
	check_flags(argv[1], &a);
	check_flags(argv[2], &a);
	if (check_sort_args(a) > 1)
		exit_program();
	if (a.bench > 1)
		exit_program();
	a.args = count_args(a);
	if (!a.adaptive && !a.complex && !a.medium && !a.simple)
		a.adaptive++;
	sort_stack(argc - 1, argv + 1, a);
	return (0);
}
