#include "push_swap.h"

void push_b_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	add_front(stack_b, (*stack_a)->data, (*stack_a)->index);
	remove_front(stack_a);
	ft_putstr_fd("pb\n", 1);
	count_ops("pb", o);
}

void push_a_bench(t_dcll **stack_b, t_dcll **stack_a, t_ops *o)
{
	add_front(stack_a, (*stack_b)->data, (*stack_b)->index);
	remove_front(stack_b);
	count_ops("pa", o);
}

void rotate_a_bench(t_dcll **stack_a, t_ops *o)
{
	*stack_a = (*stack_a)->next;
	ft_putstr_fd("ra\n", 1);
	count_ops("ra", o);
}

void rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rb\n", 1);
	count_ops("rb", o);
}

void rev_rotate_a_bench(t_dcll **stack_a, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	ft_putstr_fd("rra\n", 1);
	count_ops("rra", o);
}

void rev_rotate_b_bench(t_dcll **stack_b, t_ops *o)
{
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrb\n", 1);
	count_ops("rb", o);
}

void rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_putstr_fd("rr\n", 1);
	count_ops("rr", o);
}

void rev_rotate_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_putstr_fd("rrr\n", 1);
	count_ops("rrr", o);
}

void swap_a_bench(t_dcll **stack_a, t_ops *o)
{
	int temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	temp = (*stack_a)->index;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->index = temp;
	ft_putstr_fd("sa\n", 1);
	count_ops("sa", o);
}

void swap_b_bench(t_dcll **stack_b, t_ops *o)
{
	int temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
	temp = (*stack_b)->index;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->index = temp;
	ft_putstr_fd("sb\n", 1);
	count_ops("sb", o);
}

void swap_ab_bench(t_dcll **stack_a, t_dcll **stack_b, t_ops *o)
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
	count_ops("ss", o);
}

void bench_handle(t_dcll *a, t_dcll *b, int size)
{
	
}
