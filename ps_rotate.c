/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 10:44:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 17:17:16 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rot(t_node **stack, char c)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	//ft_printf("temp: %i\n", temp);
	last = list_last(*stack);
	last->next = *stack;
	//ft_printf("%i\n", (*stack)->next);
	(*stack)->next = NULL;
	*stack = temp;
	ft_printf("r%c\n", c);
}

void	rev_rot(t_node **stack, char c)
{
	t_node	*temp;
	t_node	*last;
	
	if (!*stack || (*stack)->next == NULL)
		return ;
	last = list_last(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->next->next == NULL)
			temp->next = NULL;
		temp = temp->next;
	}
	last->next = *stack;
	*stack = last;
	ft_printf("rr%c\n", c);
}

/*void	rra(t_node **stack)
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
	//add_front(*stack, list_last(*stack));
	add_front(stack, temp);
	(*stack)->size = keep_size;
	write(1, "rra\n", 4);
}*/

/*void	rrb(t_node **stack)
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
	//add_front(*stack, list_last(*stack));
	add_front(stack, temp);
	(*stack)->size = keep_size;
	write(1, "rrb\n", 4);
}*/
