/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:36:48 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/17 15:26:17 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	no_args(char *old_pwd)
{
	int		ret;
	char	*new_pwd;	

	ret = chdir("/Users/amaghat");
	new_pwd = builtin_pwd(1);
	set_env("OLDPWD", old_pwd);
	set_env("PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
}

int	builtin_cd(char **path)
{
	int		ret;
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = builtin_pwd(1);
	if (path[0] == NULL)
	{
		no_args(old_pwd);
		return (0);
	}
	ret = chdir(path[0]);
	new_pwd = builtin_pwd(1);
	if (ret == -1)
		ft_error(NULL, 0);
	else
	{
		set_env("OLDPWD", old_pwd);
		set_env("PWD", new_pwd);
	}
	free(old_pwd);
	free(new_pwd);
	return (1);
}
