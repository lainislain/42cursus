/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 05:48:37 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/18 06:15:11 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			getnc(int n)
{
	int				nc;
	unsigned int	temp;

	nc = 1;
	if (n < 0)
	{
		temp = n * (-1);
		nc++;
	}
	else
		temp = n;
	while (temp / 10)
	{
		temp /= 10;
		nc++;
	}
	return (nc);
}

char				*ft_itoa(int n)
{
	int				nc;
	unsigned int	temp;
	char			*res;

	nc = getnc(n);
	res = (char*)malloc(sizeof(char) * (nc + 1));
	if (!res)
		return (NULL);
	res[nc] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		temp = -n;
	}
	else
		temp = n;
	nc--;
	while (nc >= 0 && res[nc] != '-')
	{
		res[nc] = (temp % 10) + '0';
		temp /= 10;
		nc--;
	}
	return (res);
}
