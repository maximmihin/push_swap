cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)
include_directories(test)

add_executable(push_swap utils/push_swap_utils.c
        main.c push_swap.h
        libft/libft.a libft/ft_lstnew.c
        libft/ft_lstadd_back.c libft/ft_lstlast.c
        libft/ft_putchar_fd.c libft/ft_putstr_fd.c
        utils/lst_utils.c)
