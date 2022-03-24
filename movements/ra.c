#include "../push_swap.h"

int	rl(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*s;

	s = *stack;
	tmp	= s->next;
	last = ft_lstlast(*stack);
	s->next = NULL;
	last->next = *stack;
	*stack = tmp;
	return (0);
}

int	ra(t_list **stack_a, int print)
{
	rl(stack_a);
	if (print)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack_b, int print)
{
	rl(stack_b);
	if (print)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b, int print)
{
	rl(stack_a);
	rl(stack_b);
	if (print)
		write(1, "rr\n", 3);
	return (0);
}
