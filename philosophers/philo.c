/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:46:26 by amaghat           #+#    #+#             */
/*   Updated: 2021/10/19 15:46:26 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	routine(void);

void	init_supervisor(void)
{
	return ;
}

void	destroy_philo(void)
{
	free(state.status);
}

void	init_philo(char **av)
{
	size_t	i;

	i = 0;
	while (++i < state.data->n + 1)
	{
		if (pthread_create(&(state.status[i - 1].philo),
				NULL, routine, &state.status[i - 1]) != 0)
		{
			printf("Error: Failed to create a thread for philo%d\n",i);
			break ;
		}
		pthread_detach((state.status[i - 1].philo));
		usleep(60);
	}
	init_supervisor();
	destroy_philo();
}

int	main(int argc, char **argv)
{
	state.n_args = argc;
	if (!check_args(argv))
	{
		printf("Error: wrong argument type\n");
		return (1);
	}
	if ((argc == 6) || (argc == 5))
		init_philo(++argv);
	else
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}