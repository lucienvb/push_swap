cmake_minimum_required(VERSION 3.23.2)

project(push_swap)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
# can add -fsanitize=address up here
set(CMAKE_LINKER_FLAGS)
include_directories( ${incl})

add_executable(push_swap
        src/operations/ps_push.c
        src/operations/ps_rotate.c
        src/operations/ps_swap.c
        src/sort/ps_radix_sort.c
        src/sort/ps_sort.c
        src/utils/ps_convert_and_check.c
        src/utils/ps_free.c
        src/utils/ps_content_to_index.c
        src/utils/ps_push_low_to_b.c
        src/main.c)

find_library(libft/ft_printf libftprintf.a libft/ft_printf)
target_link_libraries(push_swap LINK_PUBLIC ${FT_PRINTF})
find_library(LIBFT libft.a libft)
target_link_libraries(push_swap LINK_PUBLIC ${LIBFT})
