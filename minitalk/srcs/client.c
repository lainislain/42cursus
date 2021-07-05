/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:02:13 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/05 18:05:43 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	signal_sender(char c, pid_t pid)
{
	int	i;
	int	k;
	int check;

	i = 8;
	while (i-- > 0)
	{
		k = c >> i;
		if (k & 1)
			check = kill (pid, SIGUSR1);
		else
			check = kill (pid, SIGUSR2);
		if (check == -1)
		{
			ft_putstr_fd("=> Error\n Wrong PID\n", 1);
			exit(EXIT_FAILURE);
		}
		usleep (100);
	}
}	

int	main(int ac, char **av)
{
	int		i;

	if (ac != 3)
		ft_putstr_fd("=> Error\nEnter 2 and only 2 arguments\n", 1);
	i = 0;
	while (i < ft_strlen(av[2]))
		signal_sender(av[2][i++], ft_atoi(av[1]));
	signal_sender('\n', ft_atoi(av[1]));
	ft_putstr_fd("=> Message sent succussfully\n", 1);
	return (0);
}