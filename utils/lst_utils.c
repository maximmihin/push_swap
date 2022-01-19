#include "../libft/libft.h"
#include "../push_swap.h"

ps_list			*ft_ps_lstnew(int content)
{
	ps_list	*elem;

	elem = (ps_list *) malloc(sizeof(ps_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = 0;
	elem->cs = 0;
	elem->next = NULL;
	return (elem);
}

void			ft_ps_lstadd_front(ps_list **lst, ps_list *new)
{
	new->next = *lst;
	*lst = new;
}

int				ft_ps_lstsize(ps_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst && lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

ps_list			*ft_ps_lstlast(ps_list *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void			ft_ps_lstadd_back(ps_list **lst, ps_list *new)
{
	ps_list	*ptr;

	ptr = *lst;
	if (!ptr)
	{
		*lst = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void			ft_ps_lstdelone(ps_list *lst, void (*del)(int))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void			ft_ps_lstclear(ps_list **lst, void (*del)(int))
{
	ps_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_ps_lstdelone(*lst, del);
		(*lst) = temp;
	}
}
