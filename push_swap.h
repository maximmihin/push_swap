#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//del
#include <stdio.h>

# include "libft/libft.h"

typedef struct ps_node
{
	int				content;
	unsigned int 	index;
	unsigned int	stack_index;
	char			mark;
}	ps_node;

typedef struct key_points
{
	unsigned int	min_index;
	unsigned int	min_cost;
	unsigned int	max_index;
	unsigned int	max_cost;
}	key_points;

ps_node	*ft_nodenew(int content);

int sl(t_list **S, char c);
int sa(t_list **S);
int sb(t_list **S);
int ss(t_list **A, t_list **B);

int rl(t_list **S, char c);
int ra(t_list **S);
int rb(t_list **S);
int rr(t_list **A, t_list **B);

int rrl(t_list **S, char c);
int rra(t_list **S);
int rrb(t_list **S);
int rrr(t_list **A, t_list **B);

int pl(t_list **A, t_list **B, char c);

int	pa(t_list **A, t_list **B);
int pb(t_list **A, t_list **B);


#endif
