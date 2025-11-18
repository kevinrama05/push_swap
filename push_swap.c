#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"

int	check_sort_args(t_flags flags)
{
	int	i;

	i = 0;
	i = i + flags.adaptive;
	i = i + flags.simple;
	i = i + flags.complex;
	i = i + flags.medium;
	return (i);
}

void	exit_program(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	count_args(t_flags a)
{
	int	i;

	i = a.adaptive + a.bench + a.complex + a.medium + a.simple;
	return (i); 
}