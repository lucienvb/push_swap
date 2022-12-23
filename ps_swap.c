#include "push_swap.h"

void	ps_sa(t_node **head)
{
	int	temp;
	
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	write(1, "sa\n", 3);
}

void	ps_sb(t_node **head)
{
	int	temp;
	
	temp = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp;
	write(1, "sb\n", 3);
}
