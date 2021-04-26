/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 05:12:35 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/18 05:32:38 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t count, size_t size)
{
	char	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
