/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 05:38:24 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/22 04:52:16 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_toskip(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t			i;

	i = 0;
	while (ft_toskip(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_get_last(char const *s1, char const *set)
{
	size_t			i;

	i = ft_strlen(s1);
	while (--i && ft_toskip(s1[i], set))
		;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	s2 = ft_substr(s1, start, ft_get_last(s1, set) - start + 1);
	if (start == ft_strlen(s1))
	{
		s2 = malloc(sizeof(char));
		*s2 = '\0';
	}
	else if (!s2)
		return (NULL);
	return (s2);
}
