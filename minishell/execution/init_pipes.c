/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:56:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/11 17:15:41 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*get_fds_files(int index, t_execution *execution)
{
	int		i;
	int		*fds;

	i = 0;
	while (execution[index].files[i])
		i++;
	fds = malloc(sizeof(int) * i);
	i = -1;
	while (execution[index].files[++i])
	{
		fds[i] = get_fd(index, execution, i);
	}
	return (fds);
}

void	close_all_fds(int *pipes, int nb_pipes)
{
	int		i;

	i = -1;
	while (++i < nb_pipes * 2)
	{
		close(pipes[i]);
	}
}

int	*init_pipes(int nb_pipes)
{
	int		i;
	int		*pipes;

	i = -1;
	pipes = malloc(sizeof(int) * 2 * nb_pipes);
	while (++i < nb_pipes)
	{
		pipe(pipes + i * 2);
	}
	return (pipes);
}
