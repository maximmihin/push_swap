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

void	print_two_stack(t_list *A, t_list *B)
{

	printf("----------------------\n");
	printf("A : ");
	print_index_list(A);
	printf("B : ");
	print_index_list(B);
	printf("----------------------\n");

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
		min_lst = find_index(*S, 0);
		tmp = *S;
		++index;
	}
}



//MARK
/*
char	**make_ind_mark(unsigned int lst_len)
{
	char	**mas;
	int		i;

	mas = (char **) malloc(sizeof (char *) * (lst_len + 1));
	if (!mas)
		return (NULL);
	mas[lst_len] = NULL;
	i = 0;
	while (lst_len)
	{
		mas[i] = (char *) malloc(sizeof (char) * 2);
		if (!mas[i])
		{
			free(mas);
			return (NULL);
		}
		++i;
		--lst_len;
	}
	return (mas);
}

int		check_index(t_list *S, unsigned int index, char *mark_index)
{
	t_list	*tmp;
	ps_node	*ps_tmp;
	//char	mi_tmp;

	if (S == NULL)
		return (1);
	tmp = S;
	ps_tmp = tmp->content;
	//mi_tmp = *mark_index;
	if (ps_tmp->index == index)
	{
		//mi_tmp = 'T';
		*mark_index = 'T';
		printf("T\n");
		return (1);
	}
	if (mark_index)
		*mark_index = 'F';
	printf("F\n");
	return (0);
}

int		make_mark_ad(t_list **S, char ***m_i, int ad)
{
	unsigned int	index;
	unsigned int	mi_index;
	t_list			*tmp;
	char			**mark_index;

	mark_index = *m_i;
	tmp = *S;
	mi_index = 0;
	if (ad == 0)
		index = 1;
	else
		index = ft_lstsize(*S);
	while (tmp)
	{
		while (!check_index(tmp, index, &mark_index[mi_index][ad]) && tmp)
		{
			mi_index++;
			//printf("mi_index")
			tmp = tmp->next;
		}
		mi_index++;
		if (!tmp)
			break;
		if (ad == 0)
			++index;
		else
			--index;
	}
	return (0);
}

void	ppprint(char **mas)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("\nppprint :\n");
	while (mas[i])
	{
		printf("%c ", mas[i][j]);
		i++;
	}
	printf("\n");
}
*/


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
/*
	int i = 0;
	printf("ascending\n");
	while (arr_mark[i])
	{
		printf("%c ", arr_mark[i]);
		i++;
	}
	printf("\n");
*/
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
/*
	printf("descending\n");
	int i = 0;
	while (arr_mark[i])
	{
		printf("%c ", arr_mark[i]);
		i++;
	}
	printf("\n");
*/
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

	//функция, которая сравнит и выберет лучший вариант (a || d)

	//функция, которая запишет лучший вариант в лист
	apply_mark(S, mark_index[0]);

	return (0);
}




int		is_ascending(t_list *S)
{
	ps_node			*ps_tmp;
	unsigned int	index_tmp;

	ps_tmp = (ps_node *)S->content;
	index_tmp = ps_tmp->index;
	S = S->next;

	while (S)
	{
		ps_tmp = (ps_node *)S->content;
		if (index_tmp + 1 != ps_tmp->index)
			return (0);
		index_tmp = ps_tmp->index;
		S = S->next;
	}
	return (1);
}

unsigned int	len_descending(t_list *S)
{
	ps_node			*ps_tmp;
	unsigned int	index_tmp;
	unsigned int	len;

	index_tmp = ft_lstsize(S);
	len = 0;
	S = S->next;

	while (S)
	{
		ps_tmp = (ps_node *)S->content;
		if (index_tmp - 1 != ps_tmp->index)
			return (0);
		index_tmp = ps_tmp->index;
		S = S->next;
		len++;
	}
	return (len);
}

int		check_non_numeric_symbols(char **str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (str[i] && str[i][j])
	{
		while (str[i][j])
		{
			if (!(str[i][j] == '-' || ft_isdigit(str[i][j])))
				return (1);
			++j;
		}
		++i;
		j = 0;
	}
	return (0);
}

size_t	ft_arrlen(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		check_double(char **str)
{
	size_t len_arr;
	size_t *nums;
	int i;
	size_t j;

	len_arr = ft_arrlen(str);
	nums = (size_t *) malloc(sizeof(size_t) * (len_arr + 1));
	if (!nums)
		return (1);
	i = -1;
	while (++i < (int)len_arr)
		nums[i] = ft_strlen(str[i]);
	i = 0;
	j = 0;
	while (i < (int)len_arr)
	{
		while (++j < len_arr)
			if (nums[i] == nums[j] && !(ft_strncmp(str[i], str[j], nums[i])))
				return (1);
		i++;
		j = i;
	}
	free(nums);
	return (0);
}

/*
int		s_check_double(t_list *list)
{
	t_list	*t_tmp;
	ps_node *ps_tmp;
	int		num;

	while (list)
	{
		ps_tmp = get_node(list);
		num = ps_tmp->content;
		t_tmp = list->next;
		while (t_tmp)
		{
			ps_tmp = get_node(t_tmp);
			if (num == ps_tmp->content)
				return (1);
			t_tmp = t_tmp->next;
		}
		list = list->next;
	}
	return (0);
}
*/
t_list	*parser(char **str)
{
	t_list	*list;
	size_t	i;

	if (check_non_numeric_symbols(str))
	{
		printf("find non-numeric symbols\n");
		return (NULL);
	}

	if (check_double(str))
	{
		printf("find doubles\n");
		return (NULL);
	}

	///make list
	list = ft_lstnew(ft_nodenew(ft_atoi(str[1])));
	i = 2;
	while (str[i])
		ft_lstadd_back(&list, ft_lstnew(ft_nodenew(ft_atoi(str[i++]))));

	make_index(&list);

	return (list);
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
/*
	printf("-----------------\n");

	printf("Before mark :\n");
	print_content_list(A);
	print_mark_list(A);

	make_index(&A);
	make_mark(&A);

	printf("After mark :\n");
	print_content_list(A);
	print_mark_list(A);

	printf("-----------------\n");
*/ //print stack info
/*
	printf("After algoritm :\n");
	print_content_list(A);
	print_mark_list(A);

	printf("-----------------\n");
*/
}
