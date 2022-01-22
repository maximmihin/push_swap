#include "push_swap.h"

void	print_content_list(t_list *S)
{
	ps_node *ps_tmp;

	while (S)
	{
		ps_tmp = S->content;
		printf("%d ", ps_tmp->content);
		S = S->next;
	}
	printf("\n");
}

void	print_index_list(t_list *S)
{
	ps_node *ps_tmp;

	while (S)
	{
		ps_tmp = S->content;
		printf("%d ", ps_tmp->index);
		S = S->next;
	}
	printf("\n");
}

void	print_mark_list(t_list *S)
{
	ps_node *ps_tmp;

	while (S)
	{
		ps_tmp = S->content;
		printf("%c ", ps_tmp->mark);
		S = S->next;
	}
	printf("\n");
}

void index_bzero(t_list **S)
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

t_list *find_index(t_list **S, unsigned int index)
{
	t_list *tmp;
	ps_node *ps_tmp;

	tmp = *S;

	while (tmp)
	{
		ps_tmp = tmp->content;
		if (ps_tmp->index == index)
			return(tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

ps_node *get_node(t_list *S)
{
	ps_node *node;

	node = S->content;
	return (node);
}

t_list *find_min_list(t_list *A, t_list *B)
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

void	print_node_index(t_list *S)
{
	ps_node *node;

	node = get_node(S);
	printf("node index = %d\n", node->index);
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
		min_lst = find_index(S, 0);
		tmp = *S;
		++index;
	}
}

t_list	**make_ind_mark(t_list **S)
{
	t_list *tmp;
	t_list	**mas;
	int		lst_len;
	int		i;

	tmp = *S;
	lst_len = ft_lstsize(tmp);

	mas = (t_list **) malloc(sizeof (t_list *) * lst_len + 1);
	if (!mas)
		return (NULL);
	mas[lst_len] = NULL;

	i = 0;
	while (mas[i])
	{
		mas[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	return (mas);
}

int	check_index(t_list *S, unsigned int index)
{
	t_list	*tmp;
	ps_node	*ps_tmp;

	if (S == NULL)
		return (1);
	tmp = S;
	ps_tmp = tmp->content;
	if (ps_tmp->index == index)
	{
		ps_tmp->mark = 'T';
		return (1);
	}
	else
		return (0);
}

int	make_mark(t_list **S)
{
	t_list			*tmp;
	t_list			**mark_index;
	unsigned int	index;

	tmp = *S;
	mark_index = make_ind_mark(S);
	if (!mark_index)
		return (1);
	index = 1;
	while (tmp)
	{
		while (!check_index(tmp, index) && tmp)
			tmp = tmp->next;
		++index;
		if (!tmp)
			break;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_list *A;
//	t_list *B;
	int i;


	if (argc == 1)
	{
		printf("No one argument! Bye!\n");
		return (0);
	}

	A = ft_lstnew(ft_nodenew(ft_atoi(argv[1])));

	i = 2;
	while (argv[i])
		ft_lstadd_back(&A, ft_lstnew(ft_nodenew(ft_atoi(argv[i++]))));


	printf("Before mark :\n");
	print_content_list(A);
	print_mark_list(A);

	make_index(&A);
	make_mark(&A);

	printf("After mark :\n");
	print_content_list(A);
	print_mark_list(A);





	//make markup (true || false)









//sl, rl, rrl tests
/*
	printf("Before : ");
	print_content_list(&A);
	rl(&A, 'a');
	printf("\nAfter  : ");
	print_content_list(&A);
	printf("\n");
*/
//pl tests
/*
	char **qq;
	char str[] = "5 6 7 8 9";

	qq = ft_split(str, ' ');

	B = ft_lstnew(qq[0]);

	i = 1;
	while (qq[i])
		ft_lstadd_back(&B, ft_lstnew(qq[i++]));


	printf("A : ");
	print_list(&A);
	printf("\nB : ");
	print_list(&B);
	printf("\n-----------------\n");
	pl(&A, &B, 'a');
	printf("A : ");
	print_list(&A);
	printf("\nB : ");
	print_list(&B);
*/
	return (0);
}
