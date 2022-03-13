#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>


// print info
/*
void				print_step(int steps)
{
	char *buffer;
	int buffer_len = 15;
	char *char_steps;
	size_t len_str;

	buffer = (char *) malloc(sizeof(char) * buffer_len);
	ft_strlcpy(buffer, "step ", buffer_len);

	char_steps = ft_itoa(steps);

	buffer = ft_strjoin(buffer, char_steps);
	len_str = ft_strlen(buffer);

	printf("################# %d #################\n", steps);

//	write(1, buffer, len_str);
//	write(1, "\n", 1);

	free (buffer);
}

void				print_desired_pool(t_list **desired_pool)
{
	t_list		*tmp;
	size_t desired_pool_len = 0;

	tmp = *desired_pool;
	printf("*****************************\n");


	printf("mark : ");
	while (tmp)
	{
		desired_pool_len++;
		printf("%c ", ((t_pool_node *)tmp->content)->bottom_top);
		tmp = tmp->next;
	}
	printf("\n");



	tmp = *desired_pool;


	printf("index : ");
	while (tmp)
	{
		desired_pool_len++;
		printf("%u ", ((t_pool_node *)tmp->content)->index);
		tmp = tmp->next;
	}
	printf("\n");



	tmp = *desired_pool;

	printf("cost  : ");
	while (tmp)
	{
		printf("%u ", ((t_pool_node *)tmp->content)->cost);
		tmp = tmp->next;
	}
	printf("\n");

	printf("---------\ndesired_pool_len = %lu \n---------\n", desired_pool_len);

	printf("*****************************\n");
}

void	print_two_stack(t_list *A, t_list *B)
{
	printf("---------- two stack ------------\n");

	printf("A : ");
	print_index_list(A);


	printf("B : ");
	print_index_list(B);

	printf("\nA len = %d\n", ft_lstsize(A));
	printf("B len = %d\n", ft_lstsize(B));

	printf("---------------------------------\n");

}
*/


// choose next elem to move




// second part (way to home)

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

t_element_to_move	choose_next_elem_to_a(t_list **desired_pool)
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
			 || ((t_pool_node *)tmp_desired_pool->content)->bottom_top == 'B'))
		{
			min_cost = ((t_pool_node *) tmp_desired_pool->content)->cost;
			chosen_desired_pool_node = tmp_desired_pool;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	next_elem.index = ((t_pool_node *)chosen_desired_pool_node->content)->index;
	next_elem.gate = ((t_pool_node *)chosen_desired_pool_node->content)->gate;
	next_elem.cost = ((t_pool_node *)chosen_desired_pool_node->content)->cost;
	next_elem.min_max = ((t_pool_node *)chosen_desired_pool_node->content)->bottom_top;
	((t_pool_node *)chosen_desired_pool_node->content)->gate = 'R';
	return (next_elem);
}













// main sort

int					big_sort(t_list **stack_a, t_list **stack_b)
{
	t_element_to_move	next_elem;
	unsigned int		all_num;
	unsigned int		stack_size;
	t_list				*desired_pool;
	unsigned int		num_pool_nodes;

	all_num = ft_lstsize(*stack_a);
	stack_size = all_num;
	num_pool_nodes = find_num_pool_nodes(stack_size);
	desired_pool = init_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_a(&desired_pool, num_pool_nodes, stack_size);
	calculate_all_costs(&desired_pool, *stack_a, stack_size);
/*
	print_desired_pool(&desired_pool);
	print_two_stack(*stack_a, *stack_b);
*/
//	int steps = 0;
	while (stack_size > 2)
	{
/*
		print_step(++steps);
		if (steps == 282)
			write(1, "\n", 1);
*/
		next_elem = choose_next_elem_to_a(&desired_pool);
		move_to_b(stack_a, stack_b, next_elem);
		stack_size--;
		recost_desired_pool(&desired_pool, *stack_a, stack_size);
		if (is_resize_need(stack_size, num_pool_nodes))
			num_pool_nodes = resize_desired_pool(&desired_pool, num_pool_nodes);
/*
		print_two_stack(*stack_a, *stack_b);
		print_desired_pool(&desired_pool);
		printf("################# end #################\n");
*/
	}
	pb(stack_a, stack_b);
	ft_lstclear(&desired_pool, free);

/// second part

	stack_size = all_num - 1;
	desired_pool = init_desired_pool(2);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_b(&desired_pool, *stack_a);
	calculate_all_costs(&desired_pool, *stack_b, stack_size);



	while (*stack_b)
	{
		next_elem = choose_next_elem_to_b(*stack_b, stack_size, &desired_pool);
		move_to_a(stack_a, stack_b, next_elem);
//		print_two_stack(*stack_a, *stack_b);
		stack_size--;
	}
//	print_two_stack(*stack_a, *stack_b);
	ft_lstclear(&desired_pool, free);
/*
	print_two_stack(*stack_a, *stack_b);
	if (is_ascending(*stack_a))
	{
		printf("!!! OK !!!\n");
	} else
		printf("!!! NOT OK !!!\n");
*/
	return (0);
}
