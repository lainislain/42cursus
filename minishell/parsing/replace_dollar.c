/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:18:54 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:52:32 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dollar_handling(char **tok, int index)
{
	char		*str;

	str = ft_strdup(*tok);
	free(*tok);
	*tok = NULL;
	*tok = env_search(str, index);
	if (*tok == NULL)
		ft_error("tok", 1);
}

char	**split_dollar_signe(char **old, int index)
{
	int		i;
	int		c;
	char	**content;
	char	**new;

	i = -1;
	content = ft_split(old[index], ' ');
	new = malloc(sizeof(char *) * (count(old) + count(content)));
	while (++i < index)
		new[i] = ft_strdup(old[i]);
	c = -1;
	while (content[++c])
	{
		new[i] = ft_strdup(content[c]);
		i++;
	}
	c = index;
	while (old[++c])
	{
		new[i] = ft_strdup(old[c]);
		i++;
	}
	new[i] = NULL;
	free_dollar(old, content);
	return (new);
}

void	set_types(t_tokens *tok, int oldlen, int newlen, int index)
{
	int		i;
	int		c;
	int		*newtype;

	i = -1;
	newtype = malloc(sizeof(int) * newlen);
	while (++i < index)
		newtype[i] = tok->type[i];
	c = -1;
	while (++c < newlen - oldlen + 1)
	{
		if (c == 0)
			newtype[i] = PROTECTED0;
		else
			newtype[i] = PROTECTED1;
		i++;
	}
	c = index;
	while (++c < oldlen)
	{
		newtype[i] = tok->type[c];
		i++;
	}
	free(tok->type);
	tok->type = newtype;
}

int	replace_dollar_helper(t_tokens *tok, int *i, t_data *data)
{
	if ((tok->tokens[*i][1] == '$' && *i)
				|| (*i == 0 && tok->tokens[*i][0] == '$'))
	{
		dollar_handling(&(tok->tokens[*i]), *i);
		tok->tokens = split_dollar_signe(tok->tokens, *i);
		data->presence = 1;
		data->newlen = count(tok->tokens);
		if (data->oldlen != data->newlen)
			set_types(tok, data->oldlen, data->newlen, *i);
		else if (tok->type[*i] < 0)
			tok->type[*i] = -PROTECTED0;
		else
			tok->type[*i] = PROTECTED0;
		if (tok->type[0] == PROTECTED0 || tok->type[0] == -PROTECTED0)
			tok->type[*i] = -CMD;
		(*i) += data->newlen - data->oldlen;
		data->oldlen = data->newlen;
		return (1);
	}
	return (0);
}

t_tokens	replace_dollar(t_tokens *tok)
{
	int			i;
	t_data		data;

	data.presence = 1;
	data.oldlen = count(tok->tokens);
	data.newlen = data.oldlen;
	i = -1;
	while (data.presence)
	{
		data.presence = 0;
		while (tok->tokens[++i])
		{
			if (replace_dollar_helper(tok, &i, &data) == 1)
				break ;
		}
		tok->nb = i;
	}
	return (*tok);
}
