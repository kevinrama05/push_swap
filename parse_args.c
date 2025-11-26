/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:59:54 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:51:23 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_dcll	*create_stack_a(char **args)
{
	int		i;
	t_dcll	*stack_a;
	int		value;

	i = 0;
	stack_a = NULL;
	while (args[i])
	{
		if (!is_num(args[i]))
		{
			if (!stack_a)
				exit_program();
			else
			{
				free_dcll(stack_a);
				stack_a = NULL;
				break ;
			}
		}
		value = ft_atoi(args[i]);
		if (!stack_a)
			stack_a = create_node(value, i - 1);
		else
			add_back(&stack_a, value, i - 1);
		i++;
	}
	if (!stack_a)
		exit_program();
	return (stack_a);
}
