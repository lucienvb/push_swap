/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 17:09:08 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDE
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
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

// DEFINE

// LIBFT FUNCTIONS
// long long	ft_atoi(const char *str);
// char		*ft_itoa(int n);
// size_t		word_count(char const *s, char c);
// char		**ft_split(char const *s, char c, char *placeholder);

// FT_PRINTF


// PUSH_SWAP OPERATIONS -- SWAP & PUSH
void		ps_sa(t_node **head);
void		ps_sb(t_node **head);
void		ps_pa(t_node **stack_a, t_node **stack_b);
void		ps_pb(t_node **stack_a, t_node **stack_b);
t_node		*ps_push(t_node **push, t_node **pull);

// PUSH_SWAP FUNCTIONS -- ERROR CHECK
char		**convert_and_check(int argc, char **argv);

// PUSH_SWAP FUNCTIONS -- LISTS
t_node		*new_list(t_node *stack, char **argv);
t_node		*create_list(t_node *stack, int new_content);
void		delete_node(t_node **head, int data);
void		add_back(t_node **head, int content);
int			list_size(t_node *stack);
t_node		*list_last(t_node *stack);
//void		add_front(t_node *stack, t_node *node);
void		add_front(t_node **head, int new_content);

// PUSH_SWAP OPERATIONS -- ROTATE
void		rot(t_node **stack, char c);
void		rev_rot(t_node **stack, char c);
//void		rb(t_node **stack);
// void		rra(t_node **stack);
// void		rrb(t_node **stack);

// PUSH_SWAP FUNCTIONS -- ALGORITHM
void		ps_radix_sort(t_node **stack_a, t_node **stack_b);

// PUSH_SWAP UTILS 1
int			fil_pos_check(char **str, char *num);
int			next_low(t_node **stack, int new_low);
t_node		**node_position(t_node **stack, int num);
void		ps_push_low_check_num(t_node **stack_a, int num, int i);
void		ps_push_low_to_b(t_node **stack_a, t_node **stack_b, int num);

// PUSH_SWAP UTILS 2
int			already_sorted(t_node *stack);
long long	find_lowest(t_node **stack, long long highest);
int			node_count(t_node *stack);
int			ps_position(t_node *stack, int content);
int			reversed_sorted(t_node *stack);

// PUSH_SWAP UTILS -- NUM TO INDEX
void		num_to_index(t_node **stack, int argc);

// PUSH_SWAP SORT -- 3 TILL 6
void		ps_sort_3(t_node **stack);
void		ps_rev_sort_3(t_node **stack);
void		ps_sort_4(t_node **stack_a, t_node **stack_b);
void		ps_sort_5(t_node **stack_a, t_node **stack_b);
void		ps_sort_6(t_node **stack_a, t_node **stack_b);

#endif
