/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:45:31 by kerama            #+#    #+#             */
/*   Updated: 2025/11/26 14:57:49 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

unsigned int	hash(int key, size_t size)
{
	unsigned int	x;

	x = (unsigned int)key;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (x % size);
}

entry_t	*ht_pair(unsigned int key, unsigned int value)
{
	entry_t	*entry;

	entry = malloc(sizeof(entry_t) * 1);
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return (entry);
}

ht_t	*ht_create(size_t size)
{
	ht_t	*hashtable;
	size_t	i;

	hashtable = malloc(sizeof(ht_t) * 1);
	hashtable->entries = malloc(sizeof(entry_t *) * size);
	hashtable->size = size;
	i = 0;
	while (i < size)
		hashtable->entries[i++] = NULL;
	return (hashtable);
}

void	ht_set(ht_t *hashtable, unsigned int key, unsigned int value,
		size_t size)
{
	unsigned int	slot;
	entry_t			*entry;
	entry_t			*prev;

	slot = hash(key, size);
	entry = hashtable->entries[slot];
	if (entry == NULL)
	{
		hashtable->entries[slot] = ht_pair(key, value);
		return ;
	}
	while (entry != NULL)
	{
		if (entry->key == key)
		{
			entry->value = value;
			return ;
		}
		prev = entry;
		entry = prev->next;
	}
	prev->next = ht_pair(key, value);
}

unsigned int	ht_get(ht_t *hashtable, unsigned int key, size_t size)
{
	unsigned int	slot;
	entry_t			*entry;

	slot = hash(key, size);
	entry = hashtable->entries[slot];
	if (entry == NULL)
	{
		return (-1);
	}
	while (entry != NULL)
	{
		if (entry->key == key)
		{
			return (entry->value);
		}
		entry = entry->next;
	}
	return (-1);
}
