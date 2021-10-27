/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:38:32 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 16:51:27 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_paths(void)
{
	int		i;
	int		cmp;
	char	**paths;

	i = -1;
	while (g_env.env[++i])
	{
		cmp = ft_strncmp(g_env.env[i], "PATH=", 5);
		if (cmp == 0)
			break ;
	}
	if (g_env.env[i] == NULL)
		return (ft_split("", '\0'));
	else
	{
		paths = ft_split(g_env.env[i] + 5, ':');
		if (paths == NULL)
			ft_error(NULL, 1);
		join_bs(paths);
		return (paths);
	}
}

void	free_paths(char **paths)
{
	int		i;

	i = -1;
	while (paths[++i])
	{
		free(paths[i]);
		paths[i] = NULL;
	}
	free(paths);
	paths = NULL;
}

char	*join_paths(t_tokens tokens, int index, char **paths)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*cmd;

	i = -1;
	cmd = tokens.tokens[index];
	if (index != 0)
		cmd = tokens.tokens[index] + 1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		fd = open(tmp, O_RDONLY, 0666);
		if (fd < 0)
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			close(fd);
			return (tmp);
		}
	}
	return (NULL);
}

char	*get_exec_path_helper(t_tokens token,
		char **paths, char *exec_path, int i)
{
	int		fd;
	int		index;

	index = 0;
	if (exec_path == NULL)
	{
		if (i != 0)
			index++;
		fd = open(token.tokens[i] + index, O_RDONLY, 0666);
		if (fd > 0)
		{
			close(fd);
			free_paths(paths);
			return (ft_strdup(token.tokens[i] + index));
		}
	}
	if (paths[0] == NULL)
	{
		free_paths(paths);
		return (ft_strdup(""));
	}
	free_paths(paths);
	return (exec_path);
}

char	*get_exec_path(t_tokens token, char **paths)
{
	int		i;
	char	*exec_path;

	i = -1;
	while (++i < token.nb)
	{
		if (token.type[i] == CMD || token.type[i] == -CMD)
			break ;
	}
	if (token.tokens[i] == NULL)
	{
		free_paths(paths);
		return (NULL);
	}
	if (ft_strncmp(is_builtin(token.tokens[i]), "builtin", 6) == 0)
	{
		free_paths(paths);
		return (ft_strdup(is_builtin(token.tokens[i])));
	}
	exec_path = join_paths(token, i, paths);
	return (get_exec_path_helper(token, paths, exec_path, i));
}
