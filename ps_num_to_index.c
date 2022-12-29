#include "push_swap.h"

static int	find_low(t_node **stack, int low)
{
	t_node	*head;

	head = *stack;
	while (*stack && (*stack)->next)
	{
		if ((*stack)->next->content < low)
			low = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (low);
}

static int	set_low(t_node **stack, int low, int i)
{
	t_node	*head;

	head = *stack;
	while (*stack)
	{
		if ((*stack)->content == low)
			(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (i);
}

static int	set_new_low(t_node **stack, int new_low, int i)
{
	while (*stack)
	{
		if ((*stack)->content == new_low)
			(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	return (i);
}

static void	set_remaining(t_node **stack, int low, int i, int argc)
{
	int		new_low;
	t_node	*head;

	head = *stack;
	new_low = (*stack)->content;
	while (argc > 2)
	{
		while (*stack && (*stack)->next)
		{
			if ((*stack)->next->content > low
				&& (*stack)->next->content < new_low)
				new_low = (*stack)->next->content;
			*stack = (*stack)->next;
		}
		*stack = head;
		i = set_new_low(stack, new_low, i);
		*stack = head;
		low = new_low;
		new_low = next_low(stack, new_low);
		*stack = head;
		argc--;
	}
}

void	num_to_index(t_node **stack, int argc)
{
	int		low;
	int		i;
	t_node	*head;

	head = *stack;
	i = 0;
	low = (*stack)->content;
	low = find_low(stack, low);
	i = set_low(stack, low, i);
	if (already_sorted(*stack) == 1)
		*stack = (*stack)->next;
	set_remaining(stack, low, i, argc);
	*stack = head;
}