/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:28:38 by kerama            #+#    #+#             */
/*   Updated: 2025/11/10 09:16:28 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	is_num(char *nptr)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	if (nptr[i] == '-'  || nptr[i] == '+')
		i++;
	while(nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - '0');
		if (-num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (1);
}

/* int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		printf("Usage: %s <arg1> <arg2> ...\n", argv[0]);
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		if (is_num(argv[i]))
			printf("✅ \"%s\" is a valid integer.\n", argv[i]);
		else
			printf("❌ \"%s\" is NOT a valid integer.\n", argv[i]);
	}
	return (0);
}
 */