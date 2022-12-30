/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:51 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/30 16:06:52 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_node **head)
{
	int	temp;
	
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	write(1, "sa\n", 3);
}

void	ps_sb(t_node **head)
{
	int	temp;
	
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	write(1, "sb\n", 3);
}
