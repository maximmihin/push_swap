#include "push_swap.h"

t_list	*find_index(t_list *stack, unsigned int index)
{
	ps_node	*ps_tmp;

	while (stack)
	{
		ps_tmp = stack->content;
		if (ps_tmp->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*find_min_list(t_list *elem_one, t_list *elem_two)
{
	ps_node	*ps_a;
	ps_node	*ps_b;

	ps_a = (ps_node *)elem_one->content;
	ps_b = (ps_node *)elem_two->content;
	if (ps_a->index)
		return (elem_two);
	if (ps_b->index)
		return (elem_one);
	if (ps_a->content < ps_b->content)
		return (elem_one);
	else
		return (elem_two);
}

void	assign_index(t_list **stack, unsigned int index)
{
	t_list	*tmp_stack;

	tmp_stack = *stack;
	((ps_node *)tmp_stack->content)->index = index;
}

void	make_index(t_list **stack)
{
	t_list			*tmp;
	t_list			*min_lst;
	unsigned int	lst_len;
	unsigned int	index;

	tmp = *stack;
	min_lst = tmp;
	lst_len = ft_lstsize(tmp);
	index = 1;
	while (index <= lst_len)
	{
		while (tmp)
		{
			min_lst = find_min_list(min_lst, tmp);
			tmp = tmp->next;
		}
		assign_index(&min_lst, index);
		min_lst = find_index(*stack, 0);
		tmp = *stack;
		++index;
	}
}
