#include "philo.h"

t_infos	*eating(t_infos *info, int id)
{
	pthread_mutex_lock(&info->forks[id]);
	pthread_mutex_lock(&info->prints);
	printf("%lld %d has taken a fork\n", ft_gettime()-info->start, id+1);
	pthread_mutex_unlock(&info->prints);
	pthread_mutex_lock(&info->forks[(id + 1) % info->number]);
	pthread_mutex_lock(&info->prints);
	printf("%lld %d has taken a fork\n", ft_gettime()-info->start, id+1);
	pthread_mutex_unlock(&info->prints);
	pthread_mutex_lock(&info->is_eating[id]);
	info->philo[id].last_eat = ft_gettime();
	info->philo[id].eating = 1;
	info->philo[id].nb_meals++;
	pthread_mutex_lock(&info->prints);
	printf("%lld %d is eating\n", ft_gettime()-info->start, id+1);
	pthread_mutex_unlock(&info->prints);
	my_sleep(info->eat);
	info->philo[id].eating = 0;
	pthread_mutex_unlock(&info->is_eating[id]);
	pthread_mutex_unlock(&info->forks[id]);
	pthread_mutex_unlock(&info->forks[(id + 1) % info->number]);
	return (info);
}

void	*routine(void *arg)
{
	int		id;
	t_infos	*info;

	id = *(int *)arg;
	info = statlist();
	info->philo[id].nb_meals = 0;
	info->philo[id].eating = 0;
	while (1)
	{
		info = eating(info, id);
		pthread_mutex_lock(&info->prints);
		printf("%lld %d is sleeping\n", ft_gettime()-info->start, id+1);
		pthread_mutex_unlock(&info->prints);
		my_sleep(info->sleep);
		pthread_mutex_lock(&info->prints);
		printf("%lld %d is thinking\n", ft_gettime()-info->start, id+1);
		pthread_mutex_unlock(&info->prints);
	}
	return (0);
}
