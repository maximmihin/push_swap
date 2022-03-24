#include "../includes/push_swap.h"

t_list	*find_max_top_node(t_list **desired_pool)
{
	t_list			*tmp_desired_pool;
	t_list			*max_top_node;
	t_pool_node		*max_pool_node;
	unsigned int	max_val;

	tmp_desired_pool = *desired_pool;
	max_top_node = tmp_desired_pool;
	max_pool_node = (t_pool_node *)max_top_node->content;
	max_val = max_pool_node->index;
	while (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'T'
		|| ((t_pool_node *)tmp_desired_pool->content)->bottom_top == 't')
	{
		if (((t_pool_node *)tmp_desired_pool->content)->index > max_val
			&& ((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'T')
		{
			max_top_node = tmp_desired_pool;
			max_pool_node = (t_pool_node *)max_top_node->content;
			max_val = max_pool_node->index;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (max_top_node);
}

t_list	*find_min_bottom_node(t_list **desired_pool)
{
	t_list			*tmp_desired_pool;
	t_list			*min_bottom_node;
	t_pool_node		*min_pool_node;
	unsigned int	max_val;

	tmp_desired_pool = *desired_pool;
	while (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'T'
		|| ((t_pool_node *)tmp_desired_pool->content)->bottom_top == 't')
		tmp_desired_pool = tmp_desired_pool->next;
	min_bottom_node = tmp_desired_pool;
	min_pool_node = (t_pool_node *)min_bottom_node->content;
	max_val = min_pool_node->index;
	while (tmp_desired_pool)
	{
		if (((t_pool_node *)tmp_desired_pool->content)->index < max_val
			&& ((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'B')
		{
			min_bottom_node = tmp_desired_pool;
			min_pool_node = (t_pool_node *)min_bottom_node->content;
			max_val = min_pool_node->index;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (min_bottom_node);
}

void	hide_pool_top_max(t_list **desired_pool)
{
	t_list	*max_top;

	max_top = find_max_top_node(desired_pool);
	((t_pool_node *)max_top->content)->bottom_top = 't';
}

void	hide_pool_bottom_min(t_list **desired_pool)
{
	t_list			*min_bottom;

	min_bottom = find_min_bottom_node(desired_pool);
	((t_pool_node *)min_bottom->content)->bottom_top = 'b';
}

int	resize_desired_pool(t_list **desired_pool,
							unsigned int num_pool_nodes)
{
	hide_pool_top_max(desired_pool);
	hide_pool_bottom_min(desired_pool);
	num_pool_nodes -= 2;
	return (num_pool_nodes);
}
