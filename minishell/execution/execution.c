/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:45:33 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/11 15:38:41 by abelarif         ###   ########.fr       */
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

char	*get_exec_command(t_tokens tokens)
{
	int		i;

	i = -1;
	while (tokens.tokens[++i])
	{
		if (tokens.type[i] == CMD || tokens.type[i] == -CMD)
			return (ft_strdup(tokens.tokens[i]));
	}
	return (NULL);
}

t_execution	*init_execution(t_tokens *tokens)
{
	int				i;
	t_execution		*execution;

	i = -1;
	execution = malloc(sizeof(t_execution) * tokens[0].pipe);
	while (++i < tokens[0].pipe)
	{
		execution[i].nb_pipelines = tokens[0].pipe;
		execution[i].command = get_exec_command(tokens[i]);
		execution[i].exec_path = get_exec_path(tokens[i], get_paths());
		execution[i].args = get_execution_args(tokens[i], execution[i].command);
		execution[i].args_type = get_execution_types(tokens[i]);
		execution[i].files = get_execution_files(tokens[i]);
		execution[i].files_type = get_execution_files_type(tokens[i]);
	}
	return (execution);
}

void	reset_stdio(int exit_status, int tmp_in, int tmp_out)
{
	char	*str_exit;

	str_exit = ft_itoa(exit_status);
	set_env("?", str_exit);
	dup2(tmp_in, STDIN);
	dup2(tmp_out, STDOUT);
	free(str_exit);
}

void	cases_redirection(t_execution *execution)
{
	int		tmp_input_fd;
	int		tmp_output_fd;

	tmp_input_fd = dup(STDIN);
	tmp_output_fd = dup(STDOUT);
	if (execution[0].exec_path
		&& ft_strncmp(execution[0].exec_path, "builtin", 7) == 0
		&& execution[0].nb_pipelines == 1 && execution[0].files[0])
	{
		execution[0].fds = get_fds_files(0, execution);
		if (check_redirections_errors(0, execution) != -1)
			dup_in_out(0, NULL, execution);
		else
		{
			set_env("?", "1");
			return ;
		}
		reset_stdio(simple_builtin(execution, 0), tmp_input_fd, tmp_output_fd);
	}
	else if (execution[0].exec_path && ft_strncmp(execution[0].exec_path,
			"builtin", 7) == 0 && execution[0].nb_pipelines == 1)
		simple_builtin(execution, 0);
	else
		execute_line(execution);
}

void	execution(t_tokens *tokens)
{
	t_execution		*execution;

	execution = init_execution(tokens);
	heredocs_parsing(execution);
	cases_redirection(execution);
	free_execution(execution);
}
