/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:46:21 by amaghat           #+#    #+#             */
/*   Updated: 2021/10/19 15:46:21 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_philo
{
	size_t	n;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	meals;
}	t_philo;

typedef struct s_status
{
	size_t				id;
	size_t				n_meals;
	size_t				start;
	size_t				last_m;
	int					is_eating;
	int					is_sleeping;
	pthread_t			philo;
	pthread_mutex_t		fork;
}	t_status;

typedef struct s_state
{
	t_status		*status;
	t_philo			*data;
	int				n_args;
}	t_state;

t_state		state;

void	init_philo(char **av);
void	destroy_philo(void);

#endif