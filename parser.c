#include "push_swap.h"

ps_node	*ft_nodenew(int content)
{
	ps_node	*elem;

	elem = (ps_node *) malloc(sizeof(ps_node));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = 0;
	elem->mark = 'F';
	return (elem);
}

t_list	*parser(char **str)
{
	t_list			*list;
	t_list			*tmp_list;
	ps_node			*node;
	unsigned int	i;

	node = ft_nodenew(ft_atoi(str[1]));
	if (!node)
		return (NULL);
	list = ft_lstnew(node);
	if (!list)
		return (NULL);
	i = 2;
	while (str[i])
	{
		node = ft_nodenew(ft_atoi(str[i]));
		if (!node)
			return (NULL);
		tmp_list = ft_lstnew(node);
		if (!tmp_list)
			return (NULL);
		ft_lstadd_back(&list, tmp_list);
		i++;
	}
	make_index(&list);
	return (list);
}
