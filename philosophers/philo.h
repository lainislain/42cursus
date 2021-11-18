/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:14:03 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/18 18:14:03 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	size_t	n;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	meals;
}	t_philo;

typedef struct s_book
{
	pthread_t			philo;
	size_t				id;
	size_t				start;
	size_t				last_m;
	size_t				n_meals;
	int					flag;
	pthread_mutex_t		myfork;
	bool				is_eating;
	bool				is_sleeping;
}	t_book;

typedef struct s_global
{
	t_book			*wise;
	struct timeval	startp;
	pthread_mutex_t	print;
	pthread_mutex_t	inc_meal;
	t_philo			*data;
	int				ac;
}			t_global;

t_global	g_all;

double		current_timestamp(void);
void		print_to_screen(size_t id, char *msg);
void		sleeper( t_book *philo);
double		no_time(int id);
void		eat(t_book *philo);
int			check_philo(t_book *philo);
void		*routine(void *arg);
void		philo_func(char **av);
void		supervisor(void);
void		clean(void);
void		usleeper2(double time);
int			ft_atoi(const char *str);
int			ft_isdigit(char c);
int			check_args(char **av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
void		init_data(char **av);
int			check_values(void);

#endif
