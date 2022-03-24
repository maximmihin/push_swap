#include "../includes/push_swap.h"

/*
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
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1 || argc == 2)
		return (0);
	check_argum(argv);
	stack_a = parser(argv);
	if (argc < 7)
		return (small_sort(&stack_a, &stack_b, argc));
	return (big_sort(&stack_a, &stack_b));
}
