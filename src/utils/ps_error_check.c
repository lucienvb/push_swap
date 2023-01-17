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

static size_t	error_double_check(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static size_t	error_limit_check(char **argv)
{
	long long	num;
	size_t		i;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (error_double_check(argv));
}

static size_t	error_str_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' && str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static size_t	error_2d_array_check(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-' && argv[i][j] == '-')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (error_limit_check(argv));
}

char	**convert_and_check(int argc, char **argv, int two_args)
{
	if ((argc == 2 && two_args == 1 && error_2d_array_check(argv) == 1)
		|| (argc == 2 && word_count(argv[1], ' ') == 0))
		return (NULL);
	if (argc > 2 && word_count(argv[1], ' ') > 1)
		return (write(1, "Error\n", 6), NULL);
	if (argc == 2 && error_str_check(argv[1]) == 0)
	{
		argc = word_count(argv[1], ' ');
		argv = ft_split(argv[1], ' ', argv[0]);
	}
	if (error_2d_array_check(argv) == 0)
	{
		free_argv(argv, two_args);
		return (write(1, "Error\n", 6), NULL);
	}
	if (!argv)
	{
		free_argv(argv, two_args);
		return (NULL);
	}
	return (argv);
}
