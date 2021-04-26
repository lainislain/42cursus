/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:11:58 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 01:14:33 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_memory(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->sprite)
	{
		while (i < cub->rc.nbr_sprites)
		{
			if (cub->sprite[i].get_data)
				mlx_destroy_image(cub->mlx_ptr, cub->sprite[i].img_ptr);
			if (cub->mlx_ptr && cub->win_ptr)
				mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
			i++;
		}
	}
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
	free(cub->mlx_ptr);
	free(cub->win_ptr);
	free(cub->north.img_ptr);
	free(cub->south.img_ptr);
	free(cub->east.img_ptr);
	free(cub->west.img_ptr);
	free(cub->map.north);
	free(cub->map.south);
	free(cub->map.east);
	free(cub->map.west);
	free(cub->map.sprite);
	exit(0);
	return (0);
}
