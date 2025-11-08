/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/08 13:24:09 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct  s_dcll
{
    int             data;
    int             index;
    struct s_dcll   *prev;
    struct s_dcll   *next;
}   t_dcll;
t_dcll          *create_node(int data);
void            add_back(t_dcll **head, int data, int index);
void            add_front(t_dcll **head, int data);
void	        rotate(t_dcll **head, int rotate);
void	        remove_front(t_dcll **head);
int	            ft_atoi(const char *nptr);
int	            is_num(const char *nptr);
void            free_dcll(t_dcll *head);
t_dcll          *sort_doubly_circular(t_dcll *head);

#endif