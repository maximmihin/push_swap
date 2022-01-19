#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//del
#include <stdio.h>

# include "libft/libft.h"

typedef struct ps_list
{
	int				content;
	unsigned int 	index;
	char			cs;
	struct ps_list	*next;
}	ps_list;



ps_list			*ft_ps_lstnew(int content);
void			ft_ps_lstadd_front(ps_list **lst, ps_list *new);
int				ft_ps_lstsize(ps_list *lst);
ps_list			*ft_ps_lstlast(ps_list *lst);
void			ft_ps_lstadd_back(ps_list **lst, ps_list *new);
void			ft_ps_lstdelone(ps_list *lst, void (*del)(int));
void			ft_ps_lstclear(ps_list **lst, void (*del)(int));




int sl(ps_list **S, char c);
int ss(ps_list **A, ps_list **B);

int rl(ps_list **S, char c);
int rr(ps_list **A, ps_list **B);

int rrl(ps_list **S, char c);
int rrr(ps_list **A, ps_list **B);

int pl(ps_list **A, ps_list **B, char c);
/*ыф
sb
ss

ra
rb
rr

rra
rrb
rrr

pa
pb
*/

#endif
