#ifndef PUSH_SWAP_HEADER
#define PUSH_SWAP_HEADER
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
typedef struct  s_dcll
{
    int             data;
    int             index;
    struct s_dcll   *prev;
    struct s_dcll   *next;
}   t_dcll;
typedef struct entry_t {
    unsigned int key;
    unsigned int value;
    struct entry_t *next;
} entry_t;
typedef struct {
    size_t size;
    entry_t **entries;
} ht_t;
typedef struct s_flags
{
    int simple;
    int medium;
    int complex;
    int adaptive;
    int bench;
    int args;
}   t_flags;
typedef struct s_ops
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
} t_ops;
void push_b_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o);
void push_a_bench(t_dcll **stack_b, t_dcll **stack_a, t_ops *o);
void rotate_a_bench(t_dcll **stack_a, t_ops *o);
void rotate_b_bench(t_dcll **stack_b, t_ops *o);
void rev_rotate_a_bench(t_dcll **stack_a, t_ops *o);
void rev_rotate_b_bench(t_dcll **stack_b, t_ops *o);
void rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o);
void rev_rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o);
void swap_a_bench(t_dcll **stack_a, t_ops *o);
void swap_b_bench(t_dcll **stack_b, t_ops *o);
void swap_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o);
int list_size(t_dcll *stack);
void push_chunk(t_dcll **stack_a, t_dcll **stack_b, int min, int max);
void new_chunk(int *min, int *max, int chunk);
void chunk_based_sort(t_dcll **stack_a, t_dcll **stack_b, int size);
int list_size(t_dcll *stack);
void push_chunk_bench(t_dcll **stack_a, t_dcll **stack_b, int min, int max, t_ops *o);
void new_chunk(int *min, int *max, int chunk);
void chunk_based_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o);
t_dcll  *create_node(int data, int index);
void    add_back(t_dcll **head, int data, int index);
void    add_front(t_dcll **head, int data, int index);
void	remove_front(t_dcll **head);
int check_if_no_dup(t_dcll *head);
t_dcll	*copy_list(t_dcll *head);
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
int check_if_sorted_asc(t_dcll *stack);
int check_if_sorted_dec(t_dcll *stack);
void print_list(t_dcll *head);
void free_dcll(t_dcll *head);
unsigned int hash(int key, size_t size);
entry_t *ht_pair(unsigned int key, unsigned int value);
ht_t *ht_create(size_t size);
void ht_set(ht_t *hashtable, unsigned int key, unsigned int value, size_t size);
unsigned int ht_get(ht_t *hashtable, unsigned int key, size_t size);
void ht_dump(ht_t *hashtable, size_t size);
void free_ht(ht_t *table);
void    ht_set_hashtable(ht_t **hashtable, t_dcll *a, int size);
void    ht_fix_stack_a(ht_t *hashtable, t_dcll **a, int size);
void    sort_stack(int argc, char **argv, t_flags flags);
t_dcll *split_list(t_dcll *head);
t_dcll *sort_doubly_circular(t_dcll *head);
void min_max_extraction(t_dcll **stack_a, t_dcll **stack_b);
void min_max_extraction_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o);
t_dcll	*create_stack_a(char **args);
int	check_sort_args(t_flags flags);
void	exit_program(void);
int	count_args(t_flags a);
void ft_putdouble(double x);
void adaptive_sort(t_dcll **stack_a, t_dcll **stack_b, int size);
int c(char *s1, char *s2);
int	is_num(char *nptr);
void number_of_ops(char p);
void init_flags(t_flags *f);
void	check_flags(char **flag, t_flags *args);
int	binary_digits(unsigned int n);
void push_zeros(t_dcll **stack_a, t_dcll **stack_b, int k, int n);
void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size);
void radix_sort(t_dcll **stack_a, t_dcll **stack_b, int size);
void radix_sort_bench(t_dcll **stack_a, t_dcll **stack_b, int size, t_ops *o);
void    handle_format(const char *ptr, int *i, int *total, va_list args);
int             ft_printf(const char *ptr, ...);
void    print_hex(int *count, unsigned long n);
void    print_bigx(int *count, unsigned long n);
void    ft_putptr(void *ptr, int *count);
void    ft_putchar(int *count, char c);
void    ft_putstr(int *count, char *s);
void    ft_putnum(int *count, int n);
void    ft_putu(int *count, unsigned int n);
#endif
