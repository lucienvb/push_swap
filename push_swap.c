/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:06:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/15 18:59:37 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
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
	stack_b = new_list(stack_b, argv);
	int	j = 3;
	while (j > 1)
		add_back(&stack_b, ft_atoi(argv[j--]));
	
	printf("stack_a:\n");
	print_list(&stack_a);
	printf("\nstack_b:\n");
	print_list(&stack_b);

	ps_sa(&stack_b);
	// int	j = 0;
	// while (j < 3)
	// {
	// 	rr(&stack_a, &stack_b);
	// 	j++;
	// }
	printf("\nstack_a:\n");
	print_list(&stack_a);
	printf("\nstack_b:\n");
	print_list(&stack_b);
	
	return (0);
}
