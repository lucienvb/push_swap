/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_error_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:44 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 13:18:14 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**convert_and_check(int argc, char **argv, int two_args)
{
	if ((argc == 2 && two_args == 1 && error_num_check_for_2d_array(argv) == 1)
		|| (argc == 2 && word_count(argv[1], ' ') == 0))
		return (NULL);
	if (argc > 2 && word_count(argv[1], ' ') > 1)
		return (write(STDERR_FILENO, "Error\n", 6), NULL);
	if (argc == 2 && error_num_check(argv[1]) == 0)
		argv = ft_split(argv[1], ' ', argv[0]);
	if (error_num_check_for_2d_array(argv) == 0)
	{
		free_argv(argv, two_args);
		return (write(STDERR_FILENO, "Error\n", 6);, NULL);
	}
	if (!argv)
	{
		free_argv(argv, two_args);
		return (NULL);
	}
	return (argv);
}
