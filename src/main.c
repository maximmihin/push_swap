/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:28 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 14:58:30 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = parser(&argc, argv);
	if (!stack_a)
		return (0);
	if (is_ascending(stack_a))
		return (0);
	if (argc < 7)
		small_sort(&stack_a, &stack_b, argc);
	else
		big_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
