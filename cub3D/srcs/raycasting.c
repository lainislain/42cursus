/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:12:10 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 00:12:10 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_screen(t_cub *cub, int x, int y)
{
	cub->rc.line_height = (cub->map.width / cub->rc.perp_wall_dist);
	cub->rc.draw_start = cub->map.height / 2 - cub->rc.line_height / 2;
	cub->rc.draw_end = cub->map.height / 2 + cub->rc.line_height / 2;
	if (cub->rc.draw_start < 0)
		cub->rc.draw_start = 0;
	if (cub->rc.draw_end >= cub->map.height)
		cub->rc.draw_end = cub->map.height - 1;
	draw_texture(cub, x);
	y = cub->rc.draw_end;
	while (y < cub->map.height)
	{
		cub->get_data[(y * cub->size_line + x * 4) / 4] = cub->map.floor;
		cub->get_data[x + (cub->map.height - y - 1) * cub->map.width] = \
		cub->map.ceiling;
		y++;
	}
}

static void	dda_algorithm(t_cub *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->rc.side_dist_x < cub->rc.side_dist_y)
		{
			cub->rc.side_dist_x += cub->rc.delta_dist_x;
			cub->rc.map_x += cub->rc.step_x;
			cub->rc.side = 0;
		}
		else
		{
			cub->rc.side_dist_y += cub->rc.delta_dist_y;
			cub->rc.map_y += cub->rc.step_y;
			cub->rc.side = 1;
		}
		if (cub->map.map[cub->rc.map_y][cub->rc.map_x] == '1')
			hit = 1;
	}
}

static void	calculate_steps(t_cub *cub)
{
	if (cub->rc.raydir_x < 0)
	{
		cub->rc.step_x = -1;
		cub->rc.side_dist_x = (cub->rc.pos_x - cub->rc.map_x) * \
			cub->rc.delta_dist_x;
	}
	else
	{
		cub->rc.step_x = 1;
		cub->rc.side_dist_x = (cub->rc.map_x + 1 - cub->rc.pos_x) \
			* cub->rc.delta_dist_x;
	}
	if (cub->rc.raydir_y < 0)
	{
		cub->rc.step_y = -1;
		cub->rc.side_dist_y = (cub->rc.pos_y - cub->rc.map_y) * \
			cub->rc.delta_dist_y;
	}
	else
	{
		cub->rc.step_y = 1;
		cub->rc.side_dist_y = (cub->rc.map_y + 1 - cub->rc.pos_y) \
			* cub->rc.delta_dist_y;
	}
}

static void	init_raycasting(t_cub *cub, int x)
{
	cub->rc.camera_x = 2 * x / (double)(cub->map.width) - 1;
	cub->rc.raydir_x = cub->rc.dir_x + cub->rc.plan_x * cub->rc.camera_x;
	cub->rc.raydir_y = cub->rc.dir_y + cub->rc.plan_y * cub->rc.camera_x;
	cub->rc.delta_dist_x = fabs(1 / cub->rc.raydir_x);
	cub->rc.delta_dist_y = fabs(1 / cub->rc.raydir_y);
	cub->rc.map_x = (int)cub->rc.pos_x;
	cub->rc.map_y = (int)cub->rc.pos_y;
	calculate_steps(cub);
}

void	raycasting(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cub->map.width)
	{
		init_raycasting(cub, x);
		dda_algorithm(cub);
		if (cub->rc.side == 0)
			cub->rc.perp_wall_dist = (cub->rc.map_x - cub->rc.pos_x \
					+ (1 - cub->rc.step_x) / 2) / cub->rc.raydir_x;
		else
			cub->rc.perp_wall_dist = (cub->rc.map_y - cub->rc.pos_y \
					+ (1 - cub->rc.step_y) / 2) / cub->rc.raydir_y;
		draw_screen(cub, x, y);
		cub->rs.dist_wall[x] = cub->rc.perp_wall_dist;
		x++;
	}
}
