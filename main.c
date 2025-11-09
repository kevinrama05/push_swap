
#include "push_swap.h"
#include <stdio.h>
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
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Usage: ./t <arg1> <arg2>");
        return (0);
    }
    t_dcll *stack_a;
    stack_a = create_stack_a(argv);
    printf("Parsed arguments with ascending ranks\n");
    print_list(stack_a);
    printf("\n");
    t_dcll *sorted_stack_a = sort_doubly_circular(stack_a);
    printf("Sorted arguments, and scrambled indexes(The original list, but represented by indexes)\n");
    print_list(sorted_stack_a);
    return (0);
}
