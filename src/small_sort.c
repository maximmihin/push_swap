/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:37 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 14:58:39 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	three_sort(t_list **stack)
{
	int				val[3];
	unsigned int	i;
	t_list			*list_tmp;

	list_tmp = *stack;
	i = 0;
	while (i < 3)
	{
		val[i] = (((t_node *)list_tmp->content)->content);
		list_tmp = list_tmp->next;
		i++;
	}
	if (val[0] > val[1] && val[0] < val[2] && val[1] < val [2])
		return (sa(stack, 1));
	if (val[0] > val[1] && val[0] > val[2] && val[1] > val[2])
		return (sa(stack, 1) + rra(stack, 1));
	if (val[0] > val[1] && val[0] > val[2] && val[1] < val[2])
		return (ra(stack, 1));
	if (val[0] < val[1] && val[0] < val[2] && val[1] > val[2])
		return (sa(stack, 1) + ra(stack, 1));
	if (val[0] < val[1] && val[0] > val[2] && val[1] > val[2])
		return (rra(stack, 1));
	return (1);
}

int	four_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_list;

	pb(stack_a, stack_b, 1);
	three_sort(stack_a);
	tmp_list = *stack_b;
	if (((t_node *)tmp_list->content)->index == 2)
		return (pa(stack_a, stack_b, 1) + sa(stack_a, 1));
	if (((t_node *)tmp_list->content)->index == 3)
		return (rra(stack_a, 1) + pa(stack_a, stack_b, 1)
			+ ra(stack_a, 1) + ra(stack_a, 1));
	if (((t_node *)tmp_list->content)->index == 4)
		return (pa(stack_a, stack_b, 1) + ra(stack_a, 1));
	return (pa(stack_a, stack_b, 1));
}

int	small_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*list_tmp;

	list_tmp = *stack_a;
	if (argc == 3)
		if (((t_node *)list_tmp->content)->content
			> ((t_node *)list_tmp->next->content)->content)
			sa(stack_a, 1);
	if (argc == 4)
		three_sort(stack_a);
	if (argc == 5)
		four_sort(stack_a, stack_b);
	if (argc == 6)
		five_sort(stack_a, stack_b);
	ft_lstclear(stack_a, free);
	return (0);
}
