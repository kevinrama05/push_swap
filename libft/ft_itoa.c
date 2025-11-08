/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:51:34 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 11:02:29 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static void	ft_is_negative(int *sign, int *num)
{
	if (*num < 0)
	{
		*num = -(*num);
		*sign = 1;
	}
	else
		*sign = 0;
}

char	*ft_itoa(int n)
{
	int		sign;
	int		indexes;
	char	*number;

	ft_is_negative(&sign, &n);
	if (n == 0)
		return ("0");
	else if (n == -2147483648)
		return ("-2147483648");
	number = (char *)malloc(sizeof(char) * (ft_digits(n) + sign + 1));
	if (!number)
		return (NULL);
	indexes = ft_digits(n) + sign - 1;
	number[indexes] = '\0';
	while (n != 0)
	{
		number[indexes] = (n % 10) + '0';
		n = n / 10;
		indexes--;
	}
	if (sign == 1)
		number[0] = '-';
	return (number);
}

// int main(void)
// {
// 	int n = 1654684;
// 	printf("Number: %s\n", ft_itoa(n));
// 	return 0;
// }