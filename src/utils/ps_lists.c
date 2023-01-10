/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:07:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 16:23:02 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	add_back(t_node **head, int content)
{
	t_node	*current;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_node *) malloc(sizeof(t_node));
	current->next->content = content;
	current->next->next = NULL;
	(*head)->size++;
}

void	clear_list(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp;
	int		size;

	if (!stack_a)
		return ;
	size = list_size(stack_a);
	while (size)
	{
		temp = stack_a;
		stack_a = temp->next;
		free(temp);
		size--;
	}
	if (!stack_b)
		return ;
	size = list_size(stack_b);
	while (size)
	{
		temp = stack_b;
		stack_b = temp->next;
		free(temp);
		size--;
	}
}

t_node	*list_last(t_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	list_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_node	*new_list(t_node *stack, char **argv)
{
	t_node	*new;

	if (!argv)
		return (NULL);
	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = ft_atoi(argv[1]);
	new->size = 1;
	new->next = NULL;
	new->next = stack;
	return (new);
}
