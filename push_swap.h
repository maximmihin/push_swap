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

int sa(t_list **stack_a, int print);
int sb(t_list **stack_b, int print);
int ss(t_list **stack_a, t_list **stack_b, int print);

int ra(t_list **stack_a, int print);
int rb(t_list **stack_b, int print);
int rr(t_list **stack_a, t_list **stack_b, int print);

int rra(t_list **stack_a, int print);
int rrb(t_list **stack_b, int print);
int rrr(t_list **stack_a, t_list **stack_b, int print);

int	pa(t_list **stack_a, t_list **stack_b, int print);
int pb(t_list **stack_a, t_list **stack_b, int print);

void	check_argum(char **str);
void	make_index(t_list **stack);


t_list			*init_desired_pool(unsigned int num_pool_nodes);

void			index_desired_pool_for_a(t_list **desired_pool,
										 unsigned int num_pool_nodes,
										 unsigned int stack_size);


void				calculate_all_costs(t_list **desired_pool, t_list *stack,
										unsigned int stack_size);

unsigned int		find_cost_node(t_list **desired_pool, t_list *stack,
								   size_t stack_size);


unsigned int		find_num_pool_nodes(unsigned int len_stack);

int					is_resize_need(unsigned int stack_size,
									  unsigned int num_pool_nodes);

int				resize_desired_pool(t_list **desired_pool,
									   unsigned int num_pool_nodes);


unsigned int		find_next_top(t_list *desired_pool);

unsigned int		find_next_bottom(t_list *desired_pool);

void				del_pool_node(t_list **desired_pool, t_list **node_to_del);

int					del_waste_pool_node(t_list **desired_pool,
										   unsigned int waste_index);

t_list				*find_used_pool_node(t_list **desired_pool);

t_element_to_move	choose_next_elem_second_step(t_list *stack_b,
												  unsigned int stack_size,
												  t_list **desired_pool);

void				recost_desired_pool(t_list **desired_pool, t_list *stack_a,
										unsigned int stack_size);

void				move_to_b(t_list **st_a, t_list **st_b,
							  t_element_to_move next_elem);




t_element_to_move	choose_next_elem_first_step(t_list **desired_pool);

void	index_desired_pool_for_b(t_list **desired_pool, t_list *stack_a);
void	move_to_a(t_list **A, t_list **B, t_element_to_move next_elem);


t_list	*parser(char **str);




int	three_sort(t_list **S);
int	five_sort(t_list **stack_a, t_list **stack_b);
int	small_sort(t_list **stack_a, t_list **stack_b, int argc);

int big_sort(t_list **stack_a, t_list **stack_b);



void	print_index_list(t_list *S);
void	print_content_list(t_list *S);
void	print_two_stack(t_list *A, t_list *B);


#endif
