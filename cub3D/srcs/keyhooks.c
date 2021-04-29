/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:12:01 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/26 16:40:20 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	end_game(cub, "");
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 0;
	if (keycode == S)
		cub->mv.down = 0;
	if (keycode == D)
		cub->mv.right = 0;
	if (keycode == A)
		cub->mv.left = 0;
	if (keycode == LEFT)
		cub->mv.rot_right = 0;
	if (keycode == RIGHT)
		cub->mv.rot_left = 0;
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 1;
	if (keycode == S)
		cub->mv.down = 1;
	if (keycode == D)
		cub->mv.right = 1;
	if (keycode == A)
		cub->mv.left = 1;
	if (keycode == LEFT)
		cub->mv.rot_right = 1;
	if (keycode == RIGHT)
		cub->mv.rot_left = 1;
	if (keycode == ESC)
		key_exit(cub);
	return (0);
}
