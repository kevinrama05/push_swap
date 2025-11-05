/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prng.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:34:01 by kerama            #+#    #+#             */
/*   Updated: 2025/11/04 12:52:46 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned long	seed(void)
{
	int				x;
	unsigned long	k;

	k = (unsigned long)&x;
	return (k);
}

static unsigned long	my_rand(unsigned long *seed)
{
	*seed = 6364136223846793005UL * (*seed) + 1UL;
	return (*seed);
}

unsigned long	my_rand_range(unsigned long *seed, int min, int max)
{
	unsigned long	r;

	r = my_rand(seed);
	return ((r % (max - min + 1)) + min);
}
