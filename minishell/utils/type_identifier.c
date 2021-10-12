/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:40:55 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 15:41:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_empty(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}

int	is_protected(int type)
{
	if (type == PROTECTED0 || type == -PROTECTED0)
		return (1);
	if (type == PROTECTED1 || type == -PROTECTED1)
		return (1);
	return (0);
}

int	is_arg(int type)
{
	if (type == ARG || type == -ARG)
		return (1);
	return (0);
}

int	is_cmd(int type)
{
	if (type == CMD || type == -CMD)
		return (1);
	return (0);
}

int	is_redirection(int type)
{
	if (type == REDI0 || type == -REDI0)
		return (1);
	if (type == REDI1 || type == -REDI1)
		return (1);
	if (type == REDO0 || type == -REDO0)
		return (1);
	if (type == REDO1 || type == -REDO1)
		return (1);
	if (type == HEREDOC || type == -HEREDOC)
		return (1);
	return (0);
}
