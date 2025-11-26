/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:57:56 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 15:07:56 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	free_ht(ht_t *table)
{
	entry_t	*entry;
	entry_t	*temp;
	int		i;

	i = 0;
	if (!table || !table->entries)
		return ;
	while (i < table->size)
	{
		entry = table->entries[i];
		while (entry)
		{
			temp = entry;
			entry = entry->next;
			free(temp);
		}
		i++;
	}
	free(table->entries);
	free(table);
}
