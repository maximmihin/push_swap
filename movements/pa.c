/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:00:12 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 15:00:13 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pl(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*b;

	b = *stack_b;
	if (b->next)
		tmp = b->next;
	else
		tmp = NULL;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b, int print)
{
	pl(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b, int print)
{
	pl(stack_b, stack_a);
	if (print)
		write(1, "pb\n", 3);
	return (0);
}
