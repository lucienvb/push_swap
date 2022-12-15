#include "push_swap.h"

void	add_front(t_node **head, int new_content)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->next = *head;
	*head = new_node;
}

void	ps_pa(t_node **stack_a, t_node **stack_b)
{
	if (stack_b)
	{
		*stack_a = ps_push(stack_b, stack_a);
		delete_node(stack_b, (*stack_b)->content);
	}
}

void	ps_pb(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
	{
		*stack_b = ps_push(stack_a, stack_b);
		delete_node(stack_a, (*stack_a)->content);
	}
}

t_node	*ps_push(t_node **push, t_node **pull)
{
	
	if (!*push)
		return (NULL);
	if (*pull == NULL)
		*pull = create_list(*pull, (*push)->content);
	else
		add_front(pull, (*push)->content);
	return (*pull);
}
