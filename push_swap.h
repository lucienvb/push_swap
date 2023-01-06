/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/06 14:37:12 by lvan-bus      ########   odam.nl         */
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
	int				index;
	long long		bin;
	int				size;
	struct node		*next;
}					t_node;

// DEFINE

// LIBFT FUNCTIONS
long long	ft_atoi(const char *str);
char		*ft_itoa(int n);
size_t		word_count(char const *s, char c);
char		**ft_split(char const *s, char c, char *placeholder);

// PUSH_SWAP FUNCTIONS
void	ps_sa(t_node **head);
void	ps_sb(t_node **head);
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
void	print_ind(t_node **head);
void	print_bin(t_node **head);
void	add_back(t_node **head, int content);
int		list_size(t_node *stack);
t_node	*list_last(t_node *stack);

// PUSH_SWAP FUNCTIONS -- ROTATE
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// PUSH_SWAP FUNCTIONS -- ALGORITHMS
void	ps_heapsort(t_node **stack_a, t_node **stack_b);
//void	ps_mergesort(t_node **stack_a, t_node **stack_b);
void	ps_bucket_sort(t_node **stack_a, t_node **stack_b);
void	ps_radix_sort(t_node **stack_a, t_node **stack_b);

// PUSH_SWAP UTILS
int			already_sorted(t_node *stack);
int			reversed_sorted(t_node *stack);
int			node_count(t_node *stack);
long long	find_lowest(t_node **stack, long long highest);
int			ps_position(t_node *stack, int content);
void		num_to_index(t_node **stack, int argc);
int			next_low(t_node **stack, int new_low);
int			fil_pos_check(char **str, char *num);
t_node		**node_position(t_node **stack, int num);
long long	dec_to_bin(int n) ;
void		stack_to_bin(t_node **stack);

#endif
