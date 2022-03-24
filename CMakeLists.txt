cmake_minimum_required(VERSION 3.19.2)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)
include_directories(src)

add_executable(push_swap src/big_sort.c
        src/main.c includes/push_swap.h
        libft/libft.a libft/ft_lstnew.c
        libft/ft_lstadd_back.c libft/ft_lstlast.c
        libft/ft_lstadd_front.c libft/ft_lstsize.c
        libft/ft_putchar_fd.c libft/ft_putstr_fd.c
        libft/ft_atoi.c libft/ft_isdigit.c
        libft/ft_strlen.c libft/ft_strncmp.c
        libft/ft_lstdelone.c libft/ft_lstclear.c
        libft/ft_itoa.c libft/ft_strjoin.c
        libft/ft_strlcpy.c libft/ft_split.c
        libft/ft_bzero.c libft/ft_memcpy.c
        libft/ft_strchr.c libft/ft_substr.c
        libft/ft_atoll.c
        bonus/get_next_line.c
        src/five_sort.c src/small_sort.c src/init_desired_pool.c src/calculate_cost.c src/size_desired_pool.c src/resize_desired_pool.c src/recost_desired_pool_utils.c src/first_step_utils.c src/parser.c src/second_step_utils.c
        movements/pa.c movements/ra.c movements/rra.c movements/sa.c src/make_index.c
        src/check_argum.c includes/movements.h)
