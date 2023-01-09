/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 17:12:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 17:09:31 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_3(t_node **stack)
{
	if (already_sorted(*stack) == 1)
		return ;
	if ((*stack)->index == 0)
	{
		rev_rot(stack, 'a');
		ps_sa(stack);
		return ;
	}
	else if ((*stack)->index == 1)
	{
		if ((*stack)->next->index == 0)
			ps_sa(stack);
		else
			rev_rot(stack, 'a');
		return ;
	}
	if ((*stack)->next->index == 1)
	{
		ps_sa(stack);
		rev_rot(stack, 'a');
	}
	else
		rot(stack, 'a');
}

void	ps_rev_sort_3(t_node **stack)
{
	if (reversed_sorted(*stack) == 1)
		return ;
	if ((*stack)->index == 2)
	{
		ps_sb(stack);
		rot(stack, 'b');
		return ;
	}
	else if ((*stack)->index == 1)
	{
		if ((*stack)->next->index == 0)
			rev_rot(stack, 'b');
		else
			ps_sb(stack);
		return ;
	}
	if ((*stack)->next->index == 1)
	{
		ps_sb(stack);
		rev_rot(stack, 'b');
	}
	else
		rot(stack, 'b');
}

void	ps_sort_4(t_node **stack_a, t_node **stack_b)
{
	ps_push_low_to_b(stack_a, stack_b, 3);
	num_to_index(stack_a, 4);
	ps_sort_3(stack_a);
	ps_pa(stack_a, stack_b);
}

void	ps_sort_5(t_node **stack_a, t_node **stack_b)
{
	ps_push_low_to_b(stack_a, stack_b, 4);
	num_to_index(stack_a, 4);
	ps_push_low_to_b(stack_a, stack_b, 3);
	if (reversed_sorted(*stack_b) == 0)
		ps_sb(stack_b);
	num_to_index(stack_a, 3);
	ps_sort_3(stack_a);
	ps_pa(stack_a, stack_b);
	ps_pa(stack_a, stack_b);
}

void	ps_sort_6(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 5;
	while (i > 2)
	{
		ps_push_low_to_b(stack_a, stack_b, i);
		num_to_index(stack_a, i);
		i--;
	}
	num_to_index(stack_b, 3);
	ps_rev_sort_3(stack_b);
	num_to_index(stack_a, 3);
	ps_sort_3(stack_a);
	while (i != -1)
	{
		ps_pa(stack_a, stack_b);
		i--;
	}
}
