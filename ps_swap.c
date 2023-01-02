/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:51 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/02 15:32:10 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_node **head)
{
	int	temp;
	int	keep_size;
	
	keep_size = (*head)->size;
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	(*head)->size = keep_size;
	write(1, "sa\n", 3);
}

void	ps_sb(t_node **head)
{
	int	temp;
	int	keep_size;
	
	keep_size = (*head)->size;
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	(*head)->size = keep_size;
	write(1, "sb\n", 3);
}
