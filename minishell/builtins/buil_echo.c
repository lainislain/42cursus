/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:28:27 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:43:18 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	skip_new_line(char **args)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (ft_strcmp(args[i], "-n"))
		{
			return (i);
		}
	}
	return (i);
}

int	builtin_echo(char **args, int *types)
{
	int		i;
	int		new_line;
	char	**new_args;

	i = -1;
	new_line = 1;
	if (count(args) == 0)
	{
		printf("\n");
		return (0);
	}
	new_args = join_args(args, types);
	i = skip_new_line(new_args);
	if (i-- > 0)
		new_line = 0;
	while (new_args[++i])
	{
		printf("%s", new_args[i]);
		if (new_args[i + 1])
			printf(" ");
	}
	if (new_line == 1)
		printf("\n");
	free_arr(new_args);
	return (0);
}
