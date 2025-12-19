#include "push_swap.h"

static void	init_chunk(t_chunk *chunk, int size)
{
	int	i;

	i = 0;
	while (i * i <= size)
		i++;
	if (i - 1 <= 5)
		chunk->chunk_size = 5;
	else
		chunk->chunk_size = i - 1;
	chunk->first_chunk = 1;
	chunk->max = size - 1;
	chunk->min = chunk->max - chunk->chunk_size + 1;
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
		else if (data->b->size >= 2)
		{			
			if (data->a->head->index < data->b->head->index
					&& data->a->head->index > data->b->head->next->index)
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
		else
		{
			pb(data);
			rb(data);
		}
		i++;
	}
}

static void ft_push_chunk_a(t_ps_data *data)
{
	ft_smart_rotate_a(data, data->b->head->index + 1, data->b->head->index + 1);
	while (data->b->size )
	{
		if (data->b->head->index == data->a->head->index - 1)
			pa(data);
		else
		{
			ft_smart_rotate_b(data, data->a->head->index - 1, data->a->head->index - 1);
		}
	}
}

static void	ft_new_chunk(t_chunk *chunk)
{
	chunk->first_chunk = 0;
	chunk->max = chunk->max - chunk->chunk_size;
	if (chunk->max < 0)
		chunk->max = 0;
	chunk->min = chunk->min - chunk->chunk_size;
	if (chunk->min < 0)
		chunk->min = 0;
	if (chunk->max - chunk->min + 1 != chunk->chunk_size)
		chunk->chunk_size = chunk->max - chunk->min + 1;
}

void	ft_sort_chunk(t_ps_data *data)
{
	t_chunk	chunk;

	data->strategy_name = "Medium";
	data->complexity_class = "O(n√n)";
	if (ft_is_sorted(data->a))
		return ;
	init_chunk(&chunk, data->a->size);
	while (1)
	{
		ft_push_chunk_b(data, &chunk);
		if (chunk.first_chunk == 1)
			pa(data);
		ft_push_chunk_a(data);
		ft_new_chunk(&chunk);
		if (chunk.min == 0 && chunk.max == 0)
		{
			if (data->a->tail->index == 0)
				rra(data);
			break ; 
		}
	}
}