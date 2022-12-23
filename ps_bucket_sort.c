#include "push_swap.h"

static void	ps_bucket_firstlast(t_node **stack_a)
{
	static long long	lowest;

	lowest = 2147483648;
	if ((*stack_a)->content > list_last(*stack_a)->content)
		rra(stack_a);
	printf("\nstack_a:\n");
	print_list(stack_a);
}

static void	ps_bucket_sub1(t_node **stack_a, t_node **stack_b)
{
	while (*stack_a)
	{
		ps_bucket_firstlast(stack_a);
		if ((*stack_a)->content >= 0 && (*stack_a)->content <= 9)
		{
			ps_pb(stack_a, stack_b);
			if (node_count(*stack_b) == 2 && ((*stack_b)->content > (*stack_b)->next->content))
				ps_sb(stack_b);
			else if (node_count(*stack_b) > 2)
			{
				if ((*stack_b)->content > (*stack_b)->next->content)
					ps_sb(stack_b);
				else if((*stack_b)->content > list_last(*stack_b)->content)
				{
					rrb(stack_b);
					ps_sb(stack_b);
					rb(stack_b);
					rb(stack_b);
				}
			}
		}
		else
			*stack_a = (*stack_a)->next;
		printf("\nstack_a:\n");
		print_list(stack_a);
		printf("\nstack_b:\n");
		print_list(stack_b);
	}
}

void	ps_bucket_sort(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || already_sorted(*stack_a) == 1)
		return ;
	ps_bucket_sub1(stack_a, stack_b);
}