/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:04:08 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:51:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	join_bs(char **paths)
{
	int		i;
	char	*tmp;

	i = -1;
	if (paths == NULL)
		return ;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
	}
}

int	max_of(int i, int j)
{
	if (i < j)
		return (j);
	else
		return (i);
}
