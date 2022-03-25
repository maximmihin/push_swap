/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:00:40 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 15:00:42 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sl(t_list **stack)
{
	t_list	*tmp;
	t_list	*s;

	s = *stack;
	if (!s && !s->next)
		return (1);
	tmp = s->next->next;
	s->next->next = *stack;
	*stack = s->next;
	s->next = tmp;
	return (0);
}

int	sa(t_list **stack_a, int print)
{
	sl(stack_a);
	if (print)
		write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b, int print)
{
	sl(stack_b);
	if (print)
		write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b, int print)
{
	sl(stack_a);
	sl(stack_b);
	if (print)
		write(1, "ss\n", 3);
	return (0);
}
