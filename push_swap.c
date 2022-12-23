/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:06:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/23 17:37:34 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*static long long	ps_find_lowest(t_node *stack)
{
	t_node		*head;
	long long	lowest;
	
	head = stack;
	lowest = 2147483648;
	while (stack)
	{
		if (lowest == 2147483648)
			lowest = (stack)->content;
		else
		{
			if ((stack)->content < lowest)
				lowest = (stack)->content;
		}
		stack = (stack)->next;
	}
	stack = head;
	return (lowest);
}*/

int	fil_pos_check(char **str, char *num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == num)
			return (0);
		i++;
	}
	return (1);
}

t_node	**node_position(t_node **stack, int num)
{
	while (*stack && (*stack)->content != num)
		*stack = (*stack)->next;
	return (stack);		
}

int	next_low(t_node **stack, int new_low)
{
	t_node	*head;
	int		next_low;

	head = *stack;
	next_low = 0;
	while (*stack)
	{
		if ((*stack)->content > new_low)
		{
			next_low = (*stack)->content;
			break;
		}	
		*stack = (*stack)->next;
	}
	*stack = head;
	while (*stack)
	{
		if ((*stack)->content < next_low && (*stack)->content > new_low)
			next_low = (*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (next_low);
}

void	num_to_index(t_node **stack, int argc)
{
	int		low;
	int		new_low;
	int		i;
	t_node	*head;
	
	(void) argc;
	head = *stack;
	i = 0;
	low = (*stack)->content;
	while (*stack && (*stack)->next)
	{
		if ((*stack)->next->content < low)
			low = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = head;
	while (*stack)
	{
		if ((*stack)->content == low)
			(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	new_low = (*stack)->content;
	while (argc > 2)
	{
		while (*stack && (*stack)->next)
		{
			if ((*stack)->next->content > low && (*stack)->next->content < new_low)
				new_low = (*stack)->next->content;
			*stack = (*stack)->next;	
		}
		*stack = head;
		while (*stack)
		{
			if ((*stack)->content == new_low)
				(*stack)->index = i++;
			*stack = (*stack)->next;
		}
		*stack = head;
		low = new_low;
		new_low = next_low(stack, new_low);
		*stack = head;
		argc--;
	}
}

int	main(int argc, char **argv)
//int		checkLeaks(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	
	stack_a = NULL;
	stack_b = NULL;
	argv = convert_and_check(argc, argv);
	if (!argv)
		return (0);
	i = 2;
	stack_a = new_list(stack_a, argv);
	while (argv[i])
		add_back(&stack_a, ft_atoi(argv[i++]));
	// printf("stack_a:\n");
	// print_list(&stack_a);
	// printf("\nstack_b:\n");
	// print_list(&stack_b);
	
	num_to_index(&stack_a, argc);
	//ps_bucket_sort(&stack_a, &stack_b);
	//ps_mergesort(&stack_a, &stack_b);
		
	printf("\nstack_a:\n");
	print_ind(&stack_a);
	// printf("\nstack_b:\n");
	// print_list(&stack_b);
	//while (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	checkLeaks(argc, argv);
}*/
