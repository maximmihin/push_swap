#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//del
#include <stdio.h>

# include "libft/libft.h"

typedef struct ps_node
{
	char			min_max;
	int				content;
	unsigned int 	index;
	unsigned int	stack_index;
	char			mark;
	char			del;
}	ps_node;

typedef struct s_pool_node
{
	char			bottom_top;
	unsigned int	index;
	unsigned int	pos;
	char			gate;
	unsigned int	cost;
}	t_pool_node;

typedef struct s_element_to_move
{
	char			min_max;
	unsigned int	index;
	char		 	gate;
	unsigned int 	cost;
	unsigned int 	index_next;
	char 			gate_next;
}	t_element_to_move;




ps_node	*ft_nodenew(int content);

int sa(t_list **S);
int sb(t_list **S);
int ss(t_list **A, t_list **B);

int ra(t_list **S);
int rb(t_list **S);
int rr(t_list **A, t_list **B);

int rra(t_list **S);
int rrb(t_list **S);
int rrr(t_list **A, t_list **B);

int	pa(t_list **A, t_list **B);
int pb(t_list **A, t_list **B);


void	make_index(t_list **S);

int	three_sort(t_list **S);
int	five_sort(t_list **A, t_list **B);
int	small_sort(t_list **A, t_list **B, int argc);

int big_sort(t_list **A, t_list **B);



void	print_index_list(t_list *S);
void	print_two_stack(t_list *A, t_list *B);

int		is_ascending(t_list *S);

#endif
