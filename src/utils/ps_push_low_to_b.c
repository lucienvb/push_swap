/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:55 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/12 10:02:02 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

void	ps_push_low_check_num(t_node **stack_a, int num, int i)
{
	if (i == num)
		rev_rot(stack_a, 'a');
	else if ((num == 4 && i == 3) || (num == 5 && i == 4))
	{
		rev_rot(stack_a, 'a');
		rev_rot(stack_a, 'a');
	}
	else if (num == 5 && i == 3)
	{
		rev_rot(stack_a, 'a');
		rev_rot(stack_a, 'a');
		rev_rot(stack_a, 'a');
	}
	else if (i == 1)
		rot(stack_a, 'a');
}

void	ps_push_low_to_b(t_node **stack_a, t_node **stack_b, int num)
{
	size_t	i;
	t_node	*head;

	i = 0;
	head = *stack_a;
	while ((*stack_a)->index != 0)
	{
		i++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head;
	if (num > 2 && i != 2)
		ps_push_low_check_num(stack_a, num, i);
	else if (i)
	{
		while (i)
		{
			rot(stack_a, 'a');
			i--;
		}
	}
	push(stack_a, stack_b, 'b');
}
