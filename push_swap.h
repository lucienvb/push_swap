/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/12 09:41:47 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDE
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

// STRUCTURES
typedef struct node
{
	int				content;
	int				index;
	int				size;
	struct node		*next;
}					t_node;

// ENUM
enum e_stack_number {one = 1, two = 2, three = 3, four = 4, five = 5, six = 6};

// PUSH_SWAP -- ALGORITHM
void	ps_radix_sort(t_node **stack_a, t_node **stack_b);

// PUSH_SWAP -- ERROR CHECK
char	**convert_and_check(int argc, char **argv, int two_args);

// PUSH_SWAP -- LINKED LIST FUNCTIONS
int		add_back(t_node **head, int content);
void	clear_list(t_node *stack_a, t_node *stack_b);
t_node	*list_last(t_node *stack);
int		list_size(t_node *stack);
t_node	*new_list(t_node *stack, char **argv);

// PUSH_SWAP -- OPERATIONS: PUSH, ROTATE & SWAP
void	push(t_node **stack_a, t_node **stack_b, char c);
void	rot(t_node **stack, char c);
void	rev_rot(t_node **stack, char c);
void	swap(t_node **head, char c);

// PUSH_SWAP -- UTILS 1
int		free_all(t_node *a, t_node *b, char **argv, int two_args);
void	free_argv(char **argv, int two_args);
int		next_low(t_node **stack, int new_low);
void	ps_push_low_check_num(t_node **stack_a, int num, int i);
void	ps_push_low_to_b(t_node **stack_a, t_node **stack_b, int num);

// PUSH_SWAP -- UTILS 2
int		already_sorted(t_node *stack);
size_t	node_count(t_node *stack);
int		reversed_sorted(t_node *stack);

// PUSH_SWAP -- NUM TO INDEX
void	num_to_index(t_node **stack, int argc);

// PUSH_SWAP -- SORT: 3 TILL 6
void	ps_sort_3(t_node **stack);
void	ps_rev_sort_3(t_node **stack);
void	ps_sort_4(t_node **stack_a, t_node **stack_b);
void	ps_sort_5(t_node **stack_a, t_node **stack_b);
void	ps_sort_6(t_node **stack_a, t_node **stack_b);

#endif
