/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:52:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/15 12:57:55 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr[i]);
	arr[i] = NULL;
	free(arr);
}

void	add_env(char *variable, char *value, int size)
{
	int		i;
	char	**new_env;
	char	*new_var;
	char	*tmp;

	i = -1;
	new_env = malloc(sizeof(char *) * (size + 2));
	while (g_env.env[++i])
		new_env[i] = ft_strdup(g_env.env[i]);
	tmp = ft_strjoin(variable, "=");
	new_var = ft_strjoin(tmp, value);
	free(tmp);
	tmp = NULL;
	new_env[i++] = new_var;
	new_env[i] = NULL;
	free_arr(g_env.env);
	g_env.env = new_env;
}

char	**set_env(char *variable, char *value)
{
	int		index;
	int		len;
	char	*new;
	char	*tmp;

	index = -1;
	len = ft_strlen(variable);
	while (g_env.env[++index])
		if (strncmp(g_env.env[index], variable, len - 1) == 0
			&& g_env.env[index][len] == '=')
			break ;
	free_arr(g_env.sorted);
	if (g_env.env[index] == NULL)
		add_env(variable, value, index);
	else
	{
		free(g_env.env[index]);
		tmp = ft_strjoin(variable, "=");
		new = ft_strjoin(tmp, value);
		free(tmp);
		g_env.env[index] = new;
	}
	sort_env();
	return (g_env.env);
}
