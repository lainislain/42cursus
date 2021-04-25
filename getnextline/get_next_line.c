/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:24:49 by amaghat           #+#    #+#             */
/*   Updated: 2019/11/12 19:49:08 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*free_text(char *text)
{
	if (text)
		free(text);
	return (NULL);
}

int				set_text(int fd, char *text[], char *temp)
{
	text[fd] = free_text(text[fd]);
	text[fd] = ft_strdup(temp);
	temp = free_text(temp);
	if (temp && !text[fd])
		return (-1);
	return (1);
}

int				set_line(int fd, char **line, char *text[])
{
	*line = free_text(*line);
	*line = ft_strdup(text[fd]);
	text[fd] = free_text(text[fd]);
	if (text[fd] && !*line)
		return (-1);
	return (0);
}

int				read_text(int fd, char *text[])
{
	char			*buff;
	char			*temp;
	int				checked;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	checked = read(fd, buff, BUFFER_SIZE);
	if (checked <= 0)
	{
		buff = free_text(buff);
		return (checked);
	}
	buff[checked] = '\0';
	temp = ft_strjoin(text[fd], buff);
	buff = free_text(buff);
	return (set_text(fd, text, temp));
}

int				get_next_line(int fd, char **line)
{
	static char		*text[1337];
	char			*temp;
	char			*ptr;
	int				checked;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!text[fd])
		text[fd] = ft_strdup("");
	*line = ft_strdup("");
	while (!(ptr = ft_strchr(text[fd], '\n')))
		if ((checked = read_text(fd, text)) <= 0)
			break ;
	if (ft_strlen(text[fd]) && !(ft_strchr(text[fd], '\n')))
		return (set_line(fd, line, text));
	else if (ft_strlen(text[fd]))
	{
		*ptr = '\0';
		if ((!(temp = ft_strdup(ptr + 1)) && (ptr + 1)) ||
				(set_line(fd, line, text)) < 0)
			return (-1);
		return (set_text(fd, text, temp));
	}
	return (checked);
}
