#include "push_swap.h"
#include <stdio.h>

void	ra(t_node **stack)
{
	int	temp;
	int		keep_size;

	if (!stack)
		return ;
	keep_size = (*stack)->size;
	temp = (*stack)->content;
	delete_node(stack, (*stack)->content);
	add_back(stack, temp);
	(*stack)->size = keep_size;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	int	temp;
	int		keep_size;

	if (!stack)
		return ;
	keep_size = (*stack)->size;
	temp = (*stack)->content;
	delete_node(stack, (*stack)->content);
	add_back(stack, temp);
	(*stack)->size = keep_size;
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		ra(stack_a);
		rb(stack_b);
	}		
}

void	rra(t_node **stack)
{
	int		temp;
	t_node	*second_last;
	int		keep_size;

	if (!stack)
		return ;
	keep_size = (*stack)->size;
	second_last = (*stack);
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	temp = second_last->next->content;
	delete_node(&second_last, second_last->next->content);
	add_front(stack, temp);
	(*stack)->size = keep_size;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	int		temp;
	t_node	*second_last;
	int		keep_size;

	if (!stack)
		return ;
	keep_size = (*stack)->size;
	second_last = (*stack);
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	temp = second_last->next->content;
	delete_node(&second_last, second_last->next->content);
	add_front(stack, temp);
	(*stack)->size = keep_size;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		rra(stack_a);
		rrb(stack_b);
	}		
}