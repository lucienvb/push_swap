/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 11:16:53 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long long	find_lowest(t_node **stack, long long highest)
{
	t_node	*head;

	head = *stack;
	while (*stack)
	{
		if (highest == 2147483648)
			highest = (*stack)->content;
		else
		{
			if ((*stack)->content < highest)
				highest = (*stack)->content;
		}
		*stack = (*stack)->next;
	}
	*stack = head;
	return (highest);
}

int	node_count(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ps_position(t_node *stack, int content)
{
	int	position;
	int	icontent;

	icontent = (int)content;
	position = 0;
	while (stack->content != icontent)
	{
		position++;
		stack = stack->next;
	}
	return (position);
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
