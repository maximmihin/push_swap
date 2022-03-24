NAME = push_swap

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = big_sort.c \
		movements/pa.c movements/ra.c movements/rra.c movements/sa.c \
		check_argum.c parser.c make_index.c \
		five_sort.c small_sort.c calculate_cost.c\
		size_desired_pool.c resize_desired_pool.c\
		init_desired_pool.c \
		recost_desired_pool_utils.c \
		first_step_utils.c second_step_utils.c\
		main.c

# SRC_B = bonus/get_next_line_utils.c bonus/get_next_line.h bonus/get_next_line.c \


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

#bonus	:
#	cd libft && make bonus && make



re	:	fclean all