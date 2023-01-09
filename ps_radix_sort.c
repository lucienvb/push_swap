/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 10:43:54 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 11:03:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

void	ps_radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	count;
	int	i;
	int	j;

	count = list_size(*stack_a);
	j = 0;
	while (already_sorted(*stack_a) == 0)
	{
		i = 0;
		while (i < count)
		{
			if (((*stack_a)->index >> j) & 1)
				ra(stack_a);
			else
				ps_pb(stack_a, stack_b);
			i++;
		}
		while (*stack_b)
			ps_pa(stack_a, stack_b);
		num_to_index(stack_a, count + 1);
		j++;
	}
}
