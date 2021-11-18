/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:14:10 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/18 18:14:10 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*p;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p1[i] != '\0' && p2[i] != '\0' && p1[i] == p2[i] && i < n - 1)
		i++;
	return (p1[i] - p2[i]);
}

int	all_meals(void)
{
	size_t	i;

	i = 0;
	while (i < g_all.data->n)
	{
		if (g_all.wise[i].n_meals > g_all.data->meals + 1)
			return (1);
		i++;
	}
	return (0);
}

void	supervisor(void)
{
	size_t	i;
	int		f;

	i = 1;
	f = 0;
	while (!f)
	{
		i = 0;
		if ((g_all.ac == 6) && (all_meals() == 1))
		{
			f = 1;
			break ;
		}
		while (++i < g_all.data->n + 1)
		{
			if ((check_philo(&g_all.wise[i - 1]) == 1)
				&& !(g_all.wise[i - 1].is_eating))
			{
				f = 1;
				print_to_screen(i, "is dead");
				break ;
			}
		}
		usleep(5);
	}
}

void	eat(t_book *philo)
{
	size_t	id;

	id = philo->id;
	pthread_mutex_lock(&g_all.wise[(id) % g_all.data->n].myfork);
	print_to_screen(id, "picked up a fork");
	pthread_mutex_lock(&g_all.wise[(id + 1) % g_all.data->n].myfork);
	print_to_screen(id, "picked up a fork");
	g_all.wise[id].is_eating = true;
	print_to_screen(id, "is eating");
	g_all.wise[id].start = current_timestamp();
	usleeper2(g_all.data->time_to_eat);
	if (g_all.ac == 6)
	{
		pthread_mutex_lock(&g_all.inc_meal);
		(g_all.wise[id].n_meals)++;
		pthread_mutex_unlock(&g_all.inc_meal);
	}
	pthread_mutex_unlock(&g_all.wise[(id) % g_all.data->n].myfork);
	pthread_mutex_unlock(&g_all.wise[(id + 1) % g_all.data->n].myfork);
	g_all.wise[id].is_eating = false;
}
