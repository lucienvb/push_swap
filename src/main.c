/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:06:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/23 09:42:32 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ps_sort(t_node **stack_a, t_node **stack_b, int argc)
{
	content_to_index(stack_a, argc);
	if (!stack_a || list_sorted(*stack_a) == one)
		return ;
	if ((*stack_a)->size == two)
		swap(stack_a, 'a');
	else if ((*stack_a)->size == three)
		ps_sort_3(stack_a);
	else if ((*stack_a)->size == four)
		ps_sort_4(stack_a, stack_b);
	else if ((*stack_a)->size == five)
		ps_sort_5(stack_a, stack_b);
	else if ((*stack_a)->size == six)
		ps_sort_6(stack_a, stack_b);
	else
		ps_radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	size_t	i;
	size_t	two_args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	two_args = word_count(argv[1], ' ');
	argv = convert_and_check(argc, argv, two_args);
	stack_a = new_list(stack_a, argv);
	if (!stack_a)
		return (0);
	i = 2;
	while (argv[i])
	{
		if (add_back(&stack_a, ft_atol(argv[i])) == 0)
			return (free_all(stack_a, stack_b, argv, two_args));
		i++;
	}
	ps_sort(&stack_a, &stack_b, argc);
	return (free_all(stack_a, stack_b, argv, two_args));
}
