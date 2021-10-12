/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:59:02 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 17:33:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_input_redir(int file_type)
{
	if (abs_value(file_type) == REDI0)
		return (1);
	if (abs_value(file_type) == HEREDOC)
		return (1);
	return (0);
}

int	is_output_redir(int file_type)
{
	if (abs_value(file_type) == REDO0)
		return (1);
	if (abs_value(file_type) == REDO1)
		return (1);
	return (0);
}

void	child_process_errors(t_execution *execution, int index)
{
	if (execution[index].exec_path == NULL
		&& ft_strlen(execution[index].command))
	{
		command_not_found_error(execution[index].command);
		exit(127);
	}
	else if (ft_strlen(execution[index].exec_path) == 0)
	{
		no_such_file_error(execution[index].command);
		exit(127);
	}	
}

void	child_process(int index, int *pipes, t_execution *execution)
{
	int		ret;

	ret = 0;
	execution[index].fds = get_fds_files(index, execution);
	if (check_redirections_errors(index, execution) != -1)
		dup_in_out(index, pipes, execution);
	else
		exit(1);
	close_all_fds(pipes, execution[0].nb_pipelines - 1);
	child_process_errors(execution, index);
	if (ft_strncmp("builtin", execution[index].exec_path, 7) == 0
		&& execution[index].exec_path)
	{
		exit(simple_builtin(execution + index, 1));
	}
	else
	{
		ret = execve(execution[index].exec_path,
				execution[index].args, g_env.env);
		ft_error(NULL, 0);
		exit(126);
	}
}

void	set_exit_status(int status)
{
	char	*str_exit;

	if (WIFEXITED(status))
	{
		g_env.exit_status = WEXITSTATUS(status);
		str_exit = ft_itoa(g_env.exit_status);
		set_env("?", str_exit);
		free(str_exit);
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
		{
			set_env("?", "131");
			ft_putendl_fd("\\Quit", 2);
		}
		else if (WTERMSIG(status) == SIGINT)
		{
			set_env("?", "130");
		}
	}	
}

void	create_childs(t_execution *execution)
{
	int		i;
	int		*pipes;
	int		status;
	pid_t	pid;

	i = -1;
	pipes = init_pipes(execution[0].nb_pipelines - 1);
	while (++i < execution[0].nb_pipelines)
	{
		g_env.child_flag = 1;
		pid = fork();
		if (pid == 0)
		{
			child_process(i, pipes, execution);
		}
	}
	close_all_fds(pipes, execution[0].nb_pipelines - 1);
	waitpid(-1, &status, 0);
	waitpid(pid, &status, 0);
	set_exit_status(status);
	free(pipes);
}

t_execution	*execute_line(t_execution *execution)
{
	create_childs(execution);
	return (execution);
}
