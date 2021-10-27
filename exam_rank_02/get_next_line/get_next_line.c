/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:10:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/25 15:34:49 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *find_line_break(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while(str[i])
	{
		if(str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char *ft_join(char *str1, char *str2)
{
	char *new;
	int i;
	
	i = 0;
	if (!str1 || !str2)
		return(NULL);
	new = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new)
		return (NULL);
	while (*str1)
		new[i++] = *str1++;
	while (*str2)
		new[i++] = *str2++;
	new[i] = '\0';
	return (new);
}

char *ft_substr(char *str, int start, size_t len)
{
	char *new;
	int i;

	i = 0;
	if (!str || len <= 0)
		return (NULL);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (len)
	{
		new[i++] = str[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}

char *purge_line_from_temp(char *line, char *temp)
{
	char *new_temp;

	if (!find_line_break(temp))
	{
		free (temp);
		return (NULL);
	}
	new_temp = ft_substr(temp, ft_strlen(line), ft_strlen(temp) - ft_strlen(line)); 
	free (temp);
	return (new_temp);
}

char *extract_line_from_temp(char *temp)
{
	char *line;

	if (find_line_break(temp))
		line = ft_substr(temp, 0, ft_strlen(temp) - ft_strlen(find_line_break(temp)) + 1);
	else
		line = ft_substr(temp, 0, ft_strlen(temp));
	return (line);
}

char *update_temp(char *buff, char *temp)
{
	char *new;

	if (!temp)
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	new = ft_join(temp, buff);
	free (temp);
	return (new);	
}

char *read_to_temp(int fd, char *temp)
{
	char buff[BUFFER_SIZE + 1];
	int bytes;

	bytes = 1;
	while (!find_line_break(temp) && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if ((bytes == 0 && !temp) || bytes == -1)
			return (NULL);
		buff[bytes] = '\0';
		temp = update_temp(buff, temp);
	}
	return (temp);
}

char *get_next_line(int fd)
{
	char *line;
	static char *temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = read_to_temp(fd, temp);
	line = extract_line_from_temp(temp);
	temp = purge_line_from_temp(line, temp);
	return (line);
}

int		main(int argc, char **argv)
{
	int		fd;
	// int		ret;
	char	*line;

	fd = 0;
	// ret = 1;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
    {
		printf("line = |%s|\n", line);
    }
    free(line);
    // fd = 0;
    // free(get_next_line(fd));
	return (0);
}