#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//del
#include <stdio.h>

# include "libft/libft.h"

typedef struct ps_node
{
	int				content;
	unsigned int 	index;
	char			mark;
}	ps_node;

ps_node	*ft_nodenew(int content);

int sl(t_list **S, char c);
int ss(t_list **A, t_list **B);

int rl(t_list **S, char c);
int rr(t_list **A, t_list **B);

int rrl(t_list **S, char c);
int rrr(t_list **A, t_list **B);

int pl(t_list **A, t_list **B, char c);

int	pa(t_list **A, t_list **B);
int pb(t_list **A, t_list **B);


#endif
