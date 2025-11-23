#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_stacks(t_dcll *a, t_dcll *b)
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

void min_max_extraction(t_dcll **stack_a, t_dcll **stack_b)
{
	int i = 0;
	if (check_if_sorted_asc(*stack_a) == 1)
		return ;
	t_dcll *tmp_a = *stack_a;
        t_dcll *tmp_b = *stack_b;	
	while (1)
	{
		if (tmp_a->index != i)
			rotate_a(&tmp_a);
		else
		{
			push_b(&tmp_a, &tmp_b);
			i++;
		}
		if (tmp_a == NULL)
			break;
	}
	while (tmp_b != NULL)
	{	
		push_a(&tmp_b, &tmp_a);
	}	
}
