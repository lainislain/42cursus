/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 05:08:33 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/23 08:16:38 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	size_t	cmp;
	char	*temp;

	temp = (char*)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len > ft_strlen(haystack) + 1)
		return (NULL);
	if (!(needle_len))
		return (temp);
	i = 0;
	while (i < len && *temp)
	{
		cmp = ft_strncmp(temp, needle, needle_len);
		if ((needle_len <= (len - i)) && !cmp)
			return (temp);
		temp++;
		i++;
	}
	return (NULL);
}
