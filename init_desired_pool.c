#include "push_swap.h"

t_pool_node	*pool_node_new(unsigned int index)
{
	t_pool_node	*pool_node;

	pool_node = (t_pool_node *) malloc(sizeof(t_pool_node));
	if (!pool_node)
		return (NULL);
	pool_node->index = index;
	return (pool_node);
}

t_list	*create_desired_pool(unsigned int num_pool_nodes)
{
	t_list			*desired_pool;
	t_list			*tmp_list;
	t_pool_node		*pool_node;

	pool_node = pool_node_new(1);
	if (!pool_node)
		return (NULL);
	desired_pool = ft_lstnew(pool_node);
	if (!desired_pool)
		return (NULL);
	num_pool_nodes--;
	while (num_pool_nodes)
	{
		pool_node = pool_node_new(0);
		if (!pool_node)
			return (NULL);
		tmp_list = ft_lstnew(pool_node);
		if (!tmp_list)
			return (NULL);
		ft_lstadd_back(&desired_pool, tmp_list);
		num_pool_nodes--;
	}
	return (desired_pool);
}

void	mark_desired_pool(t_list **desired_pool, unsigned int num_pool_nodes)
{
	t_list			*tmp_desired_pool;
	unsigned int	i;

	tmp_desired_pool = *desired_pool;
	num_pool_nodes /= 2;
	i = 1;
	while (i <= num_pool_nodes)
	{
		((t_pool_node *)tmp_desired_pool->content)->bottom_top = 'T';
		tmp_desired_pool = tmp_desired_pool->next;
		i++;
	}
	while (tmp_desired_pool)
	{
		((t_pool_node *)tmp_desired_pool->content)->bottom_top = 'B';
		tmp_desired_pool = tmp_desired_pool->next;
	}
}

void	index_desired_pool_for_a(t_list **desired_pool,
								unsigned int num_pool_nodes,
								unsigned int stack_size)
{
	t_list			*tmp_desired_pool;
	unsigned int	i;

	tmp_desired_pool = *desired_pool;
	i = 1;
	while (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'T')
	{
		((t_pool_node *)tmp_desired_pool->content)->index = i;
		i++;
		tmp_desired_pool = tmp_desired_pool->next;
	}
	i = stack_size - num_pool_nodes / 2 + 1;
	while (tmp_desired_pool)
	{
		((t_pool_node *)tmp_desired_pool->content)->index = i;
		i++;
		tmp_desired_pool = tmp_desired_pool->next;
	}
}

t_list	*init_desired_pool(unsigned int num_pool_nodes)
{
	t_list			*desired_pool;

	desired_pool = create_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (NULL);
	mark_desired_pool(&desired_pool, num_pool_nodes);
	return (desired_pool);
}
