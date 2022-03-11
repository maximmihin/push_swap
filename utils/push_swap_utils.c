#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

ps_node	*ft_nodenew(int content)
{
	ps_node *elem;

	elem = (ps_node *) malloc(sizeof(ps_node));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = 0;
	elem->mark = 'F';
	return (elem);
}

int sl(t_list **S)
{
	t_list *tmp;
	t_list *s;

	s = *S;

	if (!s && !s->next)
		return (1);

	tmp = s->next->next;
	s->next->next = *S;
	*S = s->next;
	s->next = tmp;

	return (0);
}

int sa(t_list **S)
{
	sl(S);
	write(1, "sa\n", 3);
	return (0);
}

int sb(t_list **S)
{
	sl(S);
	write(1, "sb\n", 3);
	return (0);
}

int ss(t_list **A, t_list **B)
{
	sl(A);
	sl(B);
	write(1, "ss\n", 3);
	return (0);
}

int rl(t_list **S)
{
	t_list *last;
	t_list *tmp;
	t_list *s;

	s = *S;

	tmp	= s->next;
	last = ft_lstlast(*S);
	s->next = NULL;
	last->next = *S;
	*S = tmp;

	return (0);
}

int ra(t_list **S)
{
	rl(S);
	write(1, "ra\n", 3);
	return (0);
}

int rb(t_list **S)
{
	rl(S);
	write(1, "rb\n", 3);
	return (0);
}

int rr(t_list **A, t_list **B)
{
	rl(A);
	rl(B);
	write(1, "rr\n", 3);
	return (0);
}

int rrl(t_list **S)
{
	t_list *tmp;

	tmp = *S;
	while(tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(S, tmp->next);
	tmp->next = NULL;

	return (0);
}

int rra(t_list **S)
{
	rrl(S);
	write(1, "rra\n", 4);
	return (0);
}

int rrb(t_list **S)
{
	rrl(S);
	write(1, "rrb\n", 4);
	return (0);
}

int rrr(t_list **A, t_list **B)
{
	rrl(A);
	rrl(B);
	write(1, "rrr\n", 4);
	return (0);
}

int pl(t_list **A, t_list **B)
{
	t_list *tmp;
	t_list *b;

	b = *B;
	if (b->next)
		tmp = b->next;
	else
		tmp = NULL;
	ft_lstadd_front(A, *B);
	*B = tmp;

	return (0);
}

int	pa(t_list **A, t_list **B)
{
	pl(A, B);
	write(1, "pa\n", 3);
	return (0);
}

int pb(t_list **A, t_list **B)
{
	pl(B, A);
	write(1, "pb\n", 3);
	return (0);
}







int				three_sort(t_list **S)
{
	int	val[3];
	unsigned int	i;
	t_list 			*list_tmp;

	list_tmp = *S;
	i = 0;
	while (i < 3)
	{
		val[i] = (((ps_node *)list_tmp->content)->content);
		list_tmp = list_tmp->next;
		i++;
	}
	if (val[0] > val[1] && val[0] < val[2] && val[1] < val [2]) // case 1
		return (sa(S));
	if (val[0] > val[1] && val[0] > val[2] && val[1] > val[2]) // case 2
		return (sa(S) +	rra(S));
	if (val[0] > val[1] && val[0] > val[2] && val[1] < val[2]) // case 3
		return (ra(S));
	if (val[0] < val[1] && val[0] < val[2] && val[1] > val[2]) // case 4
		return (sa(S) + ra(S));
	if (val[0] < val[1] && val[0] > val[2] && val[1] > val[2]) // case 5
		return (rra(S));
	return (1);
}

int				four_sort(t_list **A, t_list **B)
{
	t_list *tmp_list;

	make_index(A);
	pb(A, B);
	three_sort(A);
	tmp_list = *B;
	if (((ps_node *)tmp_list->content)->index == 2)
		return (pa(A, B) + sa(A));
	if (((ps_node *)tmp_list->content)->index == 3)
		return (rra(A) + pa(A, B) + ra(A) + ra(A));
	if (((ps_node *)tmp_list->content)->index == 4)
		return (pa(A, B) + ra(A));
	return (pa(A, B));
}

unsigned int	find_min_index(t_list *A)
{
	unsigned int min_index;

	min_index = ((ps_node *)A->content)->index;
	A = A->next;
	while (A)
	{
		if (((ps_node *)A->content)->index < min_index)
			min_index = ((ps_node *)A->content)->index;
		A = A->next;
	}
	return (min_index);
}

void			apply_delta(t_list **A, unsigned int delta)
{
	t_list	*tmp_list;

	tmp_list = *A;

	while (tmp_list)
	{
		((ps_node *)tmp_list->content)->index = ((ps_node *)
				tmp_list->content)->index - delta;
		tmp_list = tmp_list->next;
	}
}

void			cancel_delta(t_list **A, unsigned int delta)
{
	t_list	*tmp_list;

	tmp_list = *A;

	while (tmp_list)
	{
		((ps_node *)tmp_list->content)->index += delta;
		tmp_list = tmp_list->next;
	}
}

int				five_sort(t_list **A, t_list **B)
{
	t_list			*tmp_list;
	unsigned int	len_stack;
	unsigned int	delta;

	tmp_list = *A;
	len_stack = 5;
	delta = find_min_index(tmp_list) - 1;
	apply_delta(&tmp_list, delta);
//	print_two_stack(tmp_list, *B);

	while (len_stack > 3)
	{
		if (((ps_node *)tmp_list->content)->index != 3
			&& ((ps_node *)tmp_list->content)->index != 4)
		{
			pb(&tmp_list, B);
//			print_two_stack(tmp_list, *B);
			len_stack--;
		}
		else
		{
			ra(&tmp_list);
//			print_two_stack(tmp_list, *B);
		}
	}
//	print_two_stack(tmp_list, *B);
	three_sort(&tmp_list);
//	print_two_stack(tmp_list, *B);

	pa (&tmp_list, B);
//	print_two_stack(tmp_list, *B);
//	tmp_list = *A;

	if (((ps_node *)tmp_list->content)->index == 5)
	{
		ra(&tmp_list);
//		print_two_stack(tmp_list, *B);
	}

	pa (&tmp_list, B);
//	print_two_stack(tmp_list, *B);
//	*A = tmp_list;
//	tmp_list = *B;
//	tmp_list = *A;

	if (((ps_node *)tmp_list->content)->index == 5)
	{
		ra(&tmp_list);
//		print_two_stack(tmp_list, *B);
	}
	if (((ps_node *)tmp_list->content)->index == 2)
	{
		sa(&tmp_list);
//		print_two_stack(tmp_list, *B);
	}

	cancel_delta(&tmp_list, delta);
	*A = tmp_list;
//	print_two_stack(tmp_list, *B);
//	print_two_stack(*A, *B);
	return (0);
}

int				small_sort(t_list **A, t_list **B, int argc)
{
	t_list	*list_tmp;

	list_tmp = *A;
	if (argc == 3)
		if (((ps_node *)list_tmp->content)->content
			> ((ps_node *)list_tmp->next->content)->content)
			return (sa(&list_tmp));
	if (argc == 4)
		return (three_sort(&list_tmp));
	if (argc == 5)
		return (four_sort(A, B));
	if (argc == 6)
		return (five_sort(A, B));
	return (0);
}










t_pool_node		*pool_node_new(unsigned int index)
{
	t_pool_node	*pool_node;

	pool_node = (t_pool_node *) malloc(sizeof(t_pool_node));
	if (!pool_node)
		return (NULL);
	pool_node->index = index;
	return (pool_node);
}

t_list			*create_desired_pool(unsigned int	num_pool_nodes)
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

void			mark_desired_pool(t_list **desired_pool, unsigned int num_pool_nodes)
{
	t_list			*tmp_desired_pool;
	unsigned int	i;

	tmp_desired_pool = *desired_pool;
	num_pool_nodes /= 2;
	i = 1;
	while (i <= num_pool_nodes)
	{
		((t_pool_node *)tmp_desired_pool->content)->min_max = 'B';
		tmp_desired_pool = tmp_desired_pool->next;
		i++;
	}
	while (tmp_desired_pool)
	{
		((t_pool_node *)tmp_desired_pool->content)->min_max = 'T';
		tmp_desired_pool = tmp_desired_pool->next;
	}
}

void			index_desired_pool_for_a(t_list **desired_pool,
								   unsigned int num_pool_nodes,
								   unsigned int stack_size)
{
	t_list			*tmp_desired_pool;
	unsigned int	i;

	tmp_desired_pool = *desired_pool;
	i = 1;
	while (((t_pool_node *)tmp_desired_pool->content)->min_max == 'B')
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

t_list			*init_desired_pool(unsigned int num_pool_nodes)
{
	t_list			*desired_pool;

	desired_pool = create_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (NULL);

	mark_desired_pool(&desired_pool, num_pool_nodes);

	return (desired_pool);
}









unsigned int		find_pos(t_list *stack, unsigned int index)
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

char				find_gate(unsigned int stack_size, unsigned int pos)
{
	unsigned int	med_S;

	med_S = stack_size / 2;
	if (stack_size % 2)
		med_S++;

	if (pos <= med_S)
		return ('T');
	else
		return ('B');
}

unsigned int		find_cost(size_t stack_size, char gate, unsigned int pos)
{
//	if (pos == 0)
//		return (stack_size + 1);
	if (gate == 'T')
		return (pos - 1);
	else
		return (stack_size - pos + 1);
}

unsigned int		find_cost_node(t_list **desired_pool, t_list *stack,
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




void				calculate_all_costs(t_list **desired_pool, t_list *stack,
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


// не обработал крайние случаи
unsigned int		find_min_in_bottom(t_list *desired_pool, t_list *stack_b)
{
	unsigned int		max_in_bottom;

	max_in_bottom = ((t_pool_node *)desired_pool->content)->index;


	while (((t_pool_node *)desired_pool->content)->min_max == 'B')
	{
		if (((t_pool_node *)desired_pool->content)->index > max_in_bottom)
			max_in_bottom = ((t_pool_node *)desired_pool->content)->index;

		desired_pool = desired_pool->next;
	}


	while (stack_b)
	{
		/// искать надо в стеке Б максимальный элемент этого типа
		if (((ps_node *)stack_b->content)->min_max == 'B'
		&& ((ps_node *)stack_b->content)->index > max_in_bottom)
		{
			max_in_bottom = ((ps_node *)stack_b->content)->index;
		}
		stack_b = stack_b->next;
	}



	return (max_in_bottom);
}

unsigned int		find_max_in_top(t_list *desired_pool, t_list *stack_b)
{
	unsigned int		min_in_top;

	while (((t_pool_node *)desired_pool->content)->min_max == 'B')
		desired_pool = desired_pool->next;
	min_in_top = ((t_pool_node *)desired_pool->content)->index;
	while (desired_pool)
	{
		if (((t_pool_node *)desired_pool->content)->index < min_in_top)
			min_in_top = ((t_pool_node *)desired_pool->content)->index;
		desired_pool = desired_pool->next;
	}



	while (stack_b)
	{
		if (((ps_node *)stack_b->content)->min_max == 'T'
		&& ((ps_node *)stack_b->content)->index < min_in_top)
		{
			min_in_top = ((ps_node *)stack_b->content)->index;
		}
		stack_b = stack_b->next;
	}

	return (min_in_top);
}

void				preproc_next_elem(t_list **desired_pool, t_list **min_list,
								  t_list *stack_a, t_list *stack_b,
								  unsigned int stack_size)
{
	t_list				*tmp_min_list;
	unsigned int		max_in_bottom;
	unsigned int		min_in_top;

	tmp_min_list = *min_list;

/*
	if (((t_pool_node *)tmp_min_list->content)->min_max == 'B')
	{
		max_in_bottom = ((t_pool_node *)tmp_desired_pool->content)->index;
		while (((t_pool_node *)tmp_desired_pool->content)->min_max == 'B')
		{
			if (((t_pool_node *)tmp_desired_pool->content)->index >
			max_in_bottom)
				max_in_bottom = ((t_pool_node *)tmp_desired_pool->content)->index;
			tmp_desired_pool = tmp_desired_pool->next;
		}
		((t_pool_node *)tmp_min_list->content)->index = max_in_bottom + 1;
	}
	else
	{
		while (((t_pool_node *)tmp_desired_pool->content)->min_max == 'B')
			tmp_desired_pool = tmp_desired_pool->next;
		min_in_top = ((t_pool_node *)tmp_desired_pool->content)->index;
		while (tmp_desired_pool)
		{
			if (((t_pool_node *)tmp_desired_pool->content)->index < min_in_top)
				min_in_top = ((t_pool_node *)tmp_desired_pool->content)->index;
			tmp_desired_pool = tmp_desired_pool->next;
		}
		((t_pool_node *)tmp_min_list->content)->index = min_in_top - 1;
	}
*/
	//нужно обработать кейс, когда с верху и снизу значения пересекутся
	// нужно обработать кейс, когда размер desired pool больше 5
	if (((t_pool_node *)tmp_min_list->content)->min_max == 'B')
	{
		max_in_bottom = find_min_in_bottom(*desired_pool, stack_b);
		((t_pool_node *)tmp_min_list->content)->index = max_in_bottom + 1;

		// нужно найти самый большой элемент этого типа в обоих стеках (в том
		// числе в стеке Б) !!!
		//
	}
	else
	{
		min_in_top = find_max_in_top(*desired_pool, stack_b);
		((t_pool_node *)tmp_min_list->content)->index = min_in_top - 1;
	}



	//а теперь нужно пересчитать все парметры заново - ВСЕ нужно пересчитать
	// не одну ноду, а все
	// нет, не все, на данный момент при первом проходе изменений нет
	calculate_all_costs(desired_pool, stack_a, stack_size);
}

t_element_to_move	choose_next_elem_to_a(t_list *A, t_list *B,
										   unsigned int a_size,
										   t_list **desired_pool)
{
	t_element_to_move	next_elem;
	t_list				*tmp_desired_pool;
	t_list				*min_list;
	unsigned int		min_cost;

	calculate_all_costs(desired_pool, A, a_size);

	tmp_desired_pool = *desired_pool;

	//choose low cost
	min_cost = ((t_pool_node *)tmp_desired_pool->content)->cost;
	min_list = tmp_desired_pool;
	while (tmp_desired_pool)
	{
		if (((t_pool_node *)tmp_desired_pool->content)->cost < min_cost)
		{
			min_cost = ((t_pool_node *) tmp_desired_pool->content)->cost;
			min_list = tmp_desired_pool;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}

	//apply to next_elem
	next_elem.index = ((t_pool_node *)min_list->content)->index;
	next_elem.gate = ((t_pool_node *)min_list->content)->gate;
	next_elem.cost = ((t_pool_node *)min_list->content)->cost;

	//test
	next_elem.min_max = ((t_pool_node *)min_list->content)->min_max;


	//preproc next_elem (внутри переидексировать только выбранный элемент)
	preproc_next_elem(desired_pool, &min_list, A, B, a_size);


	return (next_elem);
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

}

void				move_to_a(t_list **A, t_list **B, t_element_to_move next_elem)
{
	t_list	*tmp_a;
	int 	r_counter;


	r_counter = 0;


	if (next_elem.gate == 'T')
		while (next_elem.cost)
		{
			rb(B);
			next_elem.cost--;
			r_counter++;
		}
	else if (next_elem.gate == 'B')
		while (next_elem.cost)
		{
			rrb(B);
			next_elem.cost--;
			r_counter++;
		}
	pa(A, B);

	tmp_a = *A;
	if (((ps_node *)tmp_a->content)->index
	> ((ps_node *)tmp_a->next->content)->index)
		ra(A);

}

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


	//а теперь нужно сделать пересчёт костов
//	calculate_all_costs(desired_pool, stack_b, stack_size);

	return (next_elem);
}






// resize_desired_pool

void				index_desired_pool_for_b(t_list **desired_pool, t_list *stack_a)
{
	unsigned int	median;
	t_list			*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;
	median = ((ps_node *)stack_a->content)->index;

	((t_pool_node *)tmp_desired_pool->content)->index = median + 1;
	((t_pool_node *)tmp_desired_pool->next->content)->index = median - 1;
}

unsigned int		find_num_pool_nodes(unsigned int len_stack)
{
	unsigned int	perfect_len;
	unsigned int 	deep;

	deep = 10;

	if (len_stack < 100)
		return (2);

	perfect_len = len_stack / deep;
	if (perfect_len % 2)
		perfect_len -= 1;

	return (perfect_len);
}

size_t				find_perfect_len_desired_pool(unsigned int len_stack)
{
	unsigned int	perfect_len;
	unsigned int	deep;

	deep = 10;

	perfect_len = len_stack / deep;
	if (perfect_len % 2)
		perfect_len -= 1;

	return (perfect_len);
}

int					is_resize_need(unsigned int stack_size,
									  unsigned int real_len)
{
	size_t	perfect_len;

	if (real_len == 2)
		return (0);

	perfect_len = find_perfect_len_desired_pool(stack_size);

	//сравнить
	if (perfect_len < real_len && !(perfect_len % 2))
		return (1);
	return (0);


/*
	if (stack_size > 10 && stack_size <= 40)
		perfect_len = 4;
	else if (stack_size > 40 && stack_size <= 60)
		perfect_len = 6;
	else if (stack_size > 60 && stack_size <= 80)
		perfect_len = 8;
	else if (stack_size > 80 && stack_size <= 100)
		perfect_len = 10;
	else if (stack_size > 100 && stack_size <= 120)
		perfect_len = 12;
	else if (stack_size > 120 && stack_size <= 140)
		perfect_len = 14;
*/ // hard_value

	return (0);
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

t_list				*find_bottom_min(t_list **desired_pool)
{
	t_list			*tmp_desired_pool;
	t_list			*bottom_min;
	t_pool_node		*min_pool_node;
	unsigned int	min_val;

	tmp_desired_pool = *desired_pool;

	bottom_min = tmp_desired_pool;
	min_pool_node = (t_pool_node *)bottom_min->content;
	min_val = min_pool_node->index;

	while (((t_pool_node *)tmp_desired_pool->content)->min_max == 'B')
	{
		if (((t_pool_node *)tmp_desired_pool->content)->index > min_val)
		{
			bottom_min = tmp_desired_pool;
			min_pool_node = (t_pool_node *)bottom_min->content;
			min_val = min_pool_node->index;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (bottom_min);
}

void				del_bottom_min(t_list **desired_pool)
{
	t_list			*bottom_min;
	t_list			*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;

	bottom_min = find_bottom_min(&tmp_desired_pool);

	del_pool_node(desired_pool, &bottom_min);
}

t_list				*find_top_max(t_list **desired_pool)
{
	t_list			*tmp_desired_pool;
	t_list			*top_max;
	t_pool_node		*max_pool_node;
	unsigned int	max_val;

	tmp_desired_pool = *desired_pool;

	while (((t_pool_node *)tmp_desired_pool->content)->min_max == 'B')
		tmp_desired_pool = tmp_desired_pool->next;

	top_max = tmp_desired_pool;
	max_pool_node = (t_pool_node *)top_max->content;
	max_val = max_pool_node->index;

	while (tmp_desired_pool)
	{
		// ???  > <
		if (((t_pool_node *)tmp_desired_pool->content)->index < max_val)
		{
			top_max = tmp_desired_pool;
			max_pool_node = (t_pool_node *)top_max->content;
			max_val = max_pool_node->index;
		}
		tmp_desired_pool = tmp_desired_pool->next;
	}
	return (top_max);
}

void				del_top_max(t_list **desired_pool)
{
	t_list			*top_max;
	t_list			*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;

	top_max = find_top_max(&tmp_desired_pool);
	del_pool_node(desired_pool, &top_max);
}

void				print_desired_pool(t_list **desired_pool)
{
	t_list		*tmp;
	size_t desired_pool_len = 0;

	tmp = *desired_pool;
	printf("*****************************\n");
	printf("index :");
	while (tmp)
	{
		desired_pool_len++;
		printf("%u ", ((t_pool_node *)tmp->content)->index);
		tmp = tmp->next;
	}
	printf("\n");



	tmp = *desired_pool;

	printf("cost  :");
	while (tmp)
	{
		printf("%u ", ((t_pool_node *)tmp->content)->cost);
		tmp = tmp->next;
	}
	printf("\n");

	printf("---------\ndesired_pool_len = %lu \n---------\n", desired_pool_len);

	printf("*****************************\n");
}

void				resize_desired_pool(t_list **desired_pool)
{
		del_bottom_min(desired_pool);
//		print_desired_pool(desired_pool);
		del_top_max(desired_pool);
//		print_desired_pool(desired_pool);
}


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

	write(1, buffer, len_str);
	write(1, "\n", 1);
	free (buffer);
}


int					big_sort(t_list **A, t_list **B)
{
	t_element_to_move	next_elem;
	unsigned int		all_num;
	unsigned int		stack_size;
	t_list				*desired_pool;
	unsigned int		num_pool_nodes;


	all_num = ft_lstsize(*A);
	stack_size = all_num;

	num_pool_nodes = find_num_pool_nodes(stack_size);
	desired_pool = init_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_a(&desired_pool, num_pool_nodes, stack_size);



//	print_desired_pool(&desired_pool);
//	print_two_stack(*A, *B);





	while (stack_size > 2)
	{
		next_elem = choose_next_elem_to_a(*A, *B, stack_size, &desired_pool);

		move_to_b(A, B, next_elem);
//		int steps = 0;
//		print_step(++steps);
//		print_two_stack(*A, *B);
//		print_desired_pool(&desired_pool);

//		if (steps == 69)
//			write (1, "69\n", 3);




		stack_size--;

		if (is_resize_need(stack_size, num_pool_nodes))
		{
			resize_desired_pool(&desired_pool);
//			print_desired_pool(&desired_pool);
			num_pool_nodes -=2;
//			write(1, "resize *************************\n", 33);
		}

//		print_desired_pool(&desired_pool);
	}
//	print_two_stack(*A, *B);


	while (--num_pool_nodes)
		pb(A, B);
	ft_lstclear(&desired_pool, free);


//	print_two_stack(*A, *B);




	stack_size = all_num - 1;
	desired_pool = init_desired_pool(2);
	if (!desired_pool)
		return (1);
	index_desired_pool_for_b(&desired_pool, *A);
	calculate_all_costs(&desired_pool, *B, stack_size);



	while (*B)
	{
		next_elem = choose_next_elem_to_b(*B, stack_size, &desired_pool);
		move_to_a(A, B, next_elem);
//		print_two_stack(*A, *B);
		stack_size--;
	}
//	print_two_stack(*A, *B);
	ft_lstclear(&desired_pool, free);

//	print_two_stack(*A, *B);
	return (0);
}

