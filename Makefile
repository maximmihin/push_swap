NAME = push_swap

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = utils/push_swap_utils.c main.c

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