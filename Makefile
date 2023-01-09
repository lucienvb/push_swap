#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= push_swap
CC		:= cc
CFLAGS	?= -Wall -Wextra -Werror -g

SRC		:= \
	push_swap.c \
	ps_error_check.c \
	ps_lists.c \
	ps_push.c \
	ps_swap.c \
	ps_rotate.c \
	ps_sort.c \
	ps_num_to_index.c \
	ps_utils_1.c \
	ps_utils_2.c \
	ps_radix_sort.c

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
