/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:51:06 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 15:51:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_input(int index, int input_fd, int *pipes, t_execution *execution)
{
	if (input_fd == -1 && index != 0)
	{
		dup2(pipes[index * 2 - 2], STDIN);
	}
	else if (input_fd != -1)
	{
		dup2(execution[index].fds[input_fd], STDIN);
	}
}

void	dup_output(int index, int output_fd, int *pipes, t_execution *execution)
{
	if (output_fd == -1 && index != execution[0].nb_pipelines - 1)
	{
		dup2(pipes[index * 2 + 1], STDOUT);
	}
	else if (output_fd != -1)
	{
		dup2(execution[index].fds[output_fd], STDOUT);
	}
}

void	dup_in_out(int index, int *pipes, t_execution *execution)
{
	int		i;
	int		in_index;
	int		out_index;

	i = -1;
	in_index = -1;
	out_index = -1;
	while (execution[index].files[++i])
	{
		if (is_input_redir(execution[index].files_type[i])
			&& execution[index].fds[i] != -1)
			in_index = i;
		else if (is_output_redir(execution[index].files_type[i])
			&& execution[index].fds[i] != -1)
			out_index = i;
	}
	dup_input(index, in_index, pipes, execution);
	dup_output(index, out_index, pipes, execution);
}

int	get_fd(int index, t_execution *execution, int i)
{
	int		fd;
	char	*heredoc_path;

	fd = 0;
	if (abs_value(execution[index].files_type[i]) == abs_value(REDI0))
	{
		fd = open(execution[index].files[i], O_RDONLY, 0644);
	}
	else if (abs_value(execution[index].files_type[i]) == abs_value(HEREDOC))
	{
		heredoc_path = ft_strjoin("/tmp/", execution[index].files[i]);
		fd = open(heredoc_path, O_RDONLY, 0644);
		free(heredoc_path);
	}
	else if (abs_value(execution[index].files_type[i]) == abs_value(REDO0))
	{
		fd = open(execution[index].files[i],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (abs_value(execution[index].files_type[i]) == abs_value(REDO1))
	{
		fd = open(execution[index].files[i],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	return (fd);
}
