/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:19:44 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/22 00:15:07 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left(t_cub *cub)
{
	if (cub->mv.rot_left == 1)
	{
		cub->mv.olddir_x = cub->rc.dir_x;
		cub->rc.dir_x = cub->rc.dir_x * cos(cub->mv.rot_speed) \
			- cub->rc.dir_y * sin(cub->mv.rot_speed);
		cub->rc.dir_y = cub->mv.olddir_x * sin(cub->mv.rot_speed) \
			+ cub->rc.dir_y * cos(cub->mv.rot_speed);
		cub->mv.oldplane_x = cub->rc.plan_x;
		cub->rc.plan_x = cub->rc.plan_x * cos(cub->mv.rot_speed) \
			- cub->rc.plan_y * sin(cub->mv.rot_speed);
		cub->rc.plan_y = cub->mv.oldplane_x * sin(cub->mv.rot_speed) \
			+ cub->rc.plan_y * cos(cub->mv.rot_speed);
	}
	if (cub->mv.left == 1)
	{
		if (cub->map.map[(int)(cub->rc.pos_y - cub->rc.plan_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '1' && cub->map.map[(int)(cub->rc.pos_y \
		- cub->rc.plan_y * 0.06)][(int)(cub->rc.pos_x)] != '2')
			cub->rc.pos_y -= cub->rc.plan_y * 0.06;
		if (cub->map.map[(int)(cub->rc.pos_y)][(int)(cub->rc.pos_x - \
		cub->rc.plan_x * 0.06)] != '1' && cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.pos_x - cub->rc.plan_x * 0.06)] != '2')
			cub->rc.pos_x -= cub->rc.plan_x * 0.06;
	}
}

static void	move_right(t_cub *cub)
{
	if (cub->mv.rot_right == 1)
	{
		cub->mv.olddir_x = cub->rc.dir_x;
		cub->rc.dir_x = cub->rc.dir_x * cos(-cub->mv.rot_speed) \
			- cub->rc.dir_y * sin(-cub->mv.rot_speed);
		cub->rc.dir_y = cub->mv.olddir_x * sin(-cub->mv.rot_speed) \
			+ cub->rc.dir_y * cos(-cub->mv.rot_speed);
		cub->mv.oldplane_x = cub->rc.plan_x;
		cub->rc.plan_x = cub->rc.plan_x * cos(-cub->mv.rot_speed) \
			- cub->rc.plan_y * sin(-cub->mv.rot_speed);
		cub->rc.plan_y = cub->mv.oldplane_x * sin(-cub->mv.rot_speed) \
			+ cub->rc.plan_y * cos(-cub->mv.rot_speed);
	}
	if (cub->mv.right == 1)
	{
		if (cub->map.map[(int)(cub->rc.pos_y)][(int)(cub->rc.plan_x * 0.06 \
		+ cub->rc.pos_x)] != '1' && cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.plan_x * 0.06 + cub->rc.pos_x)] != '2')
			cub->rc.pos_x += cub->rc.plan_x * 0.06;
		if (cub->map.map[(int)(cub->rc.pos_y + cub->rc.plan_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '1' \
		&& cub->map.map[(int)(cub->rc.pos_y + cub->rc.plan_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '2')
			cub->rc.pos_y += cub->rc.plan_y * 0.06;
	}
}

static void	move_down(t_cub *cub)
{
	if (cub->mv.down == 1)
	{
		if (cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.pos_x - cub->rc.dir_x * 0.06)] != '1' \
		&& cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.pos_x - cub->rc.dir_x * 0.06)] != '2')
			cub->rc.pos_x -= cub->rc.dir_x * 0.06;
		if (cub->map.map[(int)(cub->rc.pos_y - cub->rc.dir_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '1' \
		&& cub->map.map[(int)(cub->rc.pos_y - cub->rc.dir_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '2')
			cub->rc.pos_y -= cub->rc.dir_y * 0.06;
	}
}

static void	move_up(t_cub *cub)
{
	if (cub->mv.up == 1)
	{
		if (cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.pos_x + cub->rc.dir_x * 0.06)] != '1' \
		&& cub->map.map[(int)(cub->rc.pos_y)] \
		[(int)(cub->rc.pos_x + cub->rc.dir_x * 0.06)] != '2')
			cub->rc.pos_x += cub->rc.dir_x * 0.06;
		if (cub->map.map[(int)(cub->rc.pos_y + cub->rc.dir_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '1' \
		&& cub->map.map[(int)(cub->rc.pos_y + cub->rc.dir_y * 0.06)] \
		[(int)(cub->rc.pos_x)] != '2')
			cub->rc.pos_y += cub->rc.dir_y * 0.06;
	}
}

int	moveplayer(t_cub *cub)
{
	cub->mv.rot_speed = 0.06;
	move_up(cub);
	move_down(cub);
	move_right(cub);
	move_left(cub);
	init_image(cub);
	return (0);
}
