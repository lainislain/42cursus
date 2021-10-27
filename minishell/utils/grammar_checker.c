/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:47:59 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 15:33:02 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	no_redirection_file_error(int file_type)
{
	if (!(file_type == FILE || file_type == -FILE
			|| file_type == EOFHEREDOC
			|| file_type == -EOFHEREDOC))
	{
		ft_error("No redirection File", 0);
		return (1);
	}
	return (0);
}

int	redirection_grammar(t_tokens *tokens)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tokens->pipe)
	{
		j = -1;
		while (tokens[i].tokens[++j])
		{
			if (is_redirection(tokens[i].type[j]) != 0)
			{
				if (tokens[i].tokens[j + 1])
				{
					if (no_redirection_file_error(tokens[i].type[j + 1]) == 1)
						return (0);
				}
				else
				{
					ft_error("No redirection File", 0);
					return (0);
				}
			}
		}
	}
	return (1);
}

int	grammar_checker(char **commands, t_tokens *tokens)
{
	int		i;

	i = -1;
	while (commands[++i])
	{
		if (is_empty(commands[i]) == 1)
		{
			ft_error("syntax error near unexpected token `|'", 0);
			return (0);
		}
	}
	i = -1;
	if (redirection_grammar(tokens) == 0)
	{
		return (0);
	}
	return (1);
}
