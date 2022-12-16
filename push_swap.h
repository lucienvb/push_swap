/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/16 13:20:35 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDE
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

// STRUCTURES
typedef struct node
{
	int				content;
	struct node		*next;
}					t_node;

// DEFINE

// LIBFT FUNCTIONS
long long	ft_atoi(const char *str);
size_t		word_count(char const *s, char c);
char		**ft_split(char const *s, char c, char *placeholder);

// PUSH_SWAP FUNCTIONS
void	ps_sa(t_node **head);
void	add_front(t_node **head, int new_content);
void	ps_pa(t_node **stack_a, t_node **stack_b);
void	ps_pb(t_node **stack_a, t_node **stack_b);
t_node	*ps_push(t_node **push, t_node **pull);

// PUSH_SWAP FUNCTIONS -- ERROR CHECK
char	**convert_and_check(int argc, char **argv);

// PUSH_SWAP FUNCTIONS -- LISTS
t_node	*new_list(t_node *stack, char **argv);
t_node	*create_list(t_node *stack, int new_content);
void	delete_node(t_node **head, int data);
void	print_list(t_node **head);
void	add_back(t_node **head, int content);
int		list_size(t_node *stack);
t_node	*list_last(t_node *stack);

// PUSH_SWAP FUNCTIONS -- ROTATE
void	rotate(t_node **stack_a);
void	reverse_rotate(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// PUSH_SWAP FUNCTIONS -- HEAPSORT
void	ps_heapsort(t_node **stack_a, t_node **stack_b);

#endif
