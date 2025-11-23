#include "push_swap.h"
#include "libft/libft.h"

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

void init_ops(t_ops *o)
{
	o->sa = 0;
	o->sb = 0;
	o->ss = 0;
	o->pa = 0;
	o->pb = 0;
	o->ra = 0;
	o->rb = 0;
	o->rr = 0;
	o->rra = 0;
	o->rrb = 0;
	o->rrr = 0;
}
void count_ops(char *ops, t_ops *o)
{
	if (c(ops, "sa") == 0)
		o->sa++;
	else if (c(ops, "sb") == 0)
		o->sb++;
	else if (c(ops, "ss") == 0)
		o->ss++;
	else if (c(ops, "pa") == 0)
		o->pa++;
	else if (c(ops, "pb") == 0)
		o->pb++;
	else if (c(ops, "ra") == 0)
		o->ra++;
	else if (c(ops, "rb") == 0)
		o->rb++;
	else if (c(ops, "rr") == 0)
		o->rr++;
	else if (c(ops, "rra") == 0)
		o->rra++;
	else if (c(ops, "rrb") == 0)
		o->rrb++;
	else if (c(ops, "rrr") == 0)
		o->rrr++;	
}

char *flag_str(t_flags flag)
{
	if (flag.adaptive)
		return ("Adaptive");
	else if (flag.simple)
		return ("Simple");
	else if (flag.medium)
		return ("Medium");
	else
		return ("Complex");
}

char *complexity(t_flags flag, double disorder)
{
	if (flag.complex)
		return ("O(n log n)");
	else if (flag.medium)
		return ("O(n√n)");
	else if (flag.simple)
		return ("O(n²)");
	else
	{
		if (disorder <= 0.2)
			return ("O(n²)");
		else if (disorder <= 0.5)
			return ("O(n√n)");
		else
			return ("O(n log n)");
	}
}

int total_ops(t_ops o)
{
	int	i;

	i = 0;
	i += o.sa;
	i += o.sb;
	i += o.ss;
	i += o.pa;
	i += o.pb;
	i += o.ra;
	i += o.rb;
	i += o.rr;
	i += o.rra;
	i += o.rrb;
	i += o.rrr;
	return (i);
}

void bench_handle(t_dcll *a, t_dcll *b, int size, t_flags flag)
{
	t_ops o;
	init_ops(&o);
	if (flag.adaptive)
		adaptive_sort_bench(&a, &b, size, &o);
	else if (flag.simple)
		min_max_extraction_bench(&a, &b, &o);
	else if (flag.medium)
		chunk_based_sort_bench(&a, &b, size, &o);
	else if (flag.complex)
		radix_sort_bench(&a, &b, size, &o);
	ft_printf("[bench] disorder: %f%%\n", disorder(&a));
	ft_printf("[bench] strategy: %s / %s\n", flag_str(flag), complexity(flag, disorder(&a)));
	ft_printf("[bench] total_ops: %i\n", total_ops(o));
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", o.sa, o.sb, o.ss, o.pa, o.pb);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n", o.ra, o.rb, o.rr, o.rra, o.rrb, o.rrr);
}
