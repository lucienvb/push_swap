#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= push_swap
CC		:= cc
CFLAGS	?= -Wall -Wextra -Werror
#LDFLAGS	?= -fsanitize=address -g

SRC		:= \
	src/main.c \
	src/operations/ps_push.c \
	src/operations/ps_rotate.c \
	src/operations/ps_swap.c \
	src/sort/ps_radix_sort.c \
	src/sort/ps_sort.c \
	src/utils/ps_content_to_index.c \
	src/utils/ps_convert_and_check.c \
	src/utils/ps_free.c \
	src/utils/ps_push_low_to_b.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPES:		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(CC) $(LDFLAGS) $^ ./libft/libft.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C libft clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C libft fclean

re: fclean all

test:
		$(CC) $(CFLAGS) UnityExample.c libft/lists/list_reversed_sorted.o unity/libunity.a -o unittest
		@ ./unittest

.PHONY: all clean fclean re
