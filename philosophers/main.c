/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:13:50 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/18 18:13:50 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	clean(void)
{
	size_t	i;

	i = 1;
	while (i < g_all.data->n + 1)
	{
		if (pthread_mutex_destroy(&(g_all.wise[i - 1].myfork)) != 0)
			return ;
		i++;
	}
	pthread_mutex_destroy(&g_all.print);
	pthread_mutex_destroy(&g_all.inc_meal);
	free(g_all.wise);
}

void	philo_func(char **av)
{
	size_t	i;

	i = 0;
	init_data(av);
	if ((g_all.data->n == 0)
		|| (g_all.data->meals == 0) || check_values())
	{
		printf("Error\n");
		return ;
	}
	while (++i < g_all.data->n + 1)
	{
		if (pthread_create(&(g_all.wise[i - 1].philo),
				NULL, routine, &g_all.wise[i - 1]) != 0)
		{
			printf("Error philo\n");
			break ;
		}
		pthread_detach((g_all.wise[i - 1].philo));
		usleep(60);
	}
	supervisor();
	clean();
}

int	main(int ac, char **av)
{
	g_all.ac = ac;
	if (!check_args(av))
	{
		printf("Error\n");
		return (1);
	}
	if ((ac == 6) || (ac == 5))
		philo_func(++av);
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
