/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:10:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/02/28 19:14:09 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

static char	*chrjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (str == NULL)
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

int	mini_gnl(int fd, char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (line == NULL || buffer == NULL)
		return (-1);
	*line = (char *)malloc(1);
	if (*line == NULL)
	{
		free(buffer);
		return (-1);
	}
	*line[0] = '\0';
	flag = read(fd, buffer, 1);
	while (flag > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = chrjoin(*line, buffer[0]);
		flag = read(fd, buffer, 1);
	}
	free(buffer);
	return (flag);
}
