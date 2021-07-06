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

int		ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int     ft_isnum(char *str)
{
    int     i;
    int     n;

    if (!str || !str[0])
        return (0);
    i = 0;
    n = ft_strlen(str);
    while (i < n)
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

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
			ft_putstr_fd("=> Error\n Wrong PID\n", 1);
		usleep (100);
	}
}	

int	main(int ac, char **av)
{
	int		i;
	static char acknmsg[] = "\n-> Message received successfully";

	if (ac != 3)
		ft_putstr_fd("=> Error\nEnter 2 and only 2 arguments\n", 1);
	else if (!ft_isnum(av[1]))
		ft_putstr_fd("=> Error\nPID should be a positive integer\n", 1);
	i = 0;
	while (av[2][i])
		signal_sender(av[2][i++], ft_atoi(av[1]));
	i = 0;
	while (acknmsg[i])
		signal_sender(acknmsg[i++], ft_atoi(av[1]));
	signal_sender('\n', ft_atoi(av[1]));
	ft_putstr_fd("-> Message sent successfully\n", 1);
	return (0);
}