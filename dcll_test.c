#include <stdio.h>
#include "push_swap.h"

void print_list(t_dcll *head)
{
    t_dcll *temp;

    if (!head)
    {
        printf("(empty list)\n");
        return;
    }

    temp = head;
    printf("List: ");
    do {
        printf("[%d] ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main(void)
{
    t_dcll *head = NULL;

    printf("Adding 10, 20, 30 to the back:\n");
    add_back(&head, 10);
    add_back(&head, 20);
    add_back(&head, 30);
    print_list(head);

    printf("Adding 5 to the front:\n");
    add_front(&head, 5);
    print_list(head);

    printf("Rotating forward (r):\n");
    rotate(&head, 1);
    print_list(head);

    printf("Rotating backward (rr):\n");
    rotate(&head, -1);
    print_list(head);

    printf("Removing front node:\n");
    remove_front(&head);
    print_list(head);

    printf("Removing all nodes:\n");
    remove_front(&head);
    remove_front(&head);
    remove_front(&head);
    remove_front(&head);
    print_list(head);

    return (0);
}
