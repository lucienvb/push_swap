/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_bucket_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 17:12:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/30 17:22:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ps_bucket_firstlast(t_node **stack_a)
{
	static long long	lowest;

	lowest = 2147483648;
	if ((*stack_a)->content > list_last(*stack_a)->content)
		rra(stack_a);
	printf("\nstack_a:\n");
	print_list(stack_a);
}*/

/*void	ps_bucket_sub(stack_a, stack_b)
{


}*/

static void	ps_sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == 0)
	{
		rra(stack_a);
		ps_sa(stack_a);
		return ;
	}
	else if ((*stack_a)->index == 1)
	{
		if ((*stack_a)->next->index == 0)
			ps_sa(stack_a);
		else
			rra(stack_a);
		return ;
	}
	else
	{
		if ((*stack_a)->next->index == 1)
		{
			ps_sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	ps_bucket_sort(t_node **stack_a, t_node **stack_b)
{
	printf("%lli", (*stack_a)->index);
	(void)stack_b;
	if (!stack_a || already_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->size == 2)
	{
		ps_sa(stack_a);
		return ;
	}
	else if ((*stack_a)->size == 3)
		ps_sort_three(stack_a);
	else
		write(1, "4 and higher\n", 14);
	//ps_bucket_sub(stack_a, stack_b);
}
