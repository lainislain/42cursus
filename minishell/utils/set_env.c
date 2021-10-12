/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:38:55 by abelarif          #+#    #+#             */
/*   Updated: 2021/07/17 16:16:42 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	replace_value(int index, char *new_value, int var_len, char **arr)
{
	int		i;
	int		j;
	char	*new_env;
	int		new_len;

	i = -1;
	new_len = ft_strlen(new_value);
	new_env = malloc(sizeof(char) * (new_len + var_len + 1));
	if (new_env == NULL)
		ft_error("MALLOC", 1);
	while (++i < var_len)
	{
		new_env[i] = arr[index][i];
	}
	j = -1;
	while (++j < new_len)
	{
		new_env[i] = new_value[j];
		i++;
	}
	new_env[i] = '\0';
	free(arr[index]);
	arr[index] = new_env;
}

void	set_env(char *env, char *new_value)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(env);
	while (g_env.env[++i])
	{
		if (ft_strncmp(env, g_env.env[i], len) == 0)
		{
			replace_value(i, new_value, len, g_env.env);
			break ;
		}
	}
	i = -1;
	while (g_env.sorted[++i])
	{
		if (ft_strncmp(env, g_env.sorted[i], len) == 0)
		{
			replace_value(i, new_value, len, g_env.sorted);
			break ;
		}
	}
}
