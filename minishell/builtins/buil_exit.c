/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:46:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/17 14:28:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	str_is_digit(char *str)
{
	int		i;

	i = 0;
	if (!(str[i] && (str[i] == '-' || ('0' <= str[i] && str[i] <= '9'))))
	{
		return (0);
	}
	while (str[++i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			return (0);
		}
	}	
	return (1);
}

int	builtin_exit(char **args, int is_a_child_process, int counter)
{
	counter = 0;
	while (args[counter])
		counter++;
	if (args[0] == NULL)
		exit(0);
	if (str_is_digit(args[0]) == 0)
	{
		ft_error("exit: numeric argument required", 0);
		if (is_a_child_process == 1)
			return (255);
		exit(255);
	}
	else
	{
		if (counter != 1)
			ft_error("exit: too many arguments", 0);
		else
		{
			if (is_a_child_process == 1)
				exit((unsigned char)ft_atoi(args[0]));
			exit((unsigned char)ft_atoi(args[0]));
		}
	}
	return (0);
}
