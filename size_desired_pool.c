#include "push_swap.h"

unsigned int		find_num_pool_nodes(unsigned int len_stack)
{
	unsigned int	perfect_len;
	unsigned int 	deep;

	deep = 7;
	if (len_stack < 100)
		return (4);
	perfect_len = len_stack / deep;
	if (perfect_len % 2)
		perfect_len -= 1;
	return (perfect_len);
}

unsigned int		find_perfect_len_desired_pool(unsigned int stack_size,
												  unsigned int num_pool_node)
{
	unsigned int	fact_deep;
	double			perfect_len;

	fact_deep = stack_size / num_pool_node;
	if (fact_deep % 2)
		fact_deep--;
	perfect_len = fact_deep;
	perfect_len += (perfect_len / 100) * (0.7 * stack_size);
	return (perfect_len);
}

int					is_resize_need(unsigned int stack_size,
									  unsigned int num_pool_nodes)
{
	size_t	perfect_len;

	if (num_pool_nodes == 2)
		return (0);
	perfect_len = find_perfect_len_desired_pool(stack_size, num_pool_nodes);
	if (perfect_len < num_pool_nodes && !(perfect_len % 2))
		return (1);
	return (0);
}
