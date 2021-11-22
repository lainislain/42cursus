/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:02:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/22 15:02:40 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_gettime(void)
{
	struct timeval		time;
	unsigned long long	time_in_mill;

	gettimeofday(&time, NULL);
	time_in_mill = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (time_in_mill);
}

t_infos	*statlist(void)
{
	static t_infos	ret;

	return (&ret);
}

void	ft_sleep(unsigned long long i)
{
	unsigned long long	current;
	unsigned long long	start;

	start = ft_gettime();
	while (1)
	{
		usleep(100);
		current = ft_gettime();
		if (current >= start + i)
			break ;
	}
}
