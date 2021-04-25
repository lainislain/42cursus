/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:37:44 by amaghat           #+#    #+#             */
/*   Updated: 2020/12/02 03:13:33 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_getnum(long long n, unsigned int base)
{
	int			num;

	if (n == 0)
		return (1);
	num = 0;
	while (n != 0)
	{
		n /= base;
		num++;
	}
	return (num);
}

int			ft_getnumx(unsigned long long n, unsigned int base)
{
	int			num;

	if (n == 0)
		return (1);
	num = 0;
	while (n != 0)
	{
		n /= base;
		num++;
	}
	return (num);
}

char		*ft_itoa_base(unsigned long long n, unsigned int base)
{
	char			*res;
	unsigned int	num;

	num = ft_getnumx(n, base);
	if (!(res = (char*)malloc((num + 1) * sizeof(char))))
		return (NULL);
	res[num] = '\0';
	while (num)
	{
		if ((n % base) <= 9)
			res[num - 1] = '0' + (n % base);
		else
			res[num - 1] = 'a' + (n % base) - 10;
		num--;
		n /= base;
	}
	return (res);
}
