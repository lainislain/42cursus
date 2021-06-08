/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 04:49:03 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/18 05:25:00 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)c)
			return (&p1[i + 1]);
		else
			i++;
	}
	return (NULL);
}
