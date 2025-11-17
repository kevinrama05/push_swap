/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:28:38 by kerama            #+#    #+#             */
/*   Updated: 2025/11/17 19:03:45 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int c(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

void number_of_ops(char p)
{
	static int ops;
	ops++;
	if (p == 'p')
		ft_putnbr_fd(ops, 1);
//	usleep(10000);
}

void init_flags(t_flags *f)
{
    f->simple = 0;
    f->medium = 0;
    f->complex = 0;
    f->adaptive = 0;
    f->bench = 0;
}

void	check_flags(char **flag, t_flags *args)
{
	if (c(flag, "--bench") == 0)
		args->bench++;
	else if (c(flag, "--simple") == 0)
		args->simple++;
	else if (c(flag, "--medium") == 0)
		args->medium;
	else if ()
}