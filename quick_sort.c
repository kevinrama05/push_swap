/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:50:37 by kerama            #+#    #+#             */
/*   Updated: 2025/11/05 11:42:46 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *array, int length)
{
    quicksort_recursion(array, 0, length - 1);
}

void	quicksort_recursion(int *array, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index - 1, high);
	}
}

int	partition(int *array, int low, int high)
{
	int	pivot_value;

	pivot_value = array[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(array[i], array[j]);
			i++;
		}
	}
	swap(array[i], array[high]);
	return i;
}