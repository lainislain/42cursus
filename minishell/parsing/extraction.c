/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/08 15:37:47 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	extract_pipe_line(char *line)
{
	int					i;
	t_separator			c_separator;
	int					error;

	i = -1;
	error = 0;
	c_separator = get_separator_index(line, '|');
	if (c_separator.nb_separator == 0)
		c_separator.content = ft_split(line, '\0');
	else
		c_separator.content = splitSep(line,
				c_separator.separator_index, c_separator.nb_separator);
	free(c_separator.separator_index);
	c_separator.separator_index = NULL;
	while (c_separator.content[++i])
	{
		if (c_separator.content[i][0] == '|'
			|| c_separator.content[i][0] == ';')
			error = 1;
	}
	if (error == 0)
		extract_tokens(c_separator.content);
	i = -1;
	free_arr(c_separator.content);
}

void	extract_semicolon_line(char *line)
{
	t_separator		cl_separator;

	if (ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
		return ;
	}
	cl_separator = get_separator_index(line, ';');
	if (cl_separator.nb_separator == 0)
	{
		cl_separator.content = ft_split(line, '\0');
		extract_pipe_line(cl_separator.content[0]);
		free(cl_separator.content[0]);
		cl_separator.content[0] = NULL;
		free(cl_separator.content);
	}
	else
	{
		ft_error("This Shell does not support unspecified \
		special characters \";\"", 0);
	}
	free(line);
	free(cl_separator.separator_index);
	cl_separator.separator_index = NULL;
	line = NULL;
}
