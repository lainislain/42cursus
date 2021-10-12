/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:26:02 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/11 17:18:05 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	simple_builtin(t_execution *execution, int exit_flag)
{
	int		ret;
	char	*str_exit;

	ret = 0;
	if (!ft_strcmp(execution[0].exec_path, "builtin_cd"))
		ret = builtin_cd(execution[0].args + 1);
	else if (!ft_strcmp(execution[0].exec_path, "builtin_echo"))
		ret = builtin_echo(execution[0].args + 1, execution[0].args_type + 1);
	else if (!ft_strcmp(execution[0].exec_path, "builtin_env"))
		ret = builtin_env();
	else if (!ft_strcmp(execution[0].exec_path, "builtin_exit"))
		ret = builtin_exit(execution[0].args + 1, exit_flag, 0);
	else if (!ft_strcmp(execution[0].exec_path, "builtin_pwd"))
	{
		builtin_pwd(0);
		ret = 0;
	}
	else if (!ft_strcmp(execution[0].exec_path, "builtin_unset"))
		ret = builtin_unset(execution[0].args + 1);
	else if (!ft_strcmp(execution[0].exec_path, "builtin_export"))
		ret = builtin_export(execution[0].args + 1, execution[0].args_type + 1);
	str_exit = ft_itoa(ret);
	set_env("?", str_exit);
	free(str_exit);
	return (ret);
}
