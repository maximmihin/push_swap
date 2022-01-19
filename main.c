#include "push_swap.h"

void print_content_list(ps_list **S)
{
	ps_list *tmp;

	tmp = *S;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void print_index_list(ps_list **S)
{
	ps_list *tmp;

	tmp = *S;
	while (tmp)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
}

void make_index(ps_list **S)
{
	ps_list *tmp;
	int index;
	int min_num;

	tmp = *S;
	index = 1;
	min_num = tmp->content;

	while (tmp)
	{
		if (tmp->content < min_num && tmp->index == 0)
		{
			min_num = tmp->content;
			tmp->index = index;
		}
		tmp = tmp->next;
	}

}

int		main(int argc, char **argv)
{
	ps_list *A;
//	ps_list *B;
	int i;


	if (argc == 1)
	{
		printf("No one argument! Bye!\n");
		return (0);
	}

	A = ft_ps_lstnew(ft_atoi(argv[1]));

	i = 2;
	while (argv[i])
		ft_ps_lstadd_back(&A, ft_ps_lstnew(ft_atoi(argv[i++])));


	printf("Before sort :\n");
	print_content_list(&A);
	printf("\n");

	print_index_list(&A);
	printf("\n");

	//sort easy (test)



	//make markup (true || false)
















/*
	printf("Before : ");
	B = A;
	while (B)
	{
		printf("%s ", (char *)B->content);
		B = B->next;
	}

	s(&A, 'a');

	printf("\nAfter  : ");
	print_list(&A);
	printf("\n------------------\n");
*/
//sl, rl, rrl tests
/*
	printf("Before : ");
	print_list(&A);
	rrl(&A, 'a');
	printf("\nAfter  : ");
	print_list(&A);
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
