/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:23:28 by kerama            #+#    #+#             */
/*   Updated: 2025/11/24 00:31:13 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_putnum(int *count, int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr(count, "-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar(count, '-');
	}
	if (n >= 10)
		ft_putnum(count, n / 10);
	c = '0' + (n % 10);
	ft_putchar(count, c);
}

void	ft_putu(int *count, unsigned int n)
{
	char	c;

	if (n == 0)
	{
		ft_putchar(count, '0');
		return ;
	}
	if (n >= 10)
		ft_putu(count, n / 10);
	c = '0' + (n % 10);
	ft_putchar(count, c);
}

void ft_putdouble(double x)
{
    int int_part = (int)(x * 100);
    int dec_part = (int)(x * 10000 / 100 + 0.5);

    if (x == 1.0)
    {
    	ft_putnbr_fd(100, 2);
	ft_putchar_fd('.', 2);
	ft_putstr_fd("00", 2);
	return ;
    }
    ft_putnbr_fd(int_part, 2);
    ft_putchar_fd('.', 2);
    if (dec_part < 10)
        ft_putstr_fd("0", 2);
    ft_putnbr_fd(dec_part, 2);
}
