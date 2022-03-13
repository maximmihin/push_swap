#include "push_swap.h"

int		check_non_numeric_symbols(char **str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (str[i] && str[i][j])
	{
		while (str[i][j])
		{
			if (!(str[i][j] == '-' || ft_isdigit(str[i][j])))
				return (1);
			++j;
		}
		++i;
		j = 0;
	}
	return (0);
}

size_t	ft_arrlen(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		check_double(char **str)
{
	size_t len_arr;
	size_t *nums;
	int i;
	size_t j;

	len_arr = ft_arrlen(str);
	nums = (size_t *) malloc(sizeof(size_t) * (len_arr + 1));
	if (!nums)
		return (1);
	i = -1;
	while (++i < (int)len_arr)
		nums[i] = ft_strlen(str[i]);
	i = 0;
	j = 0;
	while (i < (int)len_arr)
	{
		while (++j < len_arr)
			if (nums[i] == nums[j] && !(ft_strncmp(str[i], str[j], nums[i])))
				return (1);
		i++;
		j = i;
	}
	free(nums);
	return (0);
}

void 	bzero_del(t_list **list)
{
	t_list	*tmp_list;

	tmp_list = *list;

	while (tmp_list)
	{
		((ps_node *)tmp_list->content)->del = 'N';
		tmp_list = tmp_list->next;
	}
}

t_list	*parser(char **str)
{
	t_list	*list;
	size_t	i;

	if (check_non_numeric_symbols(str))
	{
		printf("find non-numeric symbols\n");
		return (NULL);
	}

	if (check_double(str))
	{
		printf("find doubles\n");
		return (NULL);
	}

	///make list
	list = ft_lstnew(ft_nodenew(ft_atoi(str[1])));
	i = 2;
	while (str[i])
		ft_lstadd_back(&list, ft_lstnew(ft_nodenew(ft_atoi(str[i++]))));

	make_index(&list);
	bzero_del(&list);

	return (list);
}