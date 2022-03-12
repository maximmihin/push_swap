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




// print info

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
/*
	write(1, buffer, len_str);
	write(1, "\n", 1);
*/
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



// small sort

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










// init desired pool

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

void			index_desired_pool_for_a(t_list **desired_pool,
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

t_list			*init_desired_pool(unsigned int num_pool_nodes)
{
	t_list			*desired_pool;

	desired_pool = create_desired_pool(num_pool_nodes);
	if (!desired_pool)
		return (NULL);

	mark_desired_pool(&desired_pool, num_pool_nodes);

	return (desired_pool);
}









// calculate cost

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
	/// xz
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





// choose next elem to move

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

		next_elem.index_next = ((t_pool_node *)top_desired_pool->content)->index;
		next_elem.gate_next = ((t_pool_node *)top_desired_pool->content)->gate;

		((t_pool_node *)bottom_desired_pool->content)->index++;
	}
	else
	{
		next_elem.index = ((t_pool_node *)top_desired_pool->content)->index;
		next_elem.gate = ((t_pool_node *)top_desired_pool->content)->gate;
		next_elem.cost = ((t_pool_node *)top_desired_pool->content)->cost;

		next_elem.index_next = ((t_pool_node *)bottom_desired_pool->content)->index;
		next_elem.gate_next = ((t_pool_node *)bottom_desired_pool->content)->gate;

		((t_pool_node *)top_desired_pool->content)->index--;
	}


	return (next_elem);
}












// move_to_b

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






// is resize need

unsigned int		find_num_pool_nodes(unsigned int len_stack)
{
	unsigned int	perfect_len;
	unsigned int 	deep;

	/// deep
	deep = 5;

	if (len_stack < 100)
		return (4);

	perfect_len = len_stack / deep;
	if (perfect_len % 2)
		perfect_len -= 1;

	return (perfect_len);
}

unsigned int		find_perfect_len_desired_pool(unsigned int stack_size,
													unsigned int num_pool_node)
{
	unsigned int	fact_deep;
	double			perfect_len;

	fact_deep = stack_size / num_pool_node;
	if (fact_deep % 2)
		fact_deep--;


	/// 10%
	perfect_len = fact_deep;
	perfect_len += (perfect_len / 100) * (0.2 * stack_size);


	return (perfect_len);
}


int					is_resize_need(unsigned int stack_size,
									  unsigned int num_pool_nodes)
{
	size_t	perfect_len;

	/// test
	if (num_pool_nodes == 2)
		return (0);

	perfect_len = find_perfect_len_desired_pool(stack_size, num_pool_nodes);

	//сравнить
	if (perfect_len < num_pool_nodes && !(perfect_len % 2))
		return (1);
	return (0);
}




// resize

t_list				*find_max_top_node(t_list **desired_pool)
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

t_list				*find_min_bottom_node(t_list **desired_pool)
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


void				hide_pool_top_max(t_list **desired_pool)
{
	t_list			*max_top;
	t_list			*tmp_desired_pool;

	/// эта переменная лишняя, можно без неё обойтись
	tmp_desired_pool = *desired_pool;

	max_top = find_max_top_node(&tmp_desired_pool);

	((t_pool_node *)max_top->content)->bottom_top = 't';
//	del_pool_node(desired_pool, &max_top);
}

void				hide_pool_bottom_min(t_list **desired_pool)
{
	t_list			*min_bottom;
	t_list			*tmp_desired_pool;

	tmp_desired_pool = *desired_pool;

	min_bottom = find_min_bottom_node(&tmp_desired_pool);

	((t_pool_node *)min_bottom->content)->bottom_top = 'b';
//	del_pool_node(desired_pool, &min_bottom);
}



int				resize_desired_pool(t_list **desired_pool,
										unsigned int num_pool_nodes)
{
	hide_pool_top_max(desired_pool);
//	print_desired_pool(desired_pool);
	hide_pool_bottom_min(desired_pool);
//	print_desired_pool(desired_pool);

	num_pool_nodes -= 2;
	return (num_pool_nodes);
}











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
	/*
		t_list	*tmp_b;
		unsigned int 	tmp;

		tmp_b = *B;

		if (next_elem.bottom_top == 'B' && next_elem.index > 2)
		{
			tmp = next_elem.index--;
		}
		else
		{
			tmp = next_elem.index++;
		}
	*/
	if (next_elem.gate == 'T')
		while (next_elem.cost)
		{
			/// test



			rb(B);
			next_elem.cost--;
		}
	else if (next_elem.gate == 'B')
		while (next_elem.cost)
		{
			/// test



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

	//choose next elem (low cost)
	while (((t_pool_node *)tmp_desired_pool->content)->bottom_top == 't')
	{
		tmp_desired_pool = tmp_desired_pool->next;
	}

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

	//apply to return value
	next_elem.index = ((t_pool_node *)chosen_desired_pool_node->content)->index;
	next_elem.gate = ((t_pool_node *)chosen_desired_pool_node->content)->gate;
	next_elem.cost = ((t_pool_node *)chosen_desired_pool_node->content)->cost;

	//test
	next_elem.min_max = ((t_pool_node *)chosen_desired_pool_node->content)->bottom_top;

	// помечаю, что этот элемент нужно обновить
	((t_pool_node *)chosen_desired_pool_node->content)->gate = 'R';


	/// я вынес preproc в функцию биг сорт
	//preproc next_elem (внутри переидексировать только выбранный элемент)
//	preproc_next_elem(desired_pool, &chosen_desired_pool_node, A, B,
	//				  a_size);


	return (next_elem);
}












// preproc

// T (Top) - Начало стека А ( 1, 2 , 3, ... )
// T - Активная нода (значение ещё находится в стеке А и мы его обсчитываем)
// t - НЕ активная нода (значение ещё находитсяв стеке А, но мы его не обсч-ем)

// B (Bottom) - Конец стека А ( ... , 98, 99, 100 )
// B и b аналогичны T и t

unsigned int		find_next_top(t_list *desired_pool/*, t_list *stack_b*/)
{
	unsigned int		max_in_top;

	max_in_top = ((t_pool_node *)desired_pool->content)->index;


	while (((t_pool_node *)desired_pool->content)->bottom_top == 'T'
		   || ((t_pool_node *)desired_pool->content)->bottom_top == 't')
	{
		///среди неактивных элементов нужно искать меньший, а не больший
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
/*
	while (stack_b)
	{
		/// искать надо в стеке Б максимальный элемент этого типа
		if (((ps_node *)stack_b->content)->bottom_top == 'B'
		&& ((ps_node *)stack_b->content)->index > max_in_top)
		{
			max_in_top = ((ps_node *)stack_b->content)->index;
		}
		stack_b = stack_b->next;
	}
*/
	return (max_in_top);
}

unsigned int		find_next_bottom(t_list *desired_pool/*, t_list *stack_b*/)
{
	unsigned int		min_in_bottom;

	while (((t_pool_node *)desired_pool->content)->bottom_top == 'T'
		   || ((t_pool_node *)desired_pool->content)->bottom_top == 't')
		desired_pool = desired_pool->next;

	min_in_bottom = ((t_pool_node *)desired_pool->content)->index;

	while (desired_pool)
	{

		///среди неактивных элементов нужно искать меньший, а не больший
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

/*
	while (stack_b)
	{
		if (((ps_node *)stack_b->content)->bottom_top == 'B'
		&& ((ps_node *)stack_b->content)->index < min_in_bottom)
		{
			min_in_bottom = ((ps_node *)stack_b->content)->index;
		}
		stack_b = stack_b->next;
	}
*/

	return (min_in_bottom);
}


void				preproc_next_elem(t_list **desired_pool, t_list **chosen_pool_node,
									  t_list *stack_a,/* t_list *stack_b,*/
									  unsigned int stack_size)
{
	t_list				*pool_node_to_recost;
	unsigned int		next_elem_index;

	pool_node_to_recost = *chosen_pool_node;


	// поиск значения, которое должно встать на место уже перенесённого в стек Б
	if (((t_pool_node *)pool_node_to_recost->content)->bottom_top == 'T')
	{
		/// поиск самого большого элемента при двжении от начала к концу стека
		next_elem_index = find_next_top(*desired_pool/*, stack_b*/);
	}
	else
	{
		/// поиск самого малнького элемента при двжении от конца к началу стека
		next_elem_index = find_next_bottom(*desired_pool/*, stack_b*/);
	}

	((t_pool_node *)pool_node_to_recost->content)->index = next_elem_index;

	/// тут есть мутный вопрос с элементами, которые уже оказались в стеке Б,
	/// пока не понятно нужно ли их проверять тоже


	/// теперь нужно проверить не содердится ли этот элемент в desired_pool
	/// как не активный
	/// если содержится то удлать это ноду

	// подсчёт коста нового значения
	// вообще достаточно пересчитать один элемент
	((t_pool_node *)pool_node_to_recost->content)->cost = find_cost_node
			(&pool_node_to_recost, stack_a, stack_size);
//	calculate_all_costs(desired_pool, stack_a, stack_size);
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

	/// это переписать
	ft_lstdelone(tmp_node_to_del, free);
}

int				del_waste_pool_node(t_list **desired_pool,
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


void	recost_desired_pool(t_list **desired_pool, t_list *stack_a,
							unsigned int stack_size)
{
	t_list				*tmp_desired_pool;
	t_list				*pool_node_to_recost;
	unsigned int		next_elem_index;

	tmp_desired_pool = *desired_pool;




	// ищу ноду, где нужно обновить индекс (использованную)
	while (tmp_desired_pool)
	{
		if (((t_pool_node *)tmp_desired_pool->content)->gate == 'R')
			break;
		tmp_desired_pool = tmp_desired_pool->next;
	}
	pool_node_to_recost = tmp_desired_pool;




	// поиск значения, которое должно встать на место использованного
	if (((t_pool_node *)pool_node_to_recost->content)->bottom_top == 'T'
		|| ((t_pool_node *)pool_node_to_recost->content)->bottom_top == 't')
	{
		/// поиск самого большого элемента при двжении от начала к концу стека
		next_elem_index = find_next_top(*desired_pool);

		/// тут есть мутный вопрос с элементами, которые уже оказались в стеке Б,
		/// пока не понятно нужно ли их проверять тоже
	}
	else
	{
		/// поиск самого малнького элемента при двжении от конца к началу стека
		next_elem_index = find_next_bottom(*desired_pool);

		/// тут есть мутный вопрос с элементами, которые уже оказались в стеке Б,
		/// пока не понятно нужно ли их проверять тоже
	}








	/// теперь нужно проверить не содердится ли в desired_pool элемент с
	/// таким же индексом как next_elem_inde как не активный
	/// если содержится то удлать это ноду
	if (!del_waste_pool_node(desired_pool, next_elem_index))
	{
		if (((t_pool_node *)pool_node_to_recost->content)->bottom_top == 'T')
			next_elem_index++;
		else
			next_elem_index--;
	}

	((t_pool_node *)pool_node_to_recost->content)->index = next_elem_index;



	calculate_all_costs(desired_pool, stack_a, stack_size);
}


// main sort

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
	calculate_all_costs(&desired_pool, *A, stack_size);

/*
	print_desired_pool(&desired_pool);
	print_two_stack(*A, *B);
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


		move_to_b(A, B, next_elem);

		stack_size--;


		recost_desired_pool(&desired_pool, *A, stack_size);







		if (is_resize_need(stack_size, num_pool_nodes))
		{
			num_pool_nodes = resize_desired_pool(&desired_pool, num_pool_nodes/*, A*/);
//			print_desired_pool(&desired_pool);
//			write(1, "resize *************************\n", 33);
		}

/*
		print_two_stack(*A, *B);
		print_desired_pool(&desired_pool);
		printf("################# end #################\n");
*/
//		print_desired_pool(&desired_pool);
	}
//	print_two_stack(*A, *B);







//	while (--num_pool_nodes)
		pb(A, B);
	ft_lstclear(&desired_pool, free);



//	print_two_stack(*A, *B);


/// second part

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
/*
	print_two_stack(*A, *B);
	if (is_ascending(*A))
	{
		printf("!!! OK !!!\n");
	} else
		printf("!!! NOT OK !!!\n");
*/
	return (0);
}




