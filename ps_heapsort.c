#include "push_swap.h"

static long long	find_lowest(t_node **stack, long long highest)
{
	t_node	*head;

	head = *stack;
	while (*stack)
	{
		if (highest == 2147483648)
			highest = (*stack)->content;
		else
		{
			if ((*stack)->content < highest)
				highest = (*stack)->content;
		}
		*stack = (*stack)->next;
	}
	*stack = head;
	return (highest);
}

static int	ps_position(t_node *stack, int content)
{
	int	position;
	int	icontent;

	icontent = (int)content;
	position = 0;
	while (stack->content != icontent)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

void	ps_heapsort(t_node **stack_a, t_node **stack_b)
{
	static long long	highest;
	t_node				*head;
	int					position;

	if (!stack_a)
		return ;
	head = *stack_a;
	while (*stack_a)
	{
		highest = 2147483648;
		highest = find_lowest(stack_a, highest);
		position = ps_position(*stack_a, highest);
		if (position != 0)
		{
			while (position)
			{
				rotate(stack_a);
				position--;
			}
		}
		ps_pb(stack_a, stack_b);
	}
	while (*stack_b)
		ps_pa(stack_a, stack_b);
}
