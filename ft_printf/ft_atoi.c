/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:11:24 by amaghat           #+#    #+#             */
/*   Updated: 2020/12/02 04:22:55 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *s)
{
	int		i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		res = 10 * res + (s[i] - 48);
		i++;
	}
	return (res * sign);
}

int		ft_printper(t_convert convert)
{
	int			res;

	res = 1;
	while (convert.flag == '0' && convert.width > res)
	{
		write(1, "0", 1);
		res++;
	}
	while (convert.flag != '-' && convert.width > res)
	{
		write(1, " ", 1);
		res++;
	}
	write(1, "%", 1);
	while (convert.flag == '-' && convert.width > res)
	{
		write(1, " ", 1);
		res++;
	}
	return (res);
}

int		ft_getnzr(t_convert convert, long long num)
{
	if (convert.prec < ft_getnum(num, 10))
		return (0);
	else
		return (convert.prec - ft_getnum(num, 10));
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n != i && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	printd(long long num)
{
	char		*str;

	str = ft_itoa_base(num, 10);
	write(1, str, ft_getnum((int)num, 10));
	free(str);
	str = NULL;
}
