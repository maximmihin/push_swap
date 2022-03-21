#include "push_swap.h"

t_element_to_move	choose_next_elem_second_step(t_list *stack_b,
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

void				index_desired_pool_for_b(t_list **desired_pool, t_list *stack_a)
{
	unsigned int	median;
	t_list			*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;
	median = ((ps_node *)stack_a->content)->index;
	((t_pool_node *)tmp_desired_pool->content)->index = median + 1;
	((t_pool_node *)tmp_desired_pool->next->content)->index = median - 1;
}

void				move_to_a(t_list **A, t_list **B, t_element_to_move next_elem)
{
	t_list	*tmp_a;

	if (next_elem.gate == 'T')
		while (next_elem.cost)
		{
			rb(B);
			next_elem.cost--;
		}
	else if (next_elem.gate == 'B')
		while (next_elem.cost)
		{
			rrb(B);
			next_elem.cost--;
		}
	pa(A, B);
	tmp_a = *A;
	if (((ps_node *)tmp_a->content)->index
		> ((ps_node *)tmp_a->next->content)->index)
		ra(A);
}


