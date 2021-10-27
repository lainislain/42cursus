/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:36:06 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 15:51:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arr_dup(void)
{
	int	i;

	i = 0;
	while (g_env.env[i])
		i++;
	g_env.sorted = malloc(sizeof(char *) * (i + 1));
	g_env.sorted[i] = NULL;
	i = -1;
	while (g_env.env[++i])
		g_env.sorted[i] = ft_strdup(g_env.env[i]);
}

void	sort_env(void)
{
	int		i;
	int		repeat;
	char	*tmp;

	tmp = NULL;
	repeat = 1;
	arr_dup();
	while (repeat)
	{
		i = -1;
		repeat = 0;
		while (g_env.sorted[++i])
		{
			if (g_env.sorted[i] && g_env.sorted[i + 1]
				&& ft_strncmp(g_env.sorted[i], g_env.sorted[i + 1],
					max_of(ft_strlen(g_env.sorted[i]),
						ft_strlen(g_env.sorted[i + 1]))) > 0)
			{
				tmp = g_env.sorted[i];
				g_env.sorted[i] = g_env.sorted[i + 1];
				g_env.sorted[i + 1] = tmp;
				repeat = 1;
			}
		}
	}
}

void	init_env(char **env)
{
	int		c;

	c = 0;
	g_env.exit_status = 0;
	while (env[c])
		c++;
	g_env.env = malloc(sizeof(char *) * (c + 2));
	if (g_env.env == NULL)
		ft_error("malloc", 1);
	c = -1;
	g_env.env[++c] = ft_strdup("?=0");
	while (env[++c])
	{
		g_env.env[c] = ft_strdup(env[c - 1]);
		if (g_env.env[c] == NULL)
			ft_error("malloc", 1);
	}
	g_env.env[c] = NULL;
	sort_env();
}
