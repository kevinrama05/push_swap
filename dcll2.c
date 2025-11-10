#include "push_swap.h"

int check_if_no_dup(t_dcll *head)
{
	t_dcll *temp = head;
	while (1)
	{
		if (temp->data == temp->next->data)
			return 0;
		temp = temp->next;
		if (temp == head)
			break;
	}
	return 1;
}
