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

void	content_to_index(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	tmp = *stack;
	head = tmp;
	while (*stack)
	{
		(*stack)->index = 0;
		while (tmp)
		{
			if ((*stack)->content > tmp->content)
				(*stack)->index++;
			tmp = tmp->next;
		}
		tmp = head;
		*stack = (*stack)->next;
	}
	*stack = head;
}
