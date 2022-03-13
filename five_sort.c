#include "push_swap.h"

unsigned int	find_min_index(t_list *stack_a)
{
	unsigned int min_index;

	min_index = ((ps_node *)stack_a->content)->index;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (((ps_node *)stack_a->content)->index < min_index)
			min_index = ((ps_node *)stack_a->content)->index;
		stack_a = stack_a->next;
	}
	return (min_index);
}

void			cancel_delta(t_list **stack_a, unsigned int delta)
{
	t_list	*tmp_list;

	tmp_list = *stack_a;
	while (tmp_list)
	{
		((ps_node *)tmp_list->content)->index += delta;
		tmp_list = tmp_list->next;
	}
}

void			five_sort_cases(t_list **stack_b, t_list **tmp_list)
{
	t_list	*tmp_loc;

	tmp_loc = *tmp_list;
	pa (&tmp_loc, stack_b);
	if (((ps_node *)tmp_loc->content)->index == 5)
		ra(&tmp_loc);
	pa (&tmp_loc, stack_b);
	if (((ps_node *)tmp_loc->content)->index == 5)
		ra(&tmp_loc);
	if (((ps_node *)tmp_loc->content)->index == 2)
		sa(&tmp_loc);
}

int				five_sort(t_list **stack_a, t_list **stack_b)
{
	t_list			*tmp_list;
	unsigned int	len_stack;
	unsigned int	delta;

	tmp_list = *stack_a;
	len_stack = 5;
	delta = find_min_index(tmp_list) - 1;
	while (len_stack > 3)
		if (((ps_node *)tmp_list->content)->index != 3
			&& ((ps_node *)tmp_list->content)->index != 4)
		{
			pb(&tmp_list, stack_b);
			len_stack--;
		}
		else
			ra(&tmp_list);
	three_sort(&tmp_list);
	five_sort_cases(stack_b, &tmp_list);
	cancel_delta(&tmp_list, delta);
	*stack_a = tmp_list;
	return (0);
}
