#include "push_swap.h"
#include <stdio.h>

void	rotate(t_node **stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = (*stack)->content;
	delete_node(stack, (*stack)->content);
	add_back(stack, temp);
	write(1, "ra\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
	}		
}

void	reverse_rotate(t_node **stack)
{
	int		temp;
	t_node	*second_last;

	if (!stack)
		return ;
	second_last = (*stack);
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	temp = second_last->next->content;
	delete_node(&second_last, second_last->next->content);
	add_front(stack, temp);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}		
}