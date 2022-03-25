/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:29:53 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 14:29:55 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_nodenew(int content)
{
	t_node	*elem;

	elem = (t_node *) malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = 0;
	return (elem);
}

t_list	*arr_to_list(char **argum)
{
	t_list			*list;
	t_list			*tmp_list;
	t_node			*node;
	unsigned int	i;

	node = ft_nodenew(ft_atoi(argum[0]));
	if (!node)
		return (NULL);
	list = ft_lstnew(node);
	if (!list)
		return (NULL);
	i = 1;
	while (argum[i])
	{
		node = ft_nodenew(ft_atoi(argum[i]));
		if (!node)
			return (NULL);
		tmp_list = ft_lstnew(node);
		if (!tmp_list)
			return (NULL);
		ft_lstadd_back(&list, tmp_list);
		i++;
	}
	return (list);
}

void	free_argum(char **argum)
{
	int	i;

	i = 0;
	while (argum[i])
	{
		free(argum[i]);
		i++;
	}
	free(argum);
}

t_list	*parser(int argc, char **argv)
{
	t_list	*stack;
	char	**argum;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		argum = ft_split(argv[1], ' ');
		check_argum(argum);
		stack = arr_to_list(argum);
		free_argum(argum);
	}
	else
	{
		check_argum(&argv[1]);
		stack = arr_to_list(&argv[1]);
	}
	make_index(&stack);
	return (stack);
}

int	is_ascending(t_list *stack)
{
	t_node			*ps_tmp;
	unsigned int	index_tmp;

	ps_tmp = (t_node *)stack->content;
	index_tmp = ps_tmp->index;
	stack = stack->next;
	while (stack)
	{
		ps_tmp = (t_node *)stack->content;
		if (index_tmp + 1 != ps_tmp->index)
			return (0);
		index_tmp = ps_tmp->index;
		stack = stack->next;
	}
	return (1);
}
