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
	ft_lstadd_front(A, b);
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

int	three_sort(t_list **S)
{
	unsigned int	val[3];
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

int	four_sort(t_list **A, t_list **B)
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

int	five_sort(t_list **A, t_list **B)
{
	t_list	*tmp_list;
	unsigned int	len_stack;

	tmp_list = *A;
	len_stack = 5;
	make_index(A);
	while (len_stack > 3)
	{
		if (((ps_node *)tmp_list->content)->index != 3
			&& ((ps_node *)tmp_list->content)->index != 4)
		{
			pb(A, B);
			len_stack--;
		}
		else
			ra(A);
	}
	three_sort(A);
	pa (A, B);
	tmp_list = *A;

	if (((ps_node *)tmp_list->content)->index == 5)
		ra(A);

	pa (A, B);
	tmp_list = *A;

	if (((ps_node *)tmp_list->content)->index == 5)
		ra(A);
	if (((ps_node *)tmp_list->content)->index == 2)
		sa(A);
	return (0);
}

int	small_sort(t_list **A, t_list **B, int argc)
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




unsigned int	find_pos(t_list *A, unsigned int index)
{
	unsigned int	pos;
	ps_node			*tmp_node;

	pos = 1;
	tmp_node = ((ps_node *)A->content);

	while (A)
	{
		if (tmp_node->index == index)
			break;
		A = A->next;
		tmp_node = ((ps_node *)A->content);
		pos++;
	}
	return (pos);
}

char			find_gate(size_t a_size, unsigned int pos)
{
	unsigned int	med_S;

	med_S = a_size / 2;
	if (a_size % 2)
		med_S++;

	if (pos <= med_S)
		return ('T');
	else
		return ('B');
}

unsigned int	find_cost(size_t a_size, char gate, unsigned int pos)
{
	if (gate == 'T')
		return (pos);
	else
		return (a_size - pos + 1);
}

unsigned int	find_next_elem(t_list *A, unsigned int a_size,
							   t_extrema **extrema)
{
	t_extrema 		*tmp_extrema;

	tmp_extrema = *extrema;

	tmp_extrema->min_pos = find_pos(A, tmp_extrema->min_index);
	tmp_extrema->max_pos = find_pos(A, tmp_extrema->max_index);

	tmp_extrema->min_gate = find_gate(a_size, tmp_extrema->min_pos);
	tmp_extrema->max_gate = find_gate(a_size, tmp_extrema->max_pos);

	tmp_extrema->min_cost = find_cost(a_size, tmp_extrema->min_gate, tmp_extrema->min_pos);
	tmp_extrema->max_cost = find_cost(a_size, tmp_extrema->max_gate, tmp_extrema->max_pos);

	if (tmp_extrema->max_cost > tmp_extrema->min_cost)
		return (tmp_extrema->min_index);
	else
		return (tmp_extrema->max_index);
}

int fill_stack_a(t_list **A, t_list **B)
{
	t_list *tmp_list;

	tmp_list = *A;
	while (B)
	{
		pa(A, B);
		if (((ps_node *)tmp_list->content)->index
			> ((ps_node *)tmp_list->next->content)->index)
		{
			ra(A);
			printf("B\n");
		}
	}
	return (0);
}

void preproc_next_elem(t_extrema **extrema)
{
	t_extrema		*tmp_extrema;

	tmp_extrema = *extrema;
	if (tmp_extrema->next_elem == tmp_extrema->min_index)
	{
		tmp_extrema->next_elem_gate = tmp_extrema->min_gate;
		tmp_extrema->next_elem_cost = tmp_extrema->min_cost - 1;
	}
	else
	{
		tmp_extrema->next_elem_gate = tmp_extrema->max_gate;
		tmp_extrema->next_elem_cost = tmp_extrema->max_cost - 1;
	}
}

int move_to_b(t_list **A, t_list **B, t_extrema **extrema)
{
	t_extrema		*tmp_extrema;

	tmp_extrema = *extrema;

	if (tmp_extrema->next_elem_gate == 'T')
		while (tmp_extrema->next_elem_cost)
		{
			ra(A);
			tmp_extrema->next_elem_cost--;
		}
	else if (tmp_extrema->next_elem_gate == 'B')
		while (tmp_extrema->next_elem_cost)
		{
			rra(A);
			tmp_extrema->next_elem_cost--;
		}
	pb(A, B);
	if (tmp_extrema->next_elem == tmp_extrema->min_index)
		tmp_extrema->min_index++;
	else
		tmp_extrema->max_index--;
	return (0);
}

int big_sort(t_list **A, t_list **B)
{
	///сделать подсчёт действий в функции
	t_extrema		*extrema;
	unsigned int	a_size;

	extrema = (t_extrema *) malloc(sizeof (t_extrema));
	if (!extrema)
		return (1);
	a_size = ft_lstsize(*A);

	extrema->min_index = 1;
	extrema->max_index = a_size;
	make_index(A);

	while (a_size > 5)
	{
		extrema->next_elem = find_next_elem(*A, a_size, &extrema);
		preproc_next_elem(&extrema);
		move_to_b(A, B, &extrema);
		a_size--;
	}
	five_sort(A, B);
	fill_stack_a(A, B);
	return (0);
}

