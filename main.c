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

// Main test for sorting the DCLL
/*
int main(void)
{
    t_dcll *head = NULL;

    add_back(&head, 65);
    add_back(&head, 85);
    add_back(&head, 79);
    add_back(&head, 10);
    add_back(&head, 89);

    printf("Original list:\n");
    print_list(head);

    head = sort_doubly_circular(head);

    printf("Sorted list:\n");
    print_list(head);

    return 0;
}
*/

// Main test to 
/* int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Error\n");
        return 0;
    }
    size_t size = argc - 1;
    t_dcll *stack_a = create_stack_a(argv);
    t_dcll *copy_a = copy_list(stack_a);
    if (stack_a == NULL)
    {
        printf("Error\n");
        return 0;
    }
    t_dcll *sorted_stack_a = sort_doubly_circular(copy_a);
    if (check_if_no_dup(sorted_stack_a) == 0)
    {
        printf("Error\n");
        return 0;
    }
    ht_t *hashtable = ht_create(size);
    unsigned int i = 0;
    print_list(sorted_stack_a);
    print_list(stack_a);
    while (i < size)
    {
        ht_set(hashtable, sorted_stack_a->data, i, size);
        i++;
        sorted_stack_a = sorted_stack_a->next;
    }
    t_dcll *temp = stack_a;
    while (1)
    {
        temp->index = ht_get(hashtable, temp->data, size);
        printf("%d\n", temp->index);
        temp = temp->next;
        if (temp == stack_a)
            break;
    }
    print_list(stack_a);
    ht_dump(hashtable, argc - 1);
    free_dcll(stack_a);
    free_ht(hashtable);
    return 0;
}
 */

int main(int argc, char **argv)
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
    float disorder_value = disorder(&stack_a);
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
    printf("Disorder: %.2f%%\n\n", disorder_value * 100);
    print_list(stack_a);
    min_max_extraction(stack_a, stack_b);
    free_dcll(stack_a);
    free_dcll(copy_a);
    free_ht(hashtable);
    return 0;
}
