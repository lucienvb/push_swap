#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

long long	dec_to_bin(int n) 
{
	long long	bin;
	int			mod;
	int			i;
	
	i = 1;
	bin = 0;
	while (n != 0) 
	{
		mod = n % 2;
		n /= 2;
		bin += mod * i;
		i *= 10;
	}
	return (bin);
}

void	stack_to_bin(t_node **stack)
{
	t_node	*head;
	int		count;

	count = list_size(*stack) + 1;
	num_to_index(stack, count);
	head = *stack;
	while (*stack)
	{
		(*stack)->bin = dec_to_bin((*stack)->index);
		*stack = (*stack)->next;
	}
	*stack = head;
}

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