/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 04:59:39 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/18 05:25:46 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (char)c)
			return (void*)(p + i);
		i++;
	}
	return (NULL);
}
