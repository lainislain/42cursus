/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:12:01 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 01:14:66 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_cub *cub)
{
	end_game(cub, "Game closed succesully. See you next time!\n");
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
