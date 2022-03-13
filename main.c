#include "push_swap.h"


void	index_bzero(t_list **S)
{
	t_list *tmp;
	ps_node *ps_tmp;

	tmp = *S;

	while (tmp)
	{
		ps_tmp = tmp->content;
		ps_tmp->index = 0;
		tmp = tmp->next;
	}
}

t_list	*find_index(t_list *S, unsigned int index)
{
	ps_node *ps_tmp;

	while (S)
	{
		ps_tmp = S->content;
		if (ps_tmp->index == index)
			return(S);
		S = S->next;
	}
	return (NULL);
}

ps_node	*get_node(t_list *S)
{
	ps_node *node;

	node = S->content;
	return (node);
}

t_list	*find_min_list(t_list *A, t_list *B)
{
	ps_node	*ps_A;
	ps_node	*ps_B;

	ps_A = get_node(A);
	ps_B = get_node(B);
	if (ps_A->index)
		return (B);
	if (ps_B->index)
		return (A);
	if (ps_A->content < ps_B->content)
		return (A);
	else
		return (B);
}

void	assign_index(t_list **S, unsigned int index)
{
	ps_node *tmp;

	tmp = get_node(*S);
	tmp->index = index;
}

void	make_index(t_list **S)
{
	t_list *tmp;
	t_list *min_lst;
	unsigned int lst_len;
	unsigned int index;

	tmp = *S;
	min_lst = tmp;
	lst_len = ft_lstsize(tmp);
	index = 1;
	index_bzero(S);
	while (index <= lst_len)
	{
		while (tmp)
		{
			min_lst = find_min_list(min_lst, tmp);
			tmp = tmp->next;
		}
		assign_index(&min_lst, index);
		min_lst = find_index(*S, 0);
		tmp = *S;
		++index;
	}
}

char	*make_mark_ascending(t_list *S, unsigned int lst_len)
{
	char			*arr_mark;
	ps_node			*tmp;
	unsigned int	index;
	unsigned int	j;

	arr_mark = (char *) malloc(sizeof(char) * (lst_len + 1));
	if (!arr_mark)
		return (NULL);
	arr_mark[lst_len] = '\0';
	index = 1;
	j = 0;
	while (S)
	{
		tmp = get_node(S);
		if (tmp->index == index)
		{
			arr_mark[j] = 'T';
			++index;
		}
		else
			arr_mark[j] = 'F';
		++j;
		S = S->next;
	}
	return (arr_mark);
}

char	*make_mark_descending(t_list *S, unsigned int lst_len)
{
	char			*arr_mark;
	ps_node			*tmp;
	unsigned int	j;

	arr_mark = (char *) malloc(sizeof(char) * (lst_len + 1));
	if (!arr_mark)
		return (NULL);
	arr_mark[lst_len] = '\0';
	j = 0;
	while (S)
	{
		tmp = get_node(S);
		if (tmp->index == lst_len)
		{
			arr_mark[j] = 'T';
			--lst_len;
		}
		else
			arr_mark[j] = 'F';
		++j;
		S = S->next;
	}
	return (arr_mark);
}

void	apply_mark(t_list **S, const char *arr)
{
	t_list	*t_tmp;
	ps_node	*node;
	unsigned int i;

	t_tmp = *S;
	i = 0;
	while(t_tmp)
	{
		node = get_node(t_tmp);
		node->mark = arr[i];
		i++;
		t_tmp = t_tmp->next;
	}
}

int		make_mark(t_list **S)
{
	unsigned int 	lst_len;
	char			**mark_index;

	lst_len = ft_lstsize(*S);
	mark_index = (char **) malloc(sizeof(char *) * 3);
	if (!mark_index)
		return (1);
	mark_index[2] = NULL;

	mark_index[0] = make_mark_ascending(*S, lst_len);
	if (!mark_index[0])
		return (1);
	mark_index[1] = make_mark_descending(*S, lst_len);
	if (!mark_index[1])
		return (1);

	apply_mark(S, mark_index[0]);

	return (0);
}

int		is_ascending(t_list *stack)
{
	ps_node			*ps_tmp;
	unsigned int	index_tmp;

	ps_tmp = (ps_node *)stack->content;
	index_tmp = ps_tmp->index;
	stack = stack->next;
	while (stack)
	{
		ps_tmp = (ps_node *)stack->content;
		if (index_tmp + 1 != ps_tmp->index)
			return (0);
		index_tmp = ps_tmp->index;
		stack = stack->next;
	}
	return (1);
}









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




int		main(int argc, char **argv)
{
	t_list *A;
	t_list *B;

	if (argc == 1 || argc == 2)
		return (0);

	A = parser(argv);
	if (!A)
		return (0);

	if (argc < 7)
		return (small_sort(&A, &B, argc));

	return (big_sort(&A, &B));
}
