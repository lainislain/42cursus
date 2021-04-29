/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:12:13 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 00:13:40 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	join_line(t_cub *cub, char *line)
{
	char	*tmp;

	if (cub->map.tmp == NULL)
		cub->map.tmp = ft_strdup("");
	else
	{
		tmp = cub->map.tmp;
		cub->map.tmp = ft_strjoin(cub->map.tmp, "\n");
		free(tmp);
	}
	tmp = cub->map.tmp;
	cub->map.tmp = ft_strjoin(cub->map.tmp, line);
	free(tmp);
	tmp = NULL;
	cub->map.rows++;
}

static void	read_map(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		if (cub->id.r == 1 && cub->id.no == 1 && cub->id.so == 1 && \
				cub->id.ea == 1 && cub->id.we == 1 && cub->id.s == 1 && \
				cub->id.f == 1 && cub->id.c == 1)
		{
			join_line(cub, line);
			cub->id.m++;
		}
		else
			end_game(cub, "FileError: Missing Identifier\n");
	}
	else if (cub->id.m)
		cub->id.m++;
	if (line[i] != '0' && line[i] != '1' && line[i] != 'R' && line[i] != 'N' \
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && \
			line[i] != 'F' && line[i] != 'C' && line[i] != '\0')
		end_game(cub, "FileError: Invalid line in configuration file\n");
}

static void	read_textures(t_cub *cub, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && cub->id.no == 0)
	{
		cub->id.no = 1;
		cub->map.north = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == 'O' && cub->id.so == 0)
	{
		cub->id.so = 1;
		cub->map.south = save_texture(line, i);
	}
	if (line[i] == 'E' && line[i + 1] == 'A' && cub->id.ea == 0)
	{
		cub->id.ea = 1;
		cub->map.east = save_texture(line, i);
	}
	if (line[i] == 'W' && line[i + 1] == 'E' && cub->id.we == 0)
	{
		cub->id.we = 1;
		cub->map.west = save_texture(line, i);
	}
	if (line[i] == 'S' && line[i + 1] == ' ' && cub->id.s == 0)
	{
		cub->id.s = 1;
		cub->map.sprite = save_texture(line, i);
	}
}

static void	read_line(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	check_id(cub, line);
	if (line[i] == 'R' && line[i + 1] == ' ' && cub->id.r == 0)
		save_res(cub, line, i);
	read_textures(cub, line, i);
	if (line[i] == 'F' && line[i + 1] == ' ' && cub->id.f == 0)
	{
		cub->id.f = 1;
		cub->map.floor = save_color(cub, line, i);
	}
	if (line[i] == 'C' && line[i + 1] == ' ' && cub->id.c == 0)
	{
		cub->id.c = 1;
		cub->map.ceiling = save_color(cub, line, i);
	}
	read_map(cub, line);
}

int	read_file(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		end_game(cub, "FileError: Configuration file not found\n");
	while (mini_gnl(fd, &line))
	{
		read_line(cub, line);
		free(line);
		line = NULL;
	}
	read_line(cub, line);
	free(line);
	line = NULL;
	close(fd);
	check_file(cub);
	save_map(cub);
	check_map(cub);
	return (1);
}
