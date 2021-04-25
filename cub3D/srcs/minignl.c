/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:10:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/02/28 19:14:09 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int			mini_gnl(int fd, char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	*line = (char *)malloc(1);
	if (line == NULL || *line == NULL || buffer == NULL)
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
