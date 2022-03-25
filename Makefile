NAME = push_swap

NAME_B = checker_my

HEADER = includes/push_swap.h

HEADER_B = includes/checker.h

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
		src/push_swap.c

SRC_B = bonus/get_next_line_utils.c bonus/get_next_line.c \
		movements/pa.c movements/ra.c movements/rra.c movements/sa.c \
		src/parser.c src/check_argum.c src/make_index.c \
		bonus/checker.c

OBJ = $(SRC:%.c= %.o)

OBJ_B = $(SRC_B:%.c= %.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ) libft/libft.a -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B) $(HEADER_B)
	cd libft && make bonus && make
	$(CC) $(FLAGS) -O2 $(OBJ_B) libft/libft.a -o $(NAME_B)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	cd libft && make clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)

fclean	:	clean
	cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)

re	:	fclean all