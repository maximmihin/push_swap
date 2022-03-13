#include "push_swap.h"

unsigned int		find_next_top(t_list *desired_pool)
{
	unsigned int		max_in_top;

	max_in_top = ((t_pool_node *)desired_pool->content)->index;
	while (((t_pool_node *)desired_pool->content)->bottom_top == 'T'
		   || ((t_pool_node *)desired_pool->content)->bottom_top == 't')
	{
		if (((t_pool_node *)desired_pool->content)->bottom_top == 't')
		{
			max_in_top = ((t_pool_node *)desired_pool->content)->index;
			while (desired_pool)
			{
				if (((t_pool_node *)desired_pool->content)->index < max_in_top
					&& ((t_pool_node *)desired_pool->content)->bottom_top == 't')
					max_in_top = ((t_pool_node *)desired_pool->content)->index;
				desired_pool = desired_pool->next;
			}
			break;
		}
		if (((t_pool_node *)desired_pool->content)->index > max_in_top)
			max_in_top = ((t_pool_node *)desired_pool->content)->index;
		desired_pool = desired_pool->next;
	}
	return (max_in_top);
}

unsigned int		find_next_bottom(t_list *desired_pool)
{
	unsigned int		min_in_bottom;

	while (((t_pool_node *)desired_pool->content)->bottom_top == 'T'
		   || ((t_pool_node *)desired_pool->content)->bottom_top == 't')
		desired_pool = desired_pool->next;
	min_in_bottom = ((t_pool_node *)desired_pool->content)->index;
	while (desired_pool)
	{
		if (((t_pool_node *)desired_pool->content)->bottom_top == 'b')
		{
			min_in_bottom = ((t_pool_node *)desired_pool->content)->index;
			while (desired_pool)
			{
				if (((t_pool_node *)desired_pool->content)->index > min_in_bottom
					&& ((t_pool_node *)desired_pool->content)->bottom_top == 'b')
					min_in_bottom = ((t_pool_node *)desired_pool->content)->index;
				desired_pool = desired_pool->next;
			}
			break;
		}
		if (((t_pool_node *)desired_pool->content)->index < min_in_bottom)
			min_in_bottom = ((t_pool_node *)desired_pool->content)->index;
		desired_pool = desired_pool->next;
	}
	return (min_in_bottom);
}

void				del_pool_node(t_list **desired_pool, t_list **node_to_del)
{
	t_list	*tmp_desired_pool;
	t_list	*tmp_node_to_del;

	tmp_desired_pool = *desired_pool;
	tmp_node_to_del = *node_to_del;
	if (tmp_desired_pool == tmp_node_to_del)
	{
		*desired_pool = tmp_desired_pool->next;
	}
	else
	{
		while (tmp_desired_pool->next != tmp_node_to_del)
			tmp_desired_pool = tmp_desired_pool->next;
		tmp_desired_pool->next = tmp_desired_pool->next->next;
	}
	ft_lstdelone(tmp_node_to_del, free);
}

int					del_waste_pool_node(t_list **desired_pool,
										   unsigned int waste_index)
{
	t_list		*tmp_desired_pool;
	t_pool_node	*tmp_pool_node;

	tmp_desired_pool = *desired_pool;
	while (tmp_desired_pool)
	{
		tmp_pool_node = tmp_desired_pool->content;
		if (tmp_pool_node->index == waste_index
			&& (tmp_pool_node->bottom_top == 'b'
				|| tmp_pool_node->bottom_top == 't'))
		{
			del_pool_node(desired_pool, &tmp_desired_pool);
			return (1);
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (0);
}

t_list				*find_used_pool_node(t_list **desired_pool)
{
	t_list				*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;
	while (tmp_desired_pool)
	{
		if (((t_pool_node *)tmp_desired_pool->content)->gate == 'R')
			break;
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (tmp_desired_pool);
}
