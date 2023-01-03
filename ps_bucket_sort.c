/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_bucket_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 17:12:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/03 17:35:29 by lvan-bus      ########   odam.nl         */
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

static void	ps_sort_3(t_node **stack)
{
	if ((*stack)->index == 0)
	{
		rra(stack);
		ps_sa(stack);
		return ;
	}
	else if ((*stack)->index == 1)
	{
		if ((*stack)->next->index == 0)
			ps_sa(stack);
		else
			rra(stack);
		return ;
	}
	else
	{
		if ((*stack)->next->index == 1)
		{
			ps_sa(stack);
			rra(stack);
		}
		else
			ra(stack);
	}
}

/*static void	ps_sort_a(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->size == 2 && already_sorted(*stack_a) == 0)
		ps_sa(stack_a);
	else if ((*stack_a)->size == 3)
		ps_sort_3(stack_a);
	if (list_last(*stack_a)->index < (*stack_a)->index
		&& list_last(*stack_a)->index < (*stack_a)->next->index)
		{
			rra(stack_a);
			// ps_pb(stack_a, stack_b);
			if (already_sorted(*stack_a) == 0)
				ps_pb(stack_a, stack_b);
		}	
	else if ((*stack_a)->next->index < (*stack_a)->index
		&& list_last(*stack_a)->index > (*stack_a)->next->index)
		{
			ps_sa(stack_a);
			// ps_pb(stack_a, stack_b);
			if (already_sorted(*stack_a) == 0)
				ps_pb(stack_a, stack_b);
		}		
}

static void	ps_sort_b(t_node **stack_a, t_node **stack_b)
{
	(void)stack_a;
	if ((*stack_b)->size == 1)
		return ;
	if ((*stack_b)->size == 2 && reversed_sorted(*stack_b) == 0)
		ps_sb(stack_b);
	else if ((*stack_b)->size == 3)
		ps_sort_3(stack_b);
	else if (list_last(*stack_b)->index < (*stack_b)->index
		&& list_last(*stack_b)->index < (*stack_b)->next->index)
		{
			rrb(stack_b);
			// if (already_sorted(*stack_a) == 0)
			// 	ps_pa(stack_a, stack_b);
		}
	else if ((*stack_b)->next->index < (*stack_b)->index
		&& list_last(*stack_b)->index > (*stack_b)->next->index)
		{
			ps_sb(stack_b);
			// if (already_sorted(*stack_a) == 0)
			// 	ps_pa(stack_a, stack_b);
		}
}

static void	ps_sort_4_and_more(t_node **stack_a, t_node **stack_b)
{
	//int	i;

	if (!*stack_a)
		return ;
	while (already_sorted(*stack_a) == 0 && reversed_sorted(*stack_b) == 0)
	{
		if (*stack_b && reversed_sorted(*stack_b) == 0)
			ps_sort_b(stack_a, stack_b);
		if (*stack_a && already_sorted(*stack_a) == 0)
			ps_sort_a(stack_a, stack_b);
	}
	// printf("\nstack_a:\n");
	// print_list(stack_a);
	// printf("\nstack_b:\n");
	// print_list(stack_b);
	if ((already_sorted(*stack_a) == 1 && reversed_sorted(*stack_b) == 1)
	|| (*stack_b)->size == 1)
	{
		while (*stack_b)
			ps_pa(stack_a, stack_b);
	}
	while (already_sorted(*stack_a) == 0 && reversed_sorted(*stack_b) == 0)
		ps_sort_4_and_more(stack_a, stack_b);
}*/

static void	ps_push_low_to_b(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_node	*head;

	i = 0;
	head = *stack_a;
	if ((*stack_a)->index != 0)
		ps_pb(stack_a, stack_b);
	while ((*stack_a)->index != 0)
	{
		i++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head;
	if (i == 3)
	{
		rra(stack_a);
		ps_pb(stack_a, stack_b);
	}
	else
	{
		while (i)
		{
			ra(stack_a);
			i--;
		}
		ps_pb(stack_a, stack_b);
	}
}

static void	ps_sort_4(t_node **stack_a, t_node **stack_b)
{
	ps_push_low_to_b(stack_a, stack_b);
	
	/*ps_sort_3(stack_a);
	ps_pa(stack_a, stack_b);*/
	// int	i;

	// i = 2;
	// while (i)
	// {
	// 	ps_push_low_to_b(stack_a, stack_b);
	// 	i--;
	// }
	// if (already_sorted(*stack_a) == 0)
	// 	ps_sa(stack_a);
	// if (reversed_sorted(*stack_b) == 0)
	// 	ps_sb(stack_b);
	// while (stack_b)
	// 	ps_pa(stack_a, stack_b);
}

void	ps_bucket_sort(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || already_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->size == 2)
		ps_sa(stack_a);
	else if ((*stack_a)->size == 3)
		ps_sort_3(stack_a);
	else if ((*stack_a)->size == 4)
		ps_sort_4(stack_a, stack_b);
	/*else if ((*stack_a)->size == 5)
		ps_sort_5(stack_a, stack_b);
	else if ((*stack_a)->size == 6)
		ps_sort_6(stack_a, stack_b);*/
	else
		return ;
	// 	ps_sort_4_and_more(stack_a, stack_b);
}
