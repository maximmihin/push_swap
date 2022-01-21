#include "push_swap.h"

void print_content_list(t_list *S)
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

void print_index_list(t_list *S)
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

void f_make_index(t_list **S)
{
	t_list *tmp;
	ps_node *ps_tmp;
	ps_node *min_node;
	unsigned int lst_len;
	int index;
	int min_num;

	tmp = *S;
	index = 1;
	ps_tmp = tmp->content;
	min_num = ps_tmp->content;
	lst_len = ft_lstsize(*S);

	index_bzero(S);
	//printf("BP 1\n");
	while (lst_len)
	{
		while (tmp)
		{
			ps_tmp = tmp->content;
			if (ps_tmp->content <= min_num && ps_tmp->index == 0)
			{
				min_node = tmp->content;
				//printf("BP 3\n");
			}
			tmp = tmp->next;
			//printf("BP 2\n");
		}
		min_node->index = index;
		tmp = find_index(&tmp, 0);
		min_node = tmp->content;
		min_num = min_node->content;
		index++;
		tmp = *S;
		lst_len--;
		//printf("BP 4\n");
	}
}

void s_make_index(t_list **S)
{
	t_list			*tmp;
	ps_node			*ps_tmp;
	ps_node			*min_node;
	unsigned int	lenlst;
	unsigned int	index;
	int				min_num;

	tmp = *S;
	ps_tmp = tmp->content;
	lenlst = ft_lstsize(*S);
	index = 1;
	min_num = ps_tmp->content;
	index_bzero(S);

	while (lenlst)
	{
		while (tmp)
		{
			ps_tmp = tmp->content;
			if (ps_tmp->content <= min_num && ps_tmp->index == 0)
			{
				min_node = ps_tmp;
				min_num = ps_tmp->content;
			}
			tmp = tmp->next;
		}
		lenlst--;

		min_node->index = index;
		tmp = find_index(S, 0);
		if (!tmp)
			break;
		ps_tmp = tmp->content;
		min_num = ps_tmp->content;
		tmp = *S;
		index++;
	}
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

	printf("Before index :\n");
	print_content_list(A);
	print_index_list(A);

	s_make_index(&A);

	printf("After index :\n");
	print_content_list(A);
	print_index_list(A);


/*
	B = find_index(&A, 2);
	ps_node *rrr = B->content;
	printf("\ncontent = %d\nindex   = %d\n", rrr->content, rrr->index);
*/

/*
	index_bzero(&A);
	printf("After indexbzero :\n");
	print_content_list(A);
	print_index_list(A);
*/
	//sort easy (test)



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
