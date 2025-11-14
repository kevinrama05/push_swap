#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int pow(int n, int k)
{
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	int i = 0;
	int num = 1;
	while (i < k)
	{
		num = num * n;
		i++;
	}
	return num;
}

int num_of_zeros(int n, int k)
{
	int first_part = ((n + 1)/pow(2, k + 1) * pow(2, k);
}
