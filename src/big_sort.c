#include "../includes/push_swap.h"

int	first_step(t_list **stack_a, t_list **stack_b, unsigned int stack_size)
{
	t_element_to_move	next_elem;
	t_list				*desired_pool;
	unsigned int		num_pool_nodes;

	num_pool_nodes = find_num_pool_nodes(stack_size);
	desired_pool = init_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_a(&desired_pool, num_pool_nodes, stack_size);
	calculate_all_costs(&desired_pool, *stack_a, stack_size);
	while (stack_size > 2)
	{
		next_elem = choose_next_elem_first_step(&desired_pool);
		move_to_b(stack_a, stack_b, next_elem);
		stack_size--;
		recost_desired_pool(&desired_pool, *stack_a, stack_size);
		if (is_resize_need(stack_size, num_pool_nodes))
			num_pool_nodes = resize_desired_pool(&desired_pool, num_pool_nodes);
	}
	pb(stack_a, stack_b, 1);
	ft_lstclear(&desired_pool, free);
	return (0);
}

int	second_step(t_list **stack_a, t_list **stack_b, unsigned int stack_size)
{
	t_element_to_move	next_elem;
	t_list				*desired_pool;

	stack_size--;
	desired_pool = init_desired_pool(2);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_b(&desired_pool, *stack_a);
	calculate_all_costs(&desired_pool, *stack_b, stack_size);
	while (*stack_b)
	{
		next_elem = choose_next_elem_second_step(*stack_b, stack_size,
				&desired_pool);
		move_to_a(stack_a, stack_b, next_elem);
		stack_size--;
	}
	ft_lstclear(&desired_pool, free);
	return (0);
}

int	big_sort(t_list **stack_a, t_list **stack_b)
{
	unsigned int		stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (first_step(stack_a, stack_b, stack_size))
		return (1);
	if (second_step(stack_a, stack_b, stack_size))
		return (1);
	ft_lstclear(stack_a, free);
	return (0);
}
