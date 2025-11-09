/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:28:38 by kerama            #+#    #+#             */
/*   Updated: 2025/11/08 13:09:49 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_num(char *nptr)
{
	char	*word;
	int		i;

	i = ft_atoi(nptr);
	word = ft_itoa(i);
	printf("%d\n", ft_strcmp(word, nptr));
	if (ft_strcmp(word, nptr) == 0)
		return (1);
	else
		return (0);
}
