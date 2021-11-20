#include "philo.h"

int	initialisation(char **argv, int argc)
{
	t_infos		*info;

	info = statlist();
	if (ft_is_alldigit(argv[1]) && ft_is_alldigit(argv[2])
		&& ft_is_alldigit(argv[3]) && ft_is_alldigit(argv[4]))
	{
		info->number = ft_atoi(argv[1]);
		info->die = ft_atoi(argv[2]);
		info->eat = ft_atoi(argv[3]);
		info->sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			if (ft_is_alldigit(argv[5]))
				info->pme = ft_atoi(argv[5]);
			else
				return (1);
		}
		else
			info->pme = -22;
	}
	else
		return (1);
	return (0);
}

int	check_death(void)
{
	t_infos				*info;
	unsigned long long	full;
	unsigned long long	i;

	full = 0;
	i = 0;
	info = statlist();
	while (i < info->number)
	{
		if ((info->die <= (ft_gettime() - info->philo[i].last_eat))
			&& (info->philo[i].eating == 0))
		{
			printf("%lld %lld died\n", ft_gettime()-info->start, i+1);
			return (1);
		}
		if (info->pme >= 0)
			full += (info->philo[i].nb_meals >= info->pme);
		if (full == info->number)
			return (1);
		i++;
	}
	return (0);
}

int	beggin(unsigned long long i, int *id)
{
	t_infos	*info;

	info = statlist();
	while (i < info->number)
	{
		pthread_mutex_init(&info->is_eating[i], NULL);
		pthread_mutex_init(&info->forks[i++], NULL);
	}
	i = -1;
	while (++i < info->number)
	{
		*id = i;
		info->philo[i].last_eat = ft_gettime();
		pthread_create(&info->philo[i].thread, NULL, &routine, id);
		usleep(100);
	}
	while (1)
	{
		if (check_death())
			return (1);
	}
	i = 0;
	while (i < info->number)
		pthread_join(info->philo[i++].thread, NULL);
	return (0);
}

void	free_data(t_infos *info, int *id)
{
	free(info->philo);
	free(info->forks);
	free(info->is_eating);
	free(id);
}

int	main(int argc, char **argv)
{
	t_infos		*info;
	int			*id;

	info = statlist();
	info->start = ft_gettime();
	id = malloc(sizeof (int));
	if (argc == 5 || argc == 6)
	{
		if (initialisation(argv, argc))
			return (1);
		info->philo = malloc((sizeof (t_philosophers)) * info->number);
		info->forks = malloc((sizeof (pthread_mutex_t)) * info->number);
		info->is_eating = malloc((sizeof (pthread_mutex_t)) * info->number);
		if (beggin(0, id))
		{
			free_data(info, id);
			return (1);
		}
	}
	else
	{
		printf("Number of args is unavailable\n");
		return (1);
	}
}
