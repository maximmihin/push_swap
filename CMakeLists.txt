cmake_minimum_required(VERSION 3.19.2)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)
include_directories(utils)

add_executable(push_swap utils/push_swap_utils.c
        main.c push_swap.h
        libft/libft.a libft/ft_lstnew.c
        libft/ft_lstadd_back.c libft/ft_lstlast.c
        libft/ft_lstadd_front.c libft/ft_lstsize.c
        libft/ft_putchar_fd.c libft/ft_putstr_fd.c
        libft/ft_atoi.c libft/ft_isdigit.c
        libft/ft_strlen.c libft/ft_strncmp.c
        libft/ft_lstdelone.c libft/ft_lstclear.c
        libft/ft_itoa.c libft/ft_strjoin.c
        libft/ft_strlcpy.c
        ss.c five_sort.c small_sort.c init_desired_pool.c calculate_cost.c size_desired_pool.c resize_desired_pool.c recost_desired_pool_utils.c big_sort_key.c checker.c parser.c)
