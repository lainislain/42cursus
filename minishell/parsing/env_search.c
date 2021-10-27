/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:52:14 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:52:37 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_search(char *str, int index)
{
	int			i;
	int			lensrc;
	char		*env;

	env = NULL;
	i = -1;
	if (index != 0)
		index = 1;
	lensrc = ft_strlen(str + index);
	while (g_env.sorted[++i])
	{
		if (ft_strncmp(str + 1 + index, g_env.sorted[i], lensrc - 1) == 0
			&& g_env.sorted[i][lensrc - 1] == '=')
		{
			env = ft_substr(g_env.sorted[i], lensrc,
					ft_strlen(g_env.sorted[i]) - lensrc + 2);
			free(str);
			str = NULL;
			return (env);
		}
	}
	free(str);
	str = NULL;
	return (ft_strdup(""));
}
