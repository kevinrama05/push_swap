/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/10 11:38:50 by ekrama10         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>

typedef struct  s_dcll
{
    int             data;
    int             index;
    struct s_dcll   *prev;
    struct s_dcll   *next;
}   t_dcll;
t_dcll          *create_node(int data, int index);
void            add_back(t_dcll **head, int data, int index);
void            add_front(t_dcll **head, int data, int index);
void	        rotate(t_dcll **head, int rotate);
void	        remove_front(t_dcll **head);
int	            ft_atoi(const char *nptr);
int	            is_num(const char *nptr);
void            free_dcll(t_dcll *head);
t_dcll          *sort_doubly_circular(t_dcll *head);
t_dcll          *create_stack_a(char **args);
int		check_if_no_dup(t_dcll *head);
typedef struct entry_t {
    unsigned int key;
    unsigned int value;
    struct entry_t *next;
} entry_t;
typedef struct {
    size_t size;
    entry_t **entries;
} ht_t;
unsigned int hash(int key, int size);
entry_t *ht_pair(unsigned int key, unsigned int value);
ht_t *ht_create(int size);
void ht_set(ht_t *hashtable, unsigned int key, unsigned int value, size_t size);
unsigned int ht_get(ht_t *hashtable, unsigned int key, size_t size);
void free_ht(ht_t *table);
int check_if_no_dup(t_dcll *head);
void ht_dump(ht_t *hashtable, size_t size);
t_dcll *copy_list(t_dcll *head);

#endif