
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
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
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
int main(void)
{
	printf("%d\n", ft_atoi("-23 "));
	printf("%d\n", is_num("-23"));
	return 0;
}
