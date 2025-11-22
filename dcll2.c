#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"
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

t_dcll	*copy_list(t_dcll *head)
{
	t_dcll	*copy;
	t_dcll	*temp;
	t_dcll	*new_node;
	t_dcll	*last;

	if (!head)
		return (NULL);
	copy = NULL;
	temp = head;
	last = NULL;
	while (1)
	{
		new_node = create_node(temp->data, temp->index);
		if (!new_node)
			return (NULL);
		if (!copy)
		{
			copy = new_node;
			last = copy;
		}
		else
		{
			last->next = new_node;
			new_node->prev = last;
			last = new_node;
		}
		temp = temp->next;
		if (temp == head)
			break;
	}
	last->next = copy;
	copy->prev = last;
	return (copy);
}

void push_b(t_dcll **stack_a, t_dcll **stack_b)
{
	add_front(stack_b, (*stack_a)->data, (*stack_a)->index);
	remove_front(stack_a);
	ft_putstr_fd("pb\n", 1);
}

void push_a(t_dcll **stack_b, t_dcll **stack_a)
{
	add_front(stack_a, (*stack_b)->data, (*stack_b)->index);
	remove_front(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->next;
	ft_putstr_fd("ra\n", 1);
}

void rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
}

void rev_rotate_a(t_dcll **stack_a)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
}

void rev_rotate_b(t_dcll **stack_b)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
}

void rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
}

void rev_rotate_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
}

void swap_a(t_dcll **stack_a)
{
	int temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
}

void swap_b(t_dcll **stack_b)
{
	int temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
}

void swap_ab(t_dcll **stack_a, t_dcll **stack_b)
{
	int temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;

	temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("ss\n", 1);
}

float disorder(t_dcll **stack_a)
{
    int mistakes = 0;
    int total_pairs = 0;
    t_dcll *temp1;
    t_dcll *temp2;
    t_dcll *head;

    if (!stack_a || !*stack_a)
        return (0.0f);
    head = *stack_a;
    temp1 = head;
    while (temp1->next != head)
    {
        temp2 = temp1->next;
        while (temp2 != head)
        {
            total_pairs++;
            if (temp1->data > temp2->data)
                mistakes++;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ((float)mistakes / (float)total_pairs);
}

int check_if_sorted_asc(t_dcll *stack)
{
	t_dcll *temp = stack;
	while (1)
	{
		if (temp->data > temp->next->data && temp->next != stack)
			return 0;
		temp = temp->next;
		if (temp == stack)
			break;
	}
	return 1;
}

int check_if_sorted_dec(t_dcll *stack)
{
	t_dcll *temp = stack;
	while (1)
	{
		if (temp->data < temp->next->data && temp->next != stack)
			return 0;
		temp = temp->next;
		if (temp == stack)
			break;
	}
	return 1;
}
