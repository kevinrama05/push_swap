#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	if (i - 1 <= 5)
		return (5);
	return (i - 1);
}

static void	init_chunk(t_chunk *chunk, int size)
{
	chunk->chunk_size = ft_sqrt(size);
	chunk->first_chunk = 1;
	chunk->max = size - 1;
	chunk->min = max - chunk_size + 1;
	if (chunk->min < 0)
	{
		chunk->min = 0;
		chunk->chunk_size = chunk->max + 1;
	}
}

static void	ft_push_chunk_b(t_ps_data *data, t_chunk *chunk)
{
	int	i;

	i = 0;
	while (i < chunk->chunk_size)
	{
		ft_smart_rotate_a(data, chunk->min, chunk->max);
		if (data->b->size == 0)
			pb(data);
		else if (data->a->head->index > data->b->head->index)
			pb(data);
		else if (data->a->head->index < data->b->head->index
				&& data->a->head->index > data->b->head-next->index)
		{
			pb(data);
			sb(data);
		}
		else
		{
			pb(data);
			rb(data);
		}
	}
}

static void	ft_push_chunk_a(t_ps_data *data, t_chunk *chunk)
{
	
}

void	ft_sort_chunk(t_ps_data *data)
{
	t_chunk	chunk;

	init_chunk(&chunk, data->a->size);
	while (1)
	{
		ft_push_chunk_b(data, &chunk);
		ft_push_chunk_a(data, &chunk);
		ft_new_chunk(&chunk);
		if (chunk.min == 0 && chunk.max == 0)
		{
			if (data->a->tail->index == 0)
				rra(data);
			break ; 
		}
	}
}