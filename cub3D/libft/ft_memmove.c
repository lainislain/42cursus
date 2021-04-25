/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 04:57:22 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/18 05:25:23 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;

	if (!dst && !src)
		return (NULL);
	p1 = (char *)dst;
	p2 = (char *)src;
	if (src < dst)
	{
		while (n--)
			p1[n] = p2[n];
	}
	else
		ft_memcpy(p1, p2, n);
	return (dst);
}
