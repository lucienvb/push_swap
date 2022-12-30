/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_one.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:55 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/30 16:06:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fil_pos_check(char **str, char *num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == num)
			return (0);
		i++;
	}
	return (1);
}

t_node	**node_position(t_node **stack, int num)
{
	while (*stack && (*stack)->content != num)
		*stack = (*stack)->next;
	return (stack);
}

int	next_low(t_node **stack, int new_low)
{
	t_node	*head;
	int		next_low;

	head = *stack;
	next_low = 0;
	while (*stack)
	{
		if ((*stack)->content > new_low)
		{
			next_low = (*stack)->content;
			break ;
		}	
		*stack = (*stack)->next;
	}
	*stack = head;
	while (*stack)
	{
		if ((*stack)->content < next_low && (*stack)->content > new_low)
			next_low = (*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (next_low);
}