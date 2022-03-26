/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:30:09 by gradagas          #+#    #+#             */
/*   Updated: 2022/03/25 14:30:12 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_non_numeric_symbols(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != NULL/* && str[i][j]*/)
	{
		if (!ft_strlen(str[i]))
			return (1);
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

size_t	ft_arrlen(void **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_double(char **str)
{
	size_t	len_arr;
	size_t	*nums;
	int		j;
	int		i;

	len_arr = ft_arrlen((void **)str);
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
		while (++j < (int)len_arr)
			if (nums[i] == nums[j] && !(ft_strncmp(str[i], str[j], nums[i])))
				return (1);
		i++;
		j = i;
	}
	free(nums);
	return (0);
}

int	check_max_min_int(char **str)
{
	size_t			len_str;
	long long int	nbr;
	char			**tmp_str;
	char			*sub_str;

	tmp_str = str;
	while (tmp_str && *tmp_str)
	{
		sub_str = *tmp_str;
		while (*sub_str == '0')
			sub_str++;
		len_str = ft_strlen(sub_str);
		if (len_str > 11)
			return (1);
		nbr = ft_atoll(sub_str);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		tmp_str++;
	}
	return (0);
}

void	check_argum(char **argv)
{
	if (check_non_numeric_symbols(argv)
		|| check_double(argv)
		|| check_max_min_int(argv))
	{
		write(2, "Error\n", 6);
		exit(9);
	}
}
