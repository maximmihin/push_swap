NAME = push_swap

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = utils/push_swap_utils.c \
		movements/pa.c movements/ra.c movements/rra.c movements/sa.c \
		parser.c \
		five_sort.c small_sort.c calculate_cost.c\
		size_desired_pool.c resize_desired_pool.c\
		init_desired_pool.c \
		recost_desired_pool_utils.c \
		big_sort_key.c \
		main.c

OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	cd libft && make bonus && make
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
#	cd libft && make clean
	@rm -f $(OBJ)

fclean	:	clean
#	cd libft && make fclean
	@$(RM) $(NAME)

re	:	fclean all