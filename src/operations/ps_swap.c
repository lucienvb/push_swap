/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:51 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 16:22:33 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_node **head, char c)
{
	t_node	*first;
	t_node	*second;

	first = *head;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	*head = second;
	ft_printf("s%c\n", c);
}
