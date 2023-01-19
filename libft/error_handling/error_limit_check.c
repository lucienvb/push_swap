/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_limit_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:58:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 11:58:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	error_limit_check(char **argv)
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
