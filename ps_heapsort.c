#include "push_swap.h"

long long	find_lowest(t_node **stack, long long highest)
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

int	ps_position(t_node *stack, int content)
{
	int	position;
	int	icontent;
	//t_node	*head;

	//head = stack;
	icontent = (int)content;
	position = 0;
	while (stack->content != icontent)
	{
		position++;
		stack = stack->next;
	}
	//stack = head;
	return (position);
}

int	already_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*static int	reversed_sorted(t_node *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
		i++;
	}
	return (i);
}

static int	check_reversed(t_node **stack)
{
	int	i;

	if (reversed_sorted(*stack) != 0)
	{
		i = reversed_sorted(*stack);
		while (i)
		{
			rotate(stack);
			i--;
		}
		return (1);
	}
	return (0);
}*/

int	node_count(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/*void	sort_three

void	sort_algorithm(t_node **stack_a, t_node **stack_b)
{
	if (node_count(*stack_a) > 1 && node_count(*stack_a) < 4)

}*/

void	ps_heapsort(t_node **stack_a, t_node **stack_b)
{
	static long long	highest;
	int					position;

	if (!stack_a || already_sorted(*stack_a) == 1)
		return ;
	while (*stack_a && (*stack_a)->next)
	{
		highest = 2147483648;
		highest = find_lowest(stack_a, highest);
		position = ps_position(*stack_a, highest);
		if (position != 0)
		{
			while (position)
			{
				ra(stack_a);
				position--;
			}
		}
		ps_pb(stack_a, stack_b);
	}
	while (*stack_b)
		ps_pa(stack_a, stack_b);
}
