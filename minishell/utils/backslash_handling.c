/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:21:31 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/11 15:43:30 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_bs(char *line, int index)
{
	int	c;

	c = 0;
	if (index == 0)
		return (0);
	while (index-- >= 0)
	{
		if (index >= 0 && line[index] == '\\')
			c++;
		else
			break ;
	}
	return (c);
}

int	bs_position(char **tokens)
{
	int			i;
	int			j;
	t_quote		q;

	i = -1;
	while (tokens[++i])
	{
		j = -1;
		q = init_quote();
		while (tokens[i][++j])
		{
			if (tokens[i][j] == '\\'
				&& q.d_quote == false && q.s_quote == false)
				return (0);
			if (tokens[i][j] == '\'' || tokens[i][j] == '\"')
			{
				q = set_quote_value(tokens[i][j], q);
			}
		}
	}
	return (1);
}
