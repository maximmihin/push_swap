#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

int sl(ps_list **S, char c)
{
	ps_list *tmp;
	ps_list *s;

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

int ss(ps_list **A, ps_list **B)
{
	sl(A, 'a');
	sl(B, 'b');

	return (0);
}

int rl(ps_list **S, char c)
{
	ps_list *last;
	ps_list *tmp;
	ps_list *s;

	s = *S;

	tmp	= s->next;
	last = ft_ps_lstlast(*S);
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

int rr(ps_list **A, ps_list **B)
{
	rl(A, 'a');
	rl(B, 'b');

	return (0);
}

int rrl(ps_list **S, char c)
{
	ps_list *tmp;
	ps_list *s;

	s = *S;
	tmp = *S;
	while(tmp->next->next)
		tmp = tmp->next;
	ft_ps_lstadd_front(S, tmp->next);
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

int rrr(ps_list **A, ps_list **B)
{
	rrl(A, 'a');
	rrl(B, 'b');

	return (0);
}

int pl(ps_list **A, ps_list **B, char c)
{
	ps_list *tmp;
	ps_list *b;

	b = *B;
	tmp = b->next;
	ft_ps_lstadd_front(A, b);
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
