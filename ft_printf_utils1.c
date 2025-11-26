/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:23:38 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:45:18 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	print_hex(int *count, unsigned long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_hex(count, n / 16);
	write(2, &hex[n % 16], 1);
	(*count)++;
}

void	print_bigx(int *count, unsigned long n)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		print_bigx(count, n / 16);
	write(2, &hex[n % 16], 1);
	(*count)++;
}

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	addr;

	if (ptr == NULL)
	{
		write(2, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	addr = (unsigned long)ptr;
	write(2, "0x", 2);
	(*count) += 2;
	if (addr == 0)
	{
		ft_putchar(count, '0');
		return ;
	}
	print_hex(count, addr);
}

void	ft_putchar(int *count, char c)
{
	write(2, &c, 1);
	(*count)++;
}

void	ft_putstr(int *count, char *s)
{
	int	i;

	if (!s)
	{
		write(2, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(count, s[i]);
		i++;
	}
}
