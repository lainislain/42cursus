/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:47:15 by amaghat           #+#    #+#             */
/*   Updated: 2020/12/02 04:07:25 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_print_char(char **format, int *res)
{
	write(1, *format, 1);
	(*format)++;
	(*res)++;
}

char	*ft_upper(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			res[i] = str[i] - 32;
		else
			res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_test_conv(char c)
{
	if (c == '%' || c == 'd' || c == 'i' || c == 'c' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == 'p' || c == 's')
		return (1);
	else
		return (0);
}
