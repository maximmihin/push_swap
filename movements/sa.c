#include "../push_swap.h"

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

int	sa(t_list **stack_a)
{
	sl(stack_a);
	write(1, "sa\n", 3);
	return (0);
}

int sb(t_list **stack_b)
{
	sl(stack_b);
	write(1, "sb\n", 3);
	return (0);
}

int ss(t_list **stack_a, t_list **stack_b)
{
	sl(stack_a);
	sl(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
