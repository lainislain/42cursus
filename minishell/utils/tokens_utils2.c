/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:37:08 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 16:38:27 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_tokens(char *line)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (line[i])
	{
		if (line[i])
		{
			i = skip_spaces(line, i);
		}
		if (line[i])
		{
			i = get_end(line, i);
			if (i == -1)
				return (c);
			c++;
		}
		else
			return (c);
	}
	return (c);
}

int	skip_spaces(char *line, int index)
{
	while (line[index])
	{
		if (line[index] == ' ' || line[index] == '\t')
			index++;
		else
			return (index);
	}
	return (index);
}

int	get_end(char *line, int index)
{
	if ((line[index] == '>' || line[index] == '<')
		&& count_bs(line, index) % 2 == 0)
	{
		index = token_redir(line, index);
	}
	else if (line[index] == '$'
		&& count_bs(line, index) % 2 == 0)
	{
		index = token_dollar(line, index);
	}
	else if (line[index] == '\'' || line[index] == '\"')
	{
		index = token_quotes(line, index);
		if (index == -1)
			ft_error("This Shell does not support unclosed quotes.", 0);
	}
	else
	{
		index = token_word(line, index);
	}
	return (index);
}
