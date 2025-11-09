/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dcll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:37:48 by kerama            #+#    #+#             */
/*   Updated: 2025/11/09 12:03:43 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void free_dcll(t_dcll *head)
{
    t_dcll *curr;
    t_dcll *tmp;
    
    curr = head->next;
    if (!head)
        return;
    while (curr != head)
    {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(head);
}
