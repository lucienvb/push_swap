/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:07:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/29 17:25:31 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_node	*new_list(t_node *stack, char **argv)
{
	t_node	*new;

	if (!argv)
		return (NULL);
	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = ft_atoi(argv[1]);
	new->next = NULL;
	new->next = stack;
	return (new);
}

t_node	*create_list(t_node *stack, int new_content)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = new_content;
	new->next = NULL;
	new->next = stack;
	return (new);
}

void	delete_node(t_node **head, int data)
{
	t_node	*temp;
	t_node	*prev;

	temp = *head;
	if (temp && temp->content == data)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp && temp->content != data)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return ;
	prev->next = temp->next;
	free(temp);
}

void	print_list(t_node **head)
{
	t_node	*current;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

void	print_ind(t_node **head)
{
	t_node	*current;

	current = *head;
	while (current != NULL)
	{
		printf("%lld\n", current->index);
		current = current->next;
	}
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

t_node	*list_last(t_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_back(t_node **head, int content)
{
	t_node	*current;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_node *) malloc(sizeof(t_node));
	current->next->content = content;
	current->next->next = NULL;
}
