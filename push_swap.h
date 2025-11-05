/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/04 12:53:44 by kerama           ###   ########.fr       */
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
void            add_back(t_dcll **head, int data);
void            add_front(t_dcll **head, int data);
void	        rotate(t_dcll **head, int rotate);
void	        remove_front(t_dcll **head);
unsigned long   seed(void);
unsigned long   my_rand_range(unsigned long *seed, int min, int max);

#endif