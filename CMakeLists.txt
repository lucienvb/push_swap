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
        src/utils/ps_error_check.c
        src/utils/ps_lists.c
        src/utils/ps_num_to_index.c
        src/utils/ps_utils_1.c
        src/utils/ps_utils_2.c
        src/main.c)

find_library(FT_PRINTF libftprintf.a ft_printf)
target_link_libraries(push_swap LINK_PUBLIC ${FT_PRINTF})
find_library(LIBFT libft.a libft)
target_link_libraries(push_swap LINK_PUBLIC ${LIBFT})
