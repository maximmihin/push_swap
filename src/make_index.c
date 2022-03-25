/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:29:14 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 14:29:17 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_index(t_list *stack, unsigned int index)
{
	t_node	*ps_tmp;

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
	t_node	*ps_a;
	t_node	*ps_b;

	ps_a = (t_node *)elem_one->content;
	ps_b = (t_node *)elem_two->content;
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
	((t_node *)tmp_stack->content)->index = index;
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
