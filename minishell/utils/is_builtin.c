/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:58:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/09 15:58:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_builtin(char *cmd)
{
	if (cmd[0] == ' ' || cmd[0] == '\'' || cmd[0] == '\"')
		cmd++;
	if (ft_strcmp(cmd, "echo") == 0)
		return ("builtin_echo");
	if (ft_strcmp(cmd, "cd") == 0)
		return ("builtin_cd");
	if (ft_strcmp(cmd, "pwd") == 0)
		return ("builtin_pwd");
	if (ft_strcmp(cmd, "export") == 0)
		return ("builtin_export");
	if (ft_strcmp(cmd, "unset") == 0)
		return ("builtin_unset");
	if (ft_strcmp(cmd, "env") == 0)
		return ("builtin_env");
	if (ft_strcmp(cmd, "exit") == 0)
		return ("builtin_exit");
	return ("go_back");
}
