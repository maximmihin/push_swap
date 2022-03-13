#include "push_swap.h"

int				three_sort(t_list **stack)
{
	int				val[3];
	unsigned int	i;
	t_list 			*list_tmp;

	list_tmp = *stack;
	i = 0;
	while (i < 3)
	{
		val[i] = (((ps_node *)list_tmp->content)->content);
		list_tmp = list_tmp->next;
		i++;
	}
	if (val[0] > val[1] && val[0] < val[2] && val[1] < val [2])
		return (sa(stack));
	if (val[0] > val[1] && val[0] > val[2] && val[1] > val[2])
		return (sa(stack) +	rra(stack));
	if (val[0] > val[1] && val[0] > val[2] && val[1] < val[2])
		return (ra(stack));
	if (val[0] < val[1] && val[0] < val[2] && val[1] > val[2])
		return (sa(stack) + ra(stack));
	if (val[0] < val[1] && val[0] > val[2] && val[1] > val[2])
		return (rra(stack));
	return (1);
}

int				four_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_list;

	make_index(stack_a);
	pb(stack_a, stack_b);
	three_sort(stack_a);
	tmp_list = *stack_b;
	if (((ps_node *)tmp_list->content)->index == 2)
		return (pa(stack_a, stack_b) + sa(stack_a));
	if (((ps_node *)tmp_list->content)->index == 3)
		return (rra(stack_a) + pa(stack_a, stack_b) + ra(stack_a) + ra(stack_a));
	if (((ps_node *)tmp_list->content)->index == 4)
		return (pa(stack_a, stack_b) + ra(stack_a));
	return (pa(stack_a, stack_b));
}

int				small_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*list_tmp;

	list_tmp = *stack_a;
	if (argc == 3)
		if (((ps_node *)list_tmp->content)->content
			> ((ps_node *)list_tmp->next->content)->content)
			return (sa(&list_tmp));
	if (argc == 4)
		return (three_sort(&list_tmp));
	if (argc == 5)
		return (four_sort(stack_a, stack_b));
	if (argc == 6)
		return (five_sort(stack_a, stack_b));
	return (0);
}