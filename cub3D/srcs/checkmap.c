/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:12:04 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/25 18:05:45 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_columns(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (i < cub->map.rows)
	{
		if (cub->map.map[i][0] != '1' && cub->map.map[i][0] != '4')
			end_game(cub, "FileError: Map should be closed west\n");
		i++;
	}
	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
			j++;
		j--;
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != '4')
			end_game(cub, "FileError: Map should be closed east\n");
		i++;
		j = 0;
	}
}

static void	check_rows(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->map.map[0][i])
	{
		if (cub->map.map[0][i] != '1' && cub->map.map[0][i] != '4')
			end_game(cub, "FileError: Map should be closed north\n");
		i++;
	}
	i = 0;
	while (i < cub->map.columns)
	{
		if (cub->map.map[cub->map.rows - 1][i] != '1' \
				&& cub->map.map[cub->map.rows - 1][i] != '4' && \
				cub->map.map[cub->map.rows - 1][i] != '\0')
			end_game(cub, "FileError: Map Map should be closed south\n");
		i++;
	}
}

static void	check_spaces(t_cub *cub)
{
	int		i;
	int		j;

	i = 1;
	while (i < cub->map.rows - 1)
	{
		j = 1;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '4' && ((j != 0 && cub->map.map[i] \
					[j - 1] == '0') || (j != cub->map.columns - 1 && \
					cub->map.map[i][j + 1] == '0') || cub->map.map[i - 1][j] \
					== '0' || cub->map.map[i + 1][j] == '0'))
				end_game(cub, "FileError: Map inaccuracy / spaces inside map\n");
			j++;
		}
		i++;
	}
}

static void	check_player(t_cub *cub, int i, int j)
{
	if (ft_isalpha(cub->map.map[i][j]) && cub->map.map[i][j] != 'N' && \
			cub->map.map[i][j] != 'S' && cub->map.map[i][j] != 'E' && \
			cub->map.map[i][j] != 'W')
		end_game(cub, "FileError: Invalid number of arguments\n");
	if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W') \
			&& cub->id.player == 0)
	{
		cub->rc.pos_x = j + 0.5;
		cub->rc.pos_y = i + 0.5;
		cub->map.orientation = cub->map.map[i][j];
		cub->id.player = 1;
	}
	else if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W') \
			&& cub->id.player == 1)
		end_game(cub, "FileError: Multiplayer not available\n");
}

void	check_map(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
		{
			check_player(cub, i, j);
			if (cub->map.map[i][j] == '2')
				cub->rc.nbr_sprites += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (cub->id.player == 0)
		end_game(cub, "FileError: No player in the map\n");
	check_spaces(cub);
	check_rows(cub);
	check_columns(cub);
}
