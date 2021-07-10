/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:55:41 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/05 18:05:34 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar_fd(nbr % 10 + '0', 1);
	}
	else
		ft_putchar_fd(nbr % 10 + '0', 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *s)
{
	unsigned int	num;
	int				sign;
	int				i;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] == '\n'
		|| s[i] == '\t'
		|| s[i] == '\r'
		|| s[i] == '\v'
		|| s[i] == '\f'
		|| s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		num = num * 10 + s[i++] - '0';
	return (num * sign);
}
