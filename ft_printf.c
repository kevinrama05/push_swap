/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:23:44 by kerama            #+#    #+#             */
/*   Updated: 2025/11/23 11:36:08 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

void	handle_format(const char *ptr, int *i, int *total, va_list args)
{
	if (ptr[*i + 1] == '%')
		ft_putchar(total, '%');
	else if (ptr[*i + 1] == 'f')
		ft_putdouble(va_arg(args, double));
	else if (ptr[*i + 1] == 'c')
		ft_putchar(total, va_arg(args, int));
	else if (ptr[*i + 1] == 's')
		ft_putstr(total, va_arg(args, char *));
	else if (ptr[*i + 1] == 'p')
		ft_putptr(va_arg(args, void *), total);
	else if (ptr[*i + 1] == 'd' || ptr[*i + 1] == 'i')
		ft_putnum(total, va_arg(args, int));
	else if (ptr[*i + 1] == 'u')
		ft_putu(total, va_arg(args, unsigned int));
	else if (ptr[*i + 1] == 'x')
		print_hex(total, va_arg(args, unsigned int));
	else if (ptr[*i + 1] == 'X')
		print_bigx(total, va_arg(args, unsigned int));
	else
	{
		ft_putchar(total, ptr[*i]);
		ft_putchar(total, ptr[*i + 1]);
	}
	(*i) += 2;
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		total;
	int		i;

	va_start(args, ptr);
	total = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			if (!ptr[i + 1])
				break ;
			handle_format(ptr, &i, &total, args);
		}
		else
			ft_putchar(&total, ptr[i++]);
	}
	va_end(args);
	return (total);
}
