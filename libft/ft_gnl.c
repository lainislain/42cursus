/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:10:00 by amaghat           #+#    #+#             */
/*   Updated: 2021/02/28 19:18:58 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chrjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int			ft_gnl(int fd, char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !(*line = (char *)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((flag = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = chrjoin(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
