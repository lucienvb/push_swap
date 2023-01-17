/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/11 16:26:37 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	already_sorted(t_node *stack)
{
	t_node	*head;

	head = stack;
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	stack = head;
	return (1);
}

size_t	node_count(t_node *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	reversed_sorted(t_node *stack)
{
	if (!stack || stack->size == 1)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
