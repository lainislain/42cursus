/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:09:56 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 17:11:01 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_execution_args_helper(t_tokens tokens, char ***args)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (++i < tokens.nb)
	{
		if ((tokens.type[i] == ARG || tokens.type[i] == -ARG)
			&& (tokens.tokens[i][0] == ' '
			|| tokens.tokens[i][0] == '\'' || tokens.tokens[i][0] == '\"'))
			(*args)[++c] = ft_strdup(tokens.tokens[i] + 1);
		else if (tokens.type[i] == -ARG || tokens.type[i] == ARG)
			(*args)[++c] = ft_strdup(tokens.tokens[i]);
		else if (tokens.type[i] == PROTECTED0 || tokens.type[i] == -PROTECTED0
			|| tokens.type[i] == PROTECTED1 || tokens.type[i] == -PROTECTED1)
			(*args)[++c] = ft_strdup(tokens.tokens[i]);
	}
}

char	**get_execution_args(t_tokens tokens, char *command)
{
	int		i;
	int		c;
	char	**args;

	i = -1;
	c = 0;
	while (++i < tokens.nb)
		if (tokens.type[i] == ARG || tokens.type[i] == -ARG
			|| tokens.type[i] == PROTECTED0 || tokens.type[i] == -PROTECTED0
			|| tokens.type[i] == PROTECTED1 || tokens.type[i] == -PROTECTED1)
			c++;
	args = malloc(sizeof(char *) * (c + 2));
	if (command)
		args[0] = ft_strdup(command);
	else
		args[0] = ft_strdup("");
	args[c + 1] = NULL;
	get_execution_args_helper(tokens, &args);
	return (args);
}

int	*get_execution_types(t_tokens tokens)
{
	int		i;
	int		c;
	int		*types;

	c = 0;
	i = -1;
	while (++i < tokens.nb)
		if (tokens.type[i] == ARG || tokens.type[i] == -ARG
			|| tokens.type[i] == PROTECTED0 || tokens.type[i] == -PROTECTED0
			|| tokens.type[i] == PROTECTED1 || tokens.type[i] == -PROTECTED1)
			c++;
	types = malloc(sizeof(int) * (c + 1));
	i = -1;
	c = 0;
	types[0] = CMD;
	while (++i < tokens.nb)
		if (tokens.type[i] == ARG || tokens.type[i] == -ARG
			|| tokens.type[i] == PROTECTED0 || tokens.type[i] == -PROTECTED0
			|| tokens.type[i] == PROTECTED1 || tokens.type[i] == -PROTECTED1)
			types[++c] = tokens.type[i];
	return (types);
}

int	*get_execution_files_type(t_tokens tokens)
{
	int		i;
	int		c;
	int		*types;

	i = -1;
	c = 0;
	while (++i < tokens.nb)
		if (tokens.type[i] == FILE || tokens.type[i] == -FILE
			|| tokens.type[i] == EOFHEREDOC || tokens.type[i] == -EOFHEREDOC)
			c++;
	types = malloc(sizeof(char *) * c);
	i = -1;
	c = 0;
	while (++i < tokens.nb)
	{
		if (tokens.type[i] == FILE || tokens.type[i] == -FILE
			|| tokens.type[i] == EOFHEREDOC || tokens.type[i] == -EOFHEREDOC)
			types[c++] = tokens.type[i - 1];
	}
	return (types);
}

char	**get_execution_files(t_tokens tokens)
{
	int		i;
	int		c;
	char	**files;

	i = -1;
	c = 0;
	while (++i < tokens.nb)
		if (tokens.type[i] == FILE || tokens.type[i] == -FILE
			|| tokens.type[i] == EOFHEREDOC || tokens.type[i] == -EOFHEREDOC)
			c++;
	files = malloc(sizeof(char *) * (c + 1));
	files[c] = NULL;
	i = -1;
	c = 0;
	while (++i < tokens.nb)
	{
		if (tokens.type[i] == FILE || tokens.type[i] == -FILE
			|| tokens.type[i] == EOFHEREDOC || tokens.type[i] == -EOFHEREDOC)
			files[c++] = ft_strdup(tokens.tokens[i] + 1);
	}
	return (files);
}
