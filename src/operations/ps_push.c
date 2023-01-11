/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:49 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 17:12:14 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_node **push, t_node **pull, char c)
{
	t_node	*temp;

	if (!*push || !pull)
		return ;
	temp = *push;
	if (!temp)
		return ;
	*push = temp->next;
	temp->next = *pull;
	*pull = temp;
	ft_printf("p%c\n", c);
}
