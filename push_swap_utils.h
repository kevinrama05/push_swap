/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:24:25 by vgramozi          #+#    #+#             */
/*   Updated: 2025/12/21 10:04:03 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "push_swap_structs.h"

/* Memory & Init */
t_ps_counts	*ft_init_counts(void);
t_stack		*ft_init_stack(char name);
t_ps_data	*ft_init_data(void);
void		ft_free_stack(t_stack *stack);
void		ft_clean_exit(t_ps_data *data, int success_code);
void		ft_free_array_and_exit(t_ps_data *data, char *arr);

/* Node Ops */
t_node		*ft_new_node(int value);
void		ft_add_node_front(t_stack *stack, t_node *new);
t_node		*ft_del_node_front(t_stack *stack);
void		ft_add_node_back(t_stack *stack, t_node *new);
t_node		*ft_del_node_back(t_stack *stack);

/* Parsing & Logic */
char		**ft_parse_arguments(t_ps_data *data, int argc, char **argv);
int			ft_is_strategy_selector(const char *arg);
void		ft_set_strategy(t_ps_data *data, const char *arg);
int			ft_get_num_count(char **num_args);
void		ft_assign_strategy_details(t_ps_data *data, const char *arg);
int			ft_is_arg_number(const char *arg);
char		**ft_collect_numbers(int argc, char **argv, t_ps_data *data);
void		ft_index_stack(t_stack *a);
char		**ft_split(char const *s, char c);
void		ft_parse_flags(t_ps_data *data, char **argv);

/* Lib Helpers */
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_is_digit(char c);
long		ft_atol(const char *str);
long		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);

/* Benchmark & Sort */
void		ft_print_benchmark(t_ps_data *data);
void		ft_solve(t_ps_data *data);
void		ft_sort_simple(t_ps_data *data);
float		ft_calculate_disorder(t_stack *a);
int			ft_is_sorted(t_stack *a);
void		ft_tiny_sort(t_ps_data *data);
void		ft_sort_radix(t_ps_data *data);
void		ft_sort_chunk(t_ps_data *data);
void		pb_rb(t_ps_data *data);

/* Smart Rotate Ops*/
void		ft_smart_rotate_a(t_ps_data *data, int min, int max);
void		ft_smart_rotate_b(t_ps_data *data, int min, int max);

#endif
