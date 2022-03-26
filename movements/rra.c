/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:00:31 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 15:00:32 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrl(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (ft_lstsize(tmp) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(stack, tmp->next);
		tmp->next = NULL;
	}
	return (0);
}

int	rra(t_list **stack_a, int print)
{
	rrl(stack_a);
	if (print)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b, int print)
{
	rrl(stack_b);
	if (print)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	rrl(stack_a);
	rrl(stack_b);
	if (print)
		write(1, "rrr\n", 4);
	return (0);
}
