/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:14:00 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/18 18:14:00 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_values(void)
{
	if (g_all.data->n > __INT_MAX__ || g_all.data->time_to_die > __INT_MAX__)
		return (1);
	if (g_all.data->time_to_eat > __INT_MAX__
		|| g_all.data->time_to_sleep > __INT_MAX__)
		return (1);
	if (g_all.data->meals > __INT_MAX__)
		return (1);
	return (0);
}