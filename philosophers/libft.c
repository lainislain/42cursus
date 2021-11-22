/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:02:48 by amaghat           #+#    #+#             */
/*   Updated: 2021/11/22 15:02:48 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int		x;
	int		t;

	x = 0;
	t = 1;
	if (!*s)
		return (0);
	while (*s == ' ' || *s <= '\n' || *s == '\v' || *s == '\r'
		|| *s == '\t' || *s == '\f')
		s++;
	if (*s == '-')
		t *= -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9' && *s)
	{
		if (t > 0 && x < 0)
			return (-1);
		if (t < 0 && x < 0)
			return (0);
		x = (x * 10) + *s - '0';
		s++;
	}
	return (x * t);
}
