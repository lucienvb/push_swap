/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:07:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/11 15:03:06 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	free_all(t_node *a, t_node *b, char **argv, int two_args)
{
	free_argv(argv, two_args);
	clear_list(a, b);
	return (0);
}

void	free_argv(char **argv, int two_args)
{
	int	i;

	if (two_args < 2)
		return ;
	i = 1;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	clear_list(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp;
	int		size;

	if (!stack_a)
		return ;
	size = list_size(stack_a);
	while (size)
	{
		temp = stack_a;
		stack_a = temp->next;
		free(temp);
		size--;
	}
	if (!stack_b)
		return ;
	size = list_size(stack_b);
	while (size)
	{
		temp = stack_b;
		stack_b = temp->next;
		free(temp);
		size--;
	}
}
