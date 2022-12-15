#include "push_swap.h"
#include <stdio.h>

t_node	*rotate(t_node **stack)
{
	int	temp;

	if (!stack)
		return (NULL);
	temp = (*stack)->content;
	delete_node(stack, (*stack)->content);
	add_back(stack, temp);
	return (*stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		*stack_a = rotate(stack_a);
		*stack_b = rotate(stack_b);
	}		
}

t_node	*reverse_rotate(t_node **stack)
{
	int		temp;
	t_node	*second_last;

	if (!stack)
		return (NULL);
	second_last = (*stack);
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	temp = second_last->next->content;
	delete_node(&second_last, second_last->next->content);
	add_front(stack, temp);
	return (*stack);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		*stack_a = reverse_rotate(stack_a);
		*stack_b = reverse_rotate(stack_b);
	}		
}