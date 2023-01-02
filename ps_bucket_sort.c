/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_bucket_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 17:12:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/02 16:21:10 by lvan-bus      ########   odam.nl         */
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

static void	ps_sort_3(t_node **stack_a)
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

static void	ps_sort_4_and_more(t_node **stack_a, t_node **stack_b)
{
	//int	i;

	while (already_sorted(*stack_a) == 0)
	{
		if (list_last(*stack_a)->index < (*stack_a)->index)
		{
			rra(stack_a);
		}
		//if ((*stack_a)->index > (*stack_a)->next->index)
			//ps_sa(stack_a);
		else
			ps_pb(stack_a, stack_b);
	}
	if (reversed_sorted(*stack_b))
	{
		printf("size: %i\n", (*stack_b)->size);
		while ((*stack_b)->size)
		{
			ps_pa(stack_a, stack_b);
			printf("size: %i\n", (*stack_b)->size);
		}
	}
	//ps_pa(stack_a, stack_b);
}

void	ps_bucket_sort(t_node **stack_a, t_node **stack_b)
{
	//printf("%i", (*stack_a)->index);
	//(void)stack_b;
	if (!stack_a || already_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->size == 2)
		ps_sa(stack_a);
	else if ((*stack_a)->size == 3)
		ps_sort_3(stack_a);
	else
		ps_sort_4_and_more(stack_a, stack_b);
	//ps_bucket_sub(stack_a, stack_b);
}
