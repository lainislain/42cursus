/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:29:55 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/17 14:29:50 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_variable_index(char *variable)
{
	int		index;
	int		len;

	index = -1;
	len = ft_strlen(variable);
	while (g_env.env[++index])
		if (strncmp(g_env.env[index], variable, len - 1) == 0
			&& g_env.env[index][len] == '=')
			return (index);
	return (-1);
}

void	rm_variable(int index)
{
	int		i;
	int		j;
	int		size;
	char	**new_env;

	i = -1;
	j = 0;
	size = count_arr(g_env.env);
	new_env = malloc(sizeof(char *) * size);
	while (g_env.env[++i] && i != index)
	{
		new_env[j++] = ft_strdup(g_env.env[i]);
	}
	while (g_env.env[++i])
	{
		new_env[j++] = ft_strdup(g_env.env[i]);
	}
	new_env[size - 1] = NULL;
	free_arr(g_env.env);
	g_env.env = new_env;
	free_arr(g_env.sorted);
	sort_env();
}

int	builtin_unset(char **args)
{
	int		i;
	int		index;

	i = -1;
	while (args[++i])
	{
		index = get_variable_index(args[i]);
		if (index != -1)
		{
			rm_variable(index);
		}
	}
	return (0);
}
