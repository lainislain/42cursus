/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:43:19 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/17 18:32:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_heredocs(t_execution *execution, int index)
{
	int		i;
	int		c;	

	i = -1;
	c = 0;
	while (execution[index].files[++i])
		if (execution[index].files_type[i] == HEREDOC
			|| execution[index].files_type[i] == -HEREDOC)
			c++;
	return (c);
}

void	write_fd_heredocs(int fd, char **eof, int *done)
{
	int		c;
	char	*line;
	int		index_done;

	c = count_arr(eof);
	index_done = 0;
	while (done[c - 1] != 1)
	{
		line = readline("HEREDOC >");
		if (ft_strcmp(eof[index_done], line) == 0)
		{
			done[index_done++] = 1;
		}
		else if (done[c - 2] == 1)
		{
			ft_putendl_fd(line, fd);
		}
		free(line);
	}
}

void	heredocs_prompt(char **eof)
{
	int		i;
	int		c;
	int		*done;
	char	*file_path;
	int		fd;

	i = -1;
	c = count_arr(eof);
	done = malloc(sizeof(int) * c);
	while (++i < c)
	{
		done[i] = 0;
	}
	file_path = ft_strjoin("/tmp/", eof[c - 1]);
	fd = open(file_path, O_CREAT | O_RDWR, S_IRWXU);
	write_fd_heredocs(fd, eof, done);
	close(fd);
	free(done);
	free(file_path);
}

void	expand_heredocs(t_execution *execution, int index)
{
	int		i;
	int		c;
	char	**eof;

	i = -1;
	c = count_heredocs(execution, index);
	eof = malloc(sizeof(char *) * (c + 1));
	eof[c] = NULL;
	i = -1;
	c = 0;
	while (execution[index].files[++i])
	{
		if (execution[index].files_type[i] == HEREDOC
			|| execution[index].files_type[i] == -HEREDOC)
		{
			eof[c++] = ft_strdup(execution[index].files[i]);
		}
	}
	heredocs_prompt(eof);
	free_arr(eof);
}

void	heredocs_parsing(t_execution *execution)
{
	int		i;
	int		j;

	i = -1;
	while (++i < execution[0].nb_pipelines)
	{
		j = -1;
		while (execution[i].files[++j])
		{
			if (execution[i].files_type[j] == HEREDOC
				|| execution[i].files_type[j] == -HEREDOC)
			{
				expand_heredocs(execution, i);
				break ;
			}
		}
	}
}
