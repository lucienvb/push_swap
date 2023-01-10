/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 10:44:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 13:20:07 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rot(t_node **stack, char c)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	last = list_last(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	ft_printf("r%c\n", c);
}

void	rev_rot(t_node **stack, char c)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	last = list_last(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->next->next == NULL)
			temp->next = NULL;
		temp = temp->next;
	}
	last->next = *stack;
	*stack = last;
	ft_printf("rr%c\n", c);
}
