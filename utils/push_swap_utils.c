#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

ps_node	*ft_nodenew(int content)
{
	ps_node *elem;

	elem = (ps_node *) malloc(sizeof(ps_node));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = 0;
	elem->mark = 'F';
	return (elem);
}


int sl(t_list **S, char c)
{
	t_list *tmp;
	t_list *s;

	if (!*S)
	{
		ft_putstr_fd("error s : invalid A || B", 1);
		return (1);
	}


	s = *S;

	tmp = s->next->next;
	s->next->next = *S;
	*S = s->next;
	s->next = tmp;

	if (c == 88)
		ft_putchar_fd('r', 1);
/*
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
*/
	return (0);
}

int ss(t_list **A, t_list **B)
{
	sl(A, 'a');
	sl(B, 'b');

	return (0);
}

int rl(t_list **S, char c)
{
	t_list *last;
	t_list *tmp;
	t_list *s;

	s = *S;

	tmp	= s->next;
	last = ft_lstlast(*S);
	s->next = NULL;
	last->next = *S;
	*S = tmp;

	if (c == 88)
		ft_putchar_fd('r', 1);

/*
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
*/
	return (0);
}

int rr(t_list **A, t_list **B)
{
	rl(A, 'a');
	rl(B, 'b');

	return (0);
}

int rrl(t_list **S, char c)
{
	t_list *tmp;

	tmp = *S;
	while(tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(S, tmp->next);
	tmp->next = NULL;

	if (c == 88)
		ft_putchar_fd('r', 1);
/*
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
*/


	return (0);
}

int rrr(t_list **A, t_list **B)
{
	rrl(A, 'a');
	rrl(B, 'b');

	return (0);
}

int pl(t_list **A, t_list **B, char c)
{
	t_list *tmp;
	t_list *b;

	b = *B;
	if (b->next)
		tmp = b->next;
	else
		tmp = NULL;
	ft_lstadd_front(A, b);
	*B = tmp;

	if (c == 88)
		ft_putchar_fd('r', 1);
/*
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("WTF?!", 1);
*/
	return (0);
}

int	pa(t_list **A, t_list **B)
{
	pl(A, B, 'a');
	return (0);
}

int pb(t_list **A, t_list **B)
{
	pl(B, A, 'b');
	return (0);
}
