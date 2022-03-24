#include "push_swap.h"

unsigned int	find_pos(t_list *stack, unsigned int index)
{
	unsigned int	pos;
	ps_node			*tmp_node;

	pos = 1;
	while (stack)
	{
		tmp_node = ((ps_node *)stack->content);
		if (tmp_node->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

char	find_gate(unsigned int stack_size, unsigned int pos)
{
	unsigned int	med_stack;

	med_stack = stack_size / 2;
	if (stack_size % 2)
		med_stack++;
	if (pos <= med_stack)
		return ('T');
	else
		return ('B');
}

unsigned int	find_cost(size_t stack_size, char gate, unsigned int pos)
{
	if (gate == 'T')
		return (pos - 1);
	else
		return (stack_size - pos + 1);
}

unsigned int	find_cost_node(t_list **desired_pool, t_list *stack,
								size_t stack_size)
{
	t_list		*tmp_desired_pool;
	t_pool_node	*tmp_pool_node;

	tmp_desired_pool = *desired_pool;
	tmp_pool_node = (t_pool_node *)tmp_desired_pool->content;
	tmp_pool_node->pos = find_pos(stack, tmp_pool_node->index);
	tmp_pool_node->gate = find_gate(stack_size, tmp_pool_node->pos);
	return (find_cost(stack_size, tmp_pool_node->gate, tmp_pool_node->pos));
}

void	calculate_all_costs(t_list **desired_pool, t_list *stack,
										unsigned int stack_size)
{
	t_list		*tmp_desired_pool;
	t_pool_node	*tmp_pool_node;

	tmp_desired_pool = *desired_pool;
	while (tmp_desired_pool)
	{
		tmp_pool_node = (t_pool_node *)tmp_desired_pool->content;
		tmp_pool_node->cost = find_cost_node(&tmp_desired_pool, stack,
				stack_size);
		tmp_desired_pool = tmp_desired_pool->next;
	}
}
