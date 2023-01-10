#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= push_swap
CC		:= cc
CFLAGS	?= -Wall -Wextra -Werror -g

SRC		:= \
	src/main.c \
	src/operations/ps_push.c \
	src/operations/ps_rotate.c \
	src/operations/ps_swap.c \
	src/sort/ps_radix_sort.c \
	src/sort/ps_sort.c \
	src/utils/ps_error_check.c \
	src/utils/ps_lists.c \
	src/utils/ps_num_to_index.c \
	src/utils/ps_utils_1.c \
	src/utils/ps_utils_2.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(MAKE) -C ./ft_printf
		$(CC) $^ ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./ft_printf clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
