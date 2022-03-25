#include "includes/push_swap.h"
#include "includes/get_next_line.h"

void	apply_commands(t_list **stack_a, t_list **stack_b, char ***moves)
{
	char	**tmp_moves;
	int		i;

	tmp_moves = *moves;
	i = 0;

	while (moves[i])
	{
		if (!ft_strncmp(tmp_moves[i], "sa\0", 3))
			sa(stack_a, 0);
		else if (!ft_strncmp(tmp_moves[i], "sb\0", 3))
			sb(stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "ss\0", 3))
			ss(stack_a, stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "ra\0", 3))
			ra(stack_a, 0);
		else if (!ft_strncmp(tmp_moves[i], "rb\0", 3))
			rb(stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "rr\0", 3))
			rr(stack_a, stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "rra\0", 4))
			rra(stack_a, 0);
		else if (!ft_strncmp(tmp_moves[i], "rrb\0", 4))
			rrb(stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "rrr\0", 4))
			rrr(stack_a, stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "pa\0", 3))
			pa(stack_a, stack_b, 0);
		else if (!ft_strncmp(tmp_moves[i], "pb\0", 3))
			pb(stack_a, stack_b, 0);
		i++;
	}
}

int	main (int argc, char **argv)
{
	char	*moves_line;
	char	*all_moves;
	char	**moves;
	char	*tmp;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);

	while (moves_line != 0)
	{
		moves_line = get_next_line(1);
		if (!moves_line)
			return (0);
		tmp = all_moves;
		all_moves = ft_strjoin(all_moves, moves_line);
		free (tmp);
	}

	moves = ft_split(all_moves, '\n');
	stack_a = parser(argv);
	//обработать ошибку
	apply_commands(&stack_a, &stack_b, &moves);
	if (is_ascending(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	return (0);
}