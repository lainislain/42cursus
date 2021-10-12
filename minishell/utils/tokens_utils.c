/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:06:45 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:47:33 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_tok(char *line, int nb)
{
	char	**tok;
	int		i;

	i = -1;
	tok = malloc(sizeof(char *) * (nb + 1));
	if (tok == NULL)
		ft_error("malloc", 1);
	tok[nb] = NULL;
	while (++i < nb)
	{
		tok[i] = get_token(line, i);
	}
	return (tok);
}

int	is_redirection_value(char *content, int len)
{
	if (ft_strncmp(">", content, max_of(1, len)) == 0)
		return (REDO0);
	else if (ft_strncmp("<", content, max_of(1, len)) == 0)
		return (REDI0);
	else if (ft_strncmp(">>", content, max_of(1, len)) == 0)
		return (REDO1);
	else if (ft_strncmp("<<", content, max_of(1, len)) == 0)
		return (HEREDOC);
	return (0);
}

void	set_tok_value_helper(int i, int *cmd, int *type)
{
	if (i && ((-REDI0 <= type[i - 1] && type[i - 1] <= -REDO0)
			|| (REDO0 <= type[i - 1] && type[i - 1] <= REDI0)))
		type[i] *= FILE;
	else if (i && (type[i - 1] == HEREDOC || type[i - 1] == -HEREDOC))
		type[i] *= EOFHEREDOC;
	else if (*cmd == 0)
	{
		*cmd = 1;
		type[i] *= CMD;
	}
	else
		type[i] *= ARG;
}

void	set_tok_value(int *type, char **content)
{
	int		i;
	int		cmd;
	int		index;
	int		len;

	i = -1;
	cmd = 0;
	while (content[++i])
	{
		if (i == 0)
			index = 0;
		else
			index = 1;
		len = ft_strlen(content[i] + index);
		if (is_redirection_value(content[i] + index, len))
			type[i] *= is_redirection_value(content[i] + index, len);
		else
			set_tok_value_helper(i, &cmd, type);
	}
}

int	*set_tok_types(t_tokens tok)
{
	int			*type;

	type = malloc(sizeof(int) * tok.nb);
	if (type == NULL)
	{
		ft_error("set_tok_types", 1);
	}
	set_separator_type(type, tok.tokens);
	set_tok_value(type, tok.tokens);
	return (type);
}
