/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_export_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:50:05 by amaghat           #+#    #+#             */
/*   Updated: 2021/10/12 16:50:51 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *wrong_arg)
{
	ft_putstr_fd(KRED, 2);
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(wrong_arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

void	print_export_errors(char **args)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
		{
			print_error(args[i]);
		}
	}
}

int	is_wrong_arg(char *arg)
{
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
	{
		return (1);
	}
	return (0);
}
