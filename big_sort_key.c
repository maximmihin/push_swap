#include "push_swap.h"

t_element_to_move	choose_next_elem_to_b(t_list *stack_b,
										   unsigned int stack_size,
										   t_list **desired_pool)
{
	t_element_to_move	next_elem;
	t_list				*bottom_desired_pool;
	t_list				*top_desired_pool;

	calculate_all_costs(desired_pool, stack_b, stack_size);
	bottom_desired_pool = *desired_pool;
	top_desired_pool = bottom_desired_pool->next;
	if (((t_pool_node *)bottom_desired_pool->content)->cost
		<= ((t_pool_node *)top_desired_pool->content)->cost)
	{
		next_elem.index = ((t_pool_node *)bottom_desired_pool->content)->index;
		next_elem.gate = ((t_pool_node *)bottom_desired_pool->content)->gate;
		next_elem.cost = ((t_pool_node *)bottom_desired_pool->content)->cost;
		((t_pool_node *)bottom_desired_pool->content)->index++;
	}
	else
	{
		next_elem.index = ((t_pool_node *)top_desired_pool->content)->index;
		next_elem.gate = ((t_pool_node *)top_desired_pool->content)->gate;
		next_elem.cost = ((t_pool_node *)top_desired_pool->content)->cost;
		((t_pool_node *)top_desired_pool->content)->index--;
	}
	return (next_elem);
}

void				recost_desired_pool(t_list **desired_pool, t_list *stack_a,
										unsigned int stack_size)
{
	t_list				*pool_node_to_recost;
	unsigned int		next_elem_index;

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

void				move_to_b(t_list **A, t_list **B, t_element_to_move next_elem)
{


	if (next_elem.gate == 'T')
		while (next_elem.cost)
		{
			ra(A);
			next_elem.cost--;
		}
	else if (next_elem.gate == 'B')
		while (next_elem.cost)
		{
			rra(A);
			next_elem.cost--;
		}
	pb(A, B);


	/// test

	t_list *tmp_b;
	tmp_b = *B;

	((ps_node *)tmp_b->content)->min_max = next_elem.min_max;

	if (next_elem.min_max == 'B' && tmp_b->next)
		rb(B);

	/// test sb - ухудшает
/*
		tmp_b = *B;
		if ( tmp_b->next
			&& (((ps_node *)tmp_b->content)->index
		        < ((ps_node *)tmp_b->next->content)->index))
			sb(B);
*/
}
