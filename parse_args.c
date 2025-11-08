/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:59:54 by kerama            #+#    #+#             */
/*   Updated: 2025/11/08 13:27:44 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_dcll  *create_stack_a(char **args)
{
    int 	i;
	int		rank;
	t_dcll	*sorted;

    i = 1;
	rank = 0;
	sorted == NULL;
	while (args[i])
	{
		if (is_num(args[i]) == 0)
		{
			free_dcll(sorted);
			return (NULL);
		}
		else
		{
			if (sorted == NULL)
				sorted = create_node(ft_atoi(args[i]));
			else
				add_back(&sorted, ft_atio(args[i]), rank);
			i++;
			rank++;
		}
	}
	return (sorted);
}