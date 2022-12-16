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
	ps_heapsort.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(CC) $^ ./libft/libft.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
