NAME = push_swap

HEADER = includes/push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = src/big_sort.c \
		movements/pa.c movements/ra.c movements/rra.c movements/sa.c \
		src/check_argum.c src/parser.c src/make_index.c \
		src/five_sort.c src/small_sort.c src/calculate_cost.c\
		src/size_desired_pool.c src/resize_desired_pool.c\
		src/init_desired_pool.c \
		src/recost_desired_pool_utils.c \
		src/first_step_utils.c src/second_step_utils.c\
		src/main.c

# SRC_B = bonus/get_next_line_utils.c bonus/get_next_line.h bonus/get_next_line.c \


OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
#	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ) libft/libft.a -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	cd libft && make clean
	@rm -f $(OBJ)

fclean	:	clean
#	cd libft && make fclean
	@$(RM) $(NAME)

#bonus	:
#	cd libft && make bonus && make



re	:	fclean all