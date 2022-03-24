#include "push_swap.h"

t_element_to_move	get_next_elem(t_list *chosen_desired_pool_node)
{
	t_element_to_move	next_elem;
	t_pool_node			*pool_node;

	pool_node = chosen_desired_pool_node->content;
	next_elem.index = pool_node->index;
	next_elem.gate = pool_node->gate;
	next_elem.cost = pool_node->cost;
	next_elem.min_max = pool_node->bottom_top;
	return (next_elem);
}

t_element_to_move	choose_next_elem_first_step(t_list **desired_pool)
{
	t_element_to_move	next_elem;
	t_list				*tmp_desired_pool;
	t_list				*chosen_desired_pool_node;
	unsigned int		min_cost;

	tmp_desired_pool = *desired_pool;
	while (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 't')
		tmp_desired_pool = tmp_desired_pool->next;
	min_cost = ((t_pool_node *)tmp_desired_pool->content)->cost;
	chosen_desired_pool_node = tmp_desired_pool;
	while (tmp_desired_pool)
	{
		if (((t_pool_node *)tmp_desired_pool->content)->cost < min_cost
			&& (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'T'
				|| ((t_pool_node *)tmp_desired_pool->content)->bottom_top
				== 'B'))
		{
			min_cost = ((t_pool_node *) tmp_desired_pool->content)->cost;
			chosen_desired_pool_node = tmp_desired_pool;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	next_elem = get_next_elem(chosen_desired_pool_node);
	((t_pool_node *)chosen_desired_pool_node->content)->gate = 'R';
	return (next_elem);
}

void	recost_desired_pool(t_list **desired_pool, t_list *stack_a,
							unsigned int stack_size)
{
	t_list			*pool_node_to_recost;
	unsigned int	next_elem_index;

	pool_node_to_recost = find_used_pool_node(desired_pool);
	if (((t_pool_node *)pool_node_to_recost->content)->bottom_top == 'T'
		|| ((t_pool_node *)pool_node_to_recost->content)->bottom_top == 't')
		next_elem_index = find_next_top(*desired_pool);
	else
		next_elem_index = find_next_bottom(*desired_pool);
	if (!del_waste_pool_node(desired_pool, next_elem_index))
	{
		if (((t_pool_node *) pool_node_to_recost->content)->bottom_top == 'T')
			next_elem_index++;
		else
			next_elem_index--;
	}
	((t_pool_node *)pool_node_to_recost->content)->index = next_elem_index;
	calculate_all_costs(desired_pool, stack_a, stack_size);
}

void	move_to_b(t_list **st_a, t_list **st_b, t_element_to_move next_elem)
{
	t_list	*tmp_b;

	if (next_elem.gate == 'T')
	{
		while (next_elem.cost)
		{
			ra(st_a, 1);
			next_elem.cost--;
		}
	}
	else if (next_elem.gate == 'B')
	{
		while (next_elem.cost)
		{
			rra(st_a, 1);
			next_elem.cost--;
		}
	}
	pb(st_a, st_b, 1);
	tmp_b = *st_b;
	((ps_node *)tmp_b->content)->min_max = next_elem.min_max;
	if (next_elem.min_max == 'B' && tmp_b->next)
		rb(st_b, 1);
}
