/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_num_to_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:33 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 16:23:04 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	set_low(t_node **stack, int low, int i)
{
	t_node	*head;

	head = *stack;
	while (*stack)
	{
		if ((*stack)->content == low)
			(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (i);
}

static int	set_new_low(t_node **stack, int new_low, int i)
{
	t_node	*head;

	head = *stack;
	while (*stack)
	{
		if ((*stack)->content == new_low)
			(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (i);
}

static void	set_remaining(t_node **stack, int low, int i, int argc)
{
	int		new_low;
	t_node	*head;

	head = *stack;
	if ((*stack)->content == low)
		new_low = (*stack)->next->content;
	else
		new_low = (*stack)->content;
	if (argc == 2)
		argc = node_count(*stack) + 1;
	while (argc > 2)
	{
		while (*stack && (*stack)->next)
		{
			if ((*stack)->next->content > low
				&& (*stack)->next->content < new_low)
				new_low = (*stack)->next->content;
			*stack = (*stack)->next;
		}
		*stack = head;
		i = set_new_low(stack, new_low, i);
		low = new_low;
		new_low = next_low(stack, new_low);
		argc--;
	}
}

void	content_to_index(t_node **stack, int argc)
{
	int		low;
	int		i;
	t_node	*head;

	if ((*stack)->size == 1)
	{
		(*stack)->index = 0;
		return ;
	}
	head = *stack;
	i = 0;
	low = (*stack)->content;
	low = find_list_lowest(stack, low);
	i = set_low(stack, low, i);
	if (list_sorted(*stack) == 1)
		*stack = (*stack)->next;
	set_remaining(stack, low, i, argc);
	*stack = head;
}