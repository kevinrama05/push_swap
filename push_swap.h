/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/09 12:28:53 by kerama           ###   ########.fr       */
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
t_dcll          *create_node(int data, int index);
void            add_back(t_dcll **head, int data, int index);
void            add_front(t_dcll **head, int data);
void	        rotate(t_dcll **head, int rotate);
void	        remove_front(t_dcll **head);
int	            ft_atoi(const char *nptr);
int	            is_num(const char *nptr);
void            free_dcll(t_dcll *head);
t_dcll          *sort_doubly_circular(t_dcll *head);
t_dcll          *create_stack_a(char **args);

#endif