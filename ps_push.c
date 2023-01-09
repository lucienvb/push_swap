/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:06:49 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/09 12:12:27 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	$stack_add_front(t_node *stack, t_node *node)
// {
// 	t_node *last;

// 	if (stack->next == NULL)
// 	{
// 		stack->size++;
// 		stack->next = node;
// 		node->next = node;
// 		return ;
// 	}
// 	last = list_last(stack);
// 	stack->size++;
// 	node->next = stack->next;
// 	last->next = node;
// }

void	add_front(t_node **head, int new_content)
{
	t_node	*new_node;
	int		keep_size;

	keep_size = (*head)->size;
	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->next = *head;
	new_node->size = keep_size + 1;
	*head = new_node;
}

void	ps_pa(t_node **stack_a, t_node **stack_b)
{
	if (stack_b)
	{
		*stack_a = ps_push(stack_b, stack_a);
		delete_node(stack_b, (*stack_b)->content);
		if (*stack_a)
			(*stack_a)->size = list_size(*stack_a);
		if (*stack_b)
			(*stack_b)->size = list_size(*stack_b);
		write(1, "pa\n", 3);
	}
}

void	ps_pb(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
	{
		*stack_b = ps_push(stack_a, stack_b);
		delete_node(stack_a, (*stack_a)->content);
		if (*stack_a)
			(*stack_a)->size = list_size(*stack_a);
		if (*stack_b)
			(*stack_b)->size = list_size(*stack_b);
		write(1, "pb\n", 3);
	}
}

t_node	*ps_push(t_node **push, t_node **pull)
{
	if (!*push)
		return (NULL);
	if (*pull == NULL)
		*pull = create_list(*pull, (*push)->content);
	else
		//add_front(*pull, *push);
		add_front(pull, (*push)->content);
	return (*pull);
}
