/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:01:07 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/11 17:18:44 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dollar_is_present(char *str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '$')
			count++;
	}
	return (count);
}

char	*expand_dollars(char *str)
{
	int		i;
	char	*content;
	char	*tmp;

	i = -1;
	content = ft_strdup("");
	while (str[++i])
	{
		if (str[i] != '$')
		{
			content = ft_charjoin(content, str[i]);
		}
		else
		{
			tmp = sub_dollar(str, i);
			content = ft_strjoin(content, tmp);
			i += dollar_len(str, i) - 1;
		}
	}
	return (content);
}

char	*expand_quotes(char *content, int index)
{
	int		nb_dollars;
	char	*tmp;

	tmp = ft_substr(content, index + 1, ft_strlen(content) - 2 - index);
	nb_dollars = dollar_is_present(tmp);
	if (content[index] == '\"' && nb_dollars != 0)
	{
		tmp = expand_dollars(tmp);
	}
	return (tmp);
}

t_tokens	select_quotes(t_tokens tokens)
{
	int		i;
	int		dqIndex;
	char	*tmp_token;

	i = -1;
	while (tokens.tokens[++i])
	{
		dqIndex = 0;
		if (i != 0)
			dqIndex++;
		if (tokens.tokens[i][dqIndex] == '\"'
			|| tokens.tokens[i][dqIndex] == '\'')
		{
			tmp_token = tokens.tokens[i];
			tokens.tokens[i]
				= expand_quotes(tokens.tokens[i], dqIndex);
			free(tmp_token);
		}
	}
	return (tokens);
}

void	expand_quotes_dollar(t_tokens *tokens)
{
	int		i;

	i = -1;
	while (++i < tokens[0].pipe)
	{
		tokens[i] = select_quotes(tokens[i]);
	}
	execution(tokens);
}
