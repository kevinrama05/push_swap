/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrama10 <ekrama10@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:04 by kerama            #+#    #+#             */
/*   Updated: 2025/11/20 13:51:32 by ekrama10         ###   ########.fr       */
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
void min_max_extraction(t_dcll **stack_a, t_dcll **stack_b);
int check_if_sorted(t_dcll *stack);
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
void ht_dump(ht_t *hashtable, size_t size);
t_dcll *copy_list(t_dcll *head);
void push_b(t_dcll **stack_a, t_dcll **stack_b);
void push_a(t_dcll **stack_b, t_dcll **stack_a);
void rotate_a(t_dcll **stack_a);
void rotate_b(t_dcll **stack_b);
void rev_rotate_a(t_dcll **stack_a);
void rev_rotate_b(t_dcll **stack_b);
void rotate_ab(t_dcll **stack_a, t_dcll **stack_b);
void rev_rotate_ab(t_dcll **stack_a, t_dcll **stack_b);
void swap_a(t_dcll **stack_a);
void swap_b(t_dcll **stack_b);
void swap_ab(t_dcll **stack_a, t_dcll **stack_b);
float disorder(t_dcll **stack_a);
void min_max_extraction(t_dcll **stack_a, t_dcll **stack_b);
int check_if_sorted(t_dcll *stack);
int check_if_sorted_dec(t_dcll *stack);
int check_if_sorted_asc(t_dcll *stack);
void number_of_ops(char p);
void chunk_based_sort(t_dcll **stack_a, t_dcll **stack_b, int size); 
void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size);
int c(char *s1, char *s2);
typedef struct s_flags
{
    int simple;
    int medium;
    int complex;
    int adaptive;
    int bench;
}   t_flags;
void init_flags(t_flags *f);
int	check_sort_args(t_flags flags);
int list_size(t_dcll *a);
typedef struct s_opscount
{
    int sa;
    int sb;
    int ss;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int pb;
    int pa;
} t_opscount;
#endif
