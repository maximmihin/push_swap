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

unsigned int	find_cost(unsigned int index, t_list *S)
{
	unsigned int	pos;
	unsigned int	med_S;
	unsigned int	tmp;
	ps_node			*tmp_node;

	pos = 1;
	tmp_node = ((ps_node *)S->content);
	tmp = ft_lstsize(S);

	while (S)
	{
		if (tmp_node->index == index)
			break;
		S = S->next;
		tmp_node = ((ps_node *)S->content);
		pos++;
	}

	med_S = tmp / 2;
	if (tmp % 2)
		med_S++;

	if (pos <= med_S)
		return (pos - 1 + 1);
	return (tmp - pos + 1 + 1);
}

unsigned int	find_low_cost(unsigned int index, t_list *S, )
{

}

t_extrema	*choose_next_elem(t_list *A, t_list *B, t_extrema *extrema)
{

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

int big_sort(t_list **A, t_list **B)
{
	///сделать подсчёт действий в функции
	t_extrema		*extrema;
	unsigned int	a_size;
	unsigned int	steps;


	extrema = (t_extrema *) malloc(sizeof (t_extrema));
	if (!extrema)
		return (1);

	a_size = ft_lstsize(*A);
	extrema->min_index = 1;
	extrema->max_index = a_size;

	make_index(A);

	while (a_size > 5)
	{
		a_size--;
		extrema->min_cost = find_cost(extrema->min_index, *A);
		extrema->max_cost = find_cost(extrema->max_index, *A);
		if (extrema->min_cost <= extrema->max_cost)
		{
			extrema->min_index++;
			while (extrema->min_cost)
			{
				ra(A);
				printf("A\n");
				steps++;
				extrema->min_cost--;
			}
			pb(A, B);
			steps++;
		}
		else
		{
			extrema->max_index--;
			while (extrema->max_cost)
			{
				rra(A);
				steps++;
				extrema->max_cost--;
			}
			pb(A, B);
			steps++;
		}
	}

	five_sort(A, B);
	fill_stack_a(A, B);

}

