/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_execution_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:13:16 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 17:13:20 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	input_file_error(char *file)
{
	ft_putstr_fd(KRED, 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file or directory", 2);
	ft_putstr_fd(KNRM, 2);
}

int	check_redirections_errors(int index, t_execution *execution)
{
	int		i;

	i = -1;
	while (execution[index].files[++i])
	{
		if (abs_value(execution[index].files_type[i]) == REDI0
			&& execution[index].fds[i] == -1)
		{
			input_file_error(execution[index].files[i]);
			return (-1);
		}
	}
	return (0);
}

void	command_not_found_error(char *command)
{
	ft_putstr_fd(KRED, 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(": command not found", 2);
	ft_putstr_fd(KNRM, 2);
}

void	no_such_file_error(char *command)
{
	ft_putstr_fd(KRED, 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(": No such file or directory", 2);
	ft_putstr_fd(KNRM, 2);
}
