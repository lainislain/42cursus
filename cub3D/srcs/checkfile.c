/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:11:43 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 00:11:29 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_res(t_cub *cub, char *line, int i)
{
	char **res;
	int j;
	int k;

	j = 0;
	res = ft_split(line + i, ' ');
	while (res[j])
		j++;
	if (j != 2)
		end_game(cub, "FileError: Resolution is only 2 numbers\n");
	j = 0;
	while (res[j])
	{
		k = 0;
		while (res[j][k] == '0')
			k++;
		if ((ft_strlen(res[j]) - k) > 4)
		{
			if (j == 0)
				cub->map.width = 99999;
			else
				cub->map.height = 99999;
		}
		else
		{
			if (j == 0)
				cub->map.width = ft_atoi(&res[j][k]);
			else
				cub->map.height = ft_atoi(&res[j][k]);
		}
		j++;
	}
}

void	check_rgb(t_cub *cub, char *line, int i)
{
	int tmp;

	if (i == 1)
	{
		while (line[i])
		{
			if (ft_isalpha(line[i]))
				end_game(cub, "FileError: Invalid character in RGB color\n");
			i++;
		}
	}
	else
	{
		tmp = ft_atoi(&line[i]);
		if (tmp < 0 || tmp > 255)
			end_game(cub, "FileError: Invalid character in RGB color\n");
	}
}


void	check_id(t_cub *cub, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R' && cub->id.r == 1)
		end_game(cub, "FileError: Resolution duplicated\n");
	if (line[i] == 'N' && line[i + 1] == 'O' && cub->id.no == 1)
		end_game(cub, "FileError: North texture duplicated\n");
	if (line[i] == 'S' && line[i + 1] == 'O' && cub->id.so == 1)
		end_game(cub, "FileError: South texture duplicated\n");
	if (line[i] == 'E' && line[i + 1] == 'A' && cub->id.ea == 1)
		end_game(cub, "FileError: East textures duplicated\n");
	if (line[i] == 'W' && line[i + 1] == 'E' && cub->id.we == 1)
		end_game(cub, "FileError: West textures duplicated\n");
	if (line[i] == 'S' && line[i + 1] == ' ' && cub->id.s == 1)
		end_game(cub, "FileError: Sprite texture duplicated\n");
	if (line[i] == 'F' && line[i + 1] == ' ' && cub->id.f == 1)
		end_game(cub, "FileError: Floor colors duplicated\n");
	if (line[i] == 'C' && line[i + 1] == ' ' && cub->id.c == 1)
		end_game(cub, "FileError: Ceiling colors duplicated\n");
}

void	check_file(t_cub *cub)
{
	if (cub->id.r == 0 && cub->id.no == 0 && cub->id.so == 0 && \
			cub->id.ea == 0 && cub->id.we == 0 && cub->id.s == 0 && \
			cub->id.f == 0 && cub->id.c == 0 && cub->id.m == 0)
		end_game(cub, "FileError: Configuration file is empty\n");
	if (cub->id.m == 0)
		end_game(cub, "FileError: No map in configuration file\n");
	if (cub->id.m - cub->map.rows > 1)
		end_game(cub, "FileError: Invalid line in configuration file\n");
}
