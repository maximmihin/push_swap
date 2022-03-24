#ifndef PUSH_SWAP_MOVEMENTS_H
# define PUSH_SWAP_MOVEMENTS_H

# include "../libft/libft.h"

int sa(t_list **stack_a, int print);
int sb(t_list **stack_b, int print);
int ss(t_list **stack_a, t_list **stack_b, int print);

int ra(t_list **stack_a, int print);
int rb(t_list **stack_b, int print);
int rr(t_list **stack_a, t_list **stack_b, int print);

int rra(t_list **stack_a, int print);
int rrb(t_list **stack_b, int print);
int rrr(t_list **stack_a, t_list **stack_b, int print);

int	pa(t_list **stack_a, t_list **stack_b, int print);
int pb(t_list **stack_a, t_list **stack_b, int print);

#endif
