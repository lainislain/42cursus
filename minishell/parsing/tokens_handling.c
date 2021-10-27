/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:16:03 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 16:38:06 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_dollar(char *line, int index)
{
	if (line[index + 1] && line[index + 1] == '$')
		return (index + 2);
	index++;
	while (line[index])
	{
		if (line[index] == '$' || line[index] == ' ' || line[index] == '\t'
			|| line[index] == '\'' || line[index] == '\"' || line[index] == '>'
			|| line[index] == '<' || line[index] == '\0')
			return (index);
		else
			index++;
	}
	return (index);
}

int	token_word(char *line, int index)
{
	while (line[index])
	{
		if (line[index] == '$' || line[index] == ' ' || line[index] == '\t'
			|| line[index] == '>'
			|| line[index] == '<' || line[index] == '\0')
			return (index);
		else if ((line[index] == '\'' || line[index] == '\"')
			&& (count_bs(line, index) % 2 == 0))
			return (index);
		else
			index++;
	}
	return (index);
}

int	token_quotes(char *line, int index)
{
	int	i;

	i = index + 1;
	while (line[i])
	{
		if (line[i] == line[index] && line[index] == '\'')
			return (i + 1);
		if (line[i] == line[index] && (count_bs(line, i) % 2 == 0))
			return (i + 1);
		i++;
	}
	return (-1);
}

int	token_redir(char *line, int index)
{
	int					i;

	i = index;
	while (line[i])
	{
		if (line[i] == line[index])
		{
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char	*get_token(char *line, int flag)
{
	static int			start = 0;
	char				*token;
	int					end;
	int					bef;

	token = NULL;
	bef = 1;
	if (flag == 0)
		start = 0;
	if (start == 0)
		bef = 0;
	while (line[start])
	{
		start = skip_spaces(line, start);
		if (line[start])
		{
			end = get_end(line, start);
			if (end != -1)
				token = ft_subtoken(line, start - bef, end);
			start = end;
			return (token);
		}
	}
	return (token);
}
