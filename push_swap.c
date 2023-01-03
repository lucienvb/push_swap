/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:06:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/03 10:48:38 by lvan-bus      ########   odam.nl         */
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
	
	// printf("\nstack_a:\n");
	// print_ind(&stack_a);
	num_to_index(&stack_a, argc);
	ps_bucket_sort(&stack_a, &stack_b);
	
	// ps_pb(&stack_a, &stack_b);
	// ps_pa(&stack_a, &stack_b);
	
	printf("\nstack_a:\n");
	print_list(&stack_a);
	printf("\nstack_b:\n");
	print_list(&stack_b);
	
	//while (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	checkLeaks(argc, argv);
}*/
