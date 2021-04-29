/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:13:56 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 00:12:16 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	alloc_map(t_cub *cub)
{
	int	i;

	cub->map.columns = count_columns(cub->map.tmp);
	cub->map.map = malloc(sizeof(char *) * (cub->map.rows + 1));
	if (cub->map.map == NULL)
		end_game(cub, "MemoryError: Allocation problem\n");
	i = 0;
	while (i < cub->map.rows)
	{
		cub->map.map[i] = ft_calloc(sizeof(char), \
		(cub->map.columns + 1));
		if (cub->map.map[i++] == NULL)
			end_game(cub, "MemoryError: Allocation problem\n");
	}
}

void	save_map(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (cub->map.tmp[i++])
	{
		if (cub->map.tmp[i] == ' ')
			cub->map.tmp[i] = '4';
	}
	alloc_map(cub);
	i = 0;
	j = 0;
	k = 0;
	while (cub->map.tmp[k++])
	{
		if (cub->map.tmp[k] != '\n')
			cub->map.map[i][j++] = cub->map.tmp[k];
		else
		{
			cub->map.map[i++][j] = '\0';
			j = 0;
		}
	}
	cub->map.map[cub->map.rows] = NULL;
}

int	save_color(t_cub *cub, char *line, int i)
{
	int	color;

	i++;
	check_rgb(cub, line, i);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	check_rgb(cub, line, i);
	color = ft_atoi(&line[i]) * pow(2, 16);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ',' && line[i] != ' ' && line[i] != '\t')
		end_game(cub, "FileError: No coma between RGB colors\n");
	while (line[i] == ',' || line[i] == ' ' || line[i] == '\t')
		i++;
	check_rgb(cub, line, i);
	color += ft_atoi(&line[i]) * pow(2, 8);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ',' && line[i] != ' ' && line[i] != '\t')
		end_game(cub, "FileError: No coma between RGB colors\n");
	while (line[i] == ',' || line[i] == ' ' || line[i] == '\t')
		i++;
	check_rgb(cub, line, i);
	color += ft_atoi(&line[i]);
	return (color);
}

char	*save_texture(char *line, int i)
{
	char	*texture;

	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	texture = ft_strdup(&line[i]);
	return (texture);
}

void	save_res(t_cub *cub, char *line, int i)
{
	int	tmp;

	cub->id.r = 1;
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	tmp = i;
	while (line[tmp])
	{
		if (ft_isdigit(line[tmp]) == 0 && line[tmp] != ' ' && line[tmp] != '\t')
			end_game(cub, "FileError: Resolution must be only in digits\n");
		tmp++;
	}
	check_res(cub, line, i);
}
