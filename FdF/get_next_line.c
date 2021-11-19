#include "fdf.h"

static void	ft_strdel(char **s)
{
	if (s == 0)
		return ;
	if (*s)
		free(*s);
	*s = 0;
}

static char	*process_buffer(char	**remainder)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	if (!*remainder)
		return (NULL);
	while ((*remainder)[i] != '\n' && (*remainder)[i] != '\0')
		i++;
	if ((*remainder)[i] == '\n')
	{
		line = ft_substr(*remainder, 0, i + 1);
		temp = ft_strdup(&((*remainder)[i + 1]));
		free(*remainder);
		*remainder = temp;
		if ((*remainder)[0] == '\0')
			ft_strdel(remainder);
		return (line);
	}
	else
	{
		line = ft_strdup(*remainder);
		ft_strdel(remainder);
		return (line);
	}
}

static int	has_linebreak(char	*buff)
{
	while (*(char *)buff != '\0')
	{
		if (*(char *)buff == '\n')
			return (1);
		buff++;
	}
	if (*(char *)buff == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t			r;
	static char		*remainder = NULL;
	char			buff[BUFFER_SIZE + 1];
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = read(fd, buff, BUFFER_SIZE);
	while (r > 0)
	{
		buff[r] = '\0';
		if (!remainder)
			remainder = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(remainder, buff);
			ft_strdel(&remainder);
			remainder = temp;
		}
		if (has_linebreak(buff))
			break ;
		r = read(fd, buff, BUFFER_SIZE);
	}
	return (process_buffer(&remainder));
}
