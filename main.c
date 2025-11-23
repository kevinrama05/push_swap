#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
void print_list(t_dcll *head)
{
    if (!head)
        return;
    t_dcll *temp = head;
    do
    {
        printf("[%d|%d]  <-->  ", temp->data, temp->index);
        temp = temp->next;
    } while (temp != head);
    printf("[END OF CYCLE]\n");
}

void	print_stacks_main(t_dcll *a, t_dcll *b)
{
	t_dcll	*head_a = a;
	t_dcll	*head_b = b;

	if (!a && !b)
		return ;

	printf("   a   |   b\n");
	printf("---------------\n");

	while (a || b)
	{
		if (a)
		{
			printf("%5d", a->data); // right-aligned in width 5
			a = (a->next != head_a) ? a->next : NULL;
		}
		else
			printf("     "); // 5 spaces for empty slot

		printf(" | ");

		if (b)
		{
			printf("%5d", b->data);
			b = (b->next != head_b) ? b->next : NULL;
		}
		else
			printf("     ");

		printf("\n");
	}
	printf("---------------\n");
}


/* int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_putstr_fd("Error\n", 1);
        return (0);
    }
    size_t size = argc - 1;
    t_dcll *stack_a = create_stack_a(argv);
    if (stack_a == 0)
    {
    	ft_putstr_fd("Error\n", 1);
	return 0;
    }
//    float disorder_value = disorder(&stack_a);
    t_dcll *copy_a = copy_list(stack_a);
    copy_a = sort_doubly_circular(copy_a);
    if (check_if_no_dup(copy_a) == 0)
    {
    	ft_putstr_fd("Error\n", 1);
	return 0;
    }
    ht_t *hashtable = ht_create(size);
    size_t i = 0;
    while (i < size)
    {
        ht_set(hashtable, copy_a->data, i, size);
        copy_a = copy_a->next;
        i++;
    }
    t_dcll *temp = stack_a;
    while (1)
    {
        temp->index = ht_get(hashtable, temp->data, size);
        temp = temp->next;
        if (temp == stack_a)
            break;
    }
    t_dcll *stack_b = NULL;
//    printf("Disorder: %.2f%%\n\n", disorder_value * 100);
//    print_list(stack_a);
    radix_sort(&stack_a, &stack_b, (int)size);
    free_dcll(stack_a);
    free_dcll(copy_a);
    free_ht(hashtable);
    return 0;
} */

void    ht_set_hashtable(ht_t **hashtable, t_dcll *a, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ht_set(*hashtable, a->data, (size_t)i, (size_t)size);
        a = a->next;
        i++;
    }
}

void    ht_fix_stack_a(ht_t *hashtable, t_dcll **a, int size)
{
    t_dcll  *t;

    t = *a;
    while (1)
    {
        t->index = ht_get(hashtable, t->data, (size_t)size);
        t = t->next;
        if (t == *a)
            break;
    }
}

void    sort_stack(int argc, char **argv, t_flags flags)
{
    t_dcll  *stack_a;
    t_dcll  *stack_b;
    t_dcll  *copy_a;
    ht_t    *hashtable;
    int     args_count;

    args_count = count_args(flags);
    stack_a = create_stack_a(argv + args_count);
    copy_a = sort_doubly_circular(stack_a);
    if (check_if_no_dup(copy_a) == 0)
        exit_program();
    hashtable = ht_create(argc - args_count);
    ht_set_hashtable(&hashtable, copy_a, argc - args_count);
    ht_fix_stack_a(hashtable, &stack_a, argc - args_count);
    if (flags.bench == 1)
        bench_handle(&stack_a, &stack_b, argc - args_count, flags);
    if (flags.adaptive == 1)
        adaptive_sort(&stack_a, &stack_b, argc - args_count, flags);
    else if (flags.simple == 1)
        min_max_extraction(&stack_a, &stack_b, flags);
    else if (flags.medium == 1)
        chunk_based_sort(&stack_a, &stack_b, argc - args_count, flags);
    else if (flags.complex == 1)
        radix_sort(&stack_a, &stack_b, argc - args_count, flags);
}

int	main(int argc, char **argv)
{
	t_flags	a;

    if (argc == 1)
        exit_program();
    init_flags(&a);
    check_flags(argv[1], &a);
    check_flags(argv[2], &a);
    if (check_sort_args(a) > 1)
        exit_program();
    if (a.bench > 1)
	exit_program();
    if (!a.adaptive && !a.complex && !a.medium && !a.simple)
        a.adaptive++;
    sort_stack(argc - 1, argv + 1, a);
    return (0);
}
