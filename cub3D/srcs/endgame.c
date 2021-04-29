/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:11:58 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 01:14:33 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	red_cross_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	exit(0);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_columns(char *tmp)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			if (res < j)
				res = j - 1;
			j = 0;
		}
		i++;
		j++;
	}
	return (res);
}

static void	free_memory(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->sprite)
		free(cub->sprite);
	i = 0;
	if (cub->map.tmp)
		free(cub->map.tmp);
	if (cub->map.map)
	{
		while (i <= cub->map.rows)
			free(cub->map.map[i++]);
	}
	free(cub->map.map);
}

int	end_game(t_cub *cub, char s[])
{
	ft_putstr_fd(s, 1);
	free_memory(cub);
	exit(0);
	return (0);
}
