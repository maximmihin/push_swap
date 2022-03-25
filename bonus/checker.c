/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:09:41 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/26 01:09:43 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	apply_command(t_list **stack_a, t_list **stack_b, char *moves)
{
	if (!ft_strncmp(moves, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(moves, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(moves, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(moves, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(moves, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(moves, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(moves, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(moves, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(moves, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(moves, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(moves, "pb\n", 3))
		pb(stack_a, stack_b, 0);
}

int	main(int argc, char **argv)
{
	char	*moves_line;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = parser(&argc, argv);
	if (!stack_a)
		return (0);
	while (1)
	{
		moves_line = get_next_line(0);
		if (!moves_line)
			break ;
		apply_command(&stack_a, &stack_b, moves_line);
		free(moves_line);
	}
	if (is_ascending(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
