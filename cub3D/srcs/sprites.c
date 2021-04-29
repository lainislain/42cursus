/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:12:19 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/25 17:54:59 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_sprite(t_cub *cub, int i)
{
	if (cub->rs.tex_y > 0)
	{
		if (cub->sprite[i].get_data[cub->rs.tex_x + cub->rs.tex_y * \
		cub->sprite[i].width] != 0)
			cub->sprite[i].color = cub->sprite[i].get_data \
			[cub->rs.tex_x + cub->rs.tex_y * cub->sprite[i].width];
		else
			cub->sprite[i].color = 0xBFD195;
	}
}

static void	draw_xray_sprite(t_cub *cub, int x, int i)
{
	int	y;
	int	d;

	y = cub->rs.draw_start_y + cub->map.width / 100 + 12;
	while (y < cub->rs.draw_end_y)
	{
		d = (y * 256 - cub->map.height * 128 + cub->rs.height * 128);
		cub->rs.tex_y = (d * cub->sprite[i].height / cub->rs.height) / 256;
		color_sprite(cub, i);
		if (cub->sprite[i].color != 0xBFD195 && \
				cub->rs.transform_y < cub->rs.dist_wall[x])
		{
			if (x >= 0 && x < cub->map.width && y >= 0 && cub->map.width)
			{
				cub->get_data[x + y * cub->map.width] = \
					cub->sprite[i].color;
			}
		}
		y++;
	}
}

static void	init_sprite(t_cub *cub, int i)
{
	cub->rs.x = cub->sprite[i].coord_x - cub->rc.pos_x;
	cub->rs.y = cub->sprite[i].coord_y - cub->rc.pos_y;
	cub->rs.inv_det = 1 / (cub->rc.plan_x * cub->rc.dir_y \
			- cub->rc.dir_x * cub->rc.plan_y);
	cub->rs.transform_x = cub->rs.inv_det * \
			(cub->rc.dir_y * cub->rs.x - cub->rc.dir_x * cub->rs.y);
	cub->rs.transform_y = cub->rs.inv_det * \
			(-cub->rc.plan_y * cub->rs.x + cub->rc.plan_x * cub->rs.y);
	cub->rs.screen_x = (int)((cub->map.width / 2) * \
			(1 + cub->rs.transform_x / cub->rs.transform_y));
	cub->rs.height = abs((int)(cub->map.width / cub->rs.transform_y));
	cub->rs.draw_start_y = cub->map.height / 2 - cub->rs.height / 2;
	if (cub->rs.draw_start_y < 0)
		cub->rs.draw_start_y = 0;
	cub->rs.draw_end_y = cub->map.height / 2 + cub->rs.height / 2;
	if (cub->rs.draw_end_y >= cub->map.height)
		cub->rs.draw_end_y = cub->map.height - 1;
	cub->rs.width = abs((int)(cub->map.width / cub->rs.transform_y));
	cub->rs.draw_start_x = cub->rs.screen_x - cub->rs.width / 2;
	if (cub->rs.draw_start_x < 0)
		cub->rs.draw_start_x = 0;
	cub->rs.draw_end_x = cub->rs.screen_x + cub->rs.width / 2;
	if (cub->rs.draw_end_x >= cub->map.width)
		cub->rs.draw_end_x = cub->map.width - 1;
}

static void	sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < cub->rc.nbr_sprites)
	{
		j = 0;
		while (j < cub->rc.nbr_sprites - i - 1)
		{
			if (cub->sprite[j].distance < cub->sprite[j + 1].distance)
			{
				tmp = cub->sprite[j];
				cub->sprite[j] = cub->sprite[j + 1];
				cub->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprites(t_cub *cub)
{
	int	i;
	int	x;

	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		cub->sprite[i].distance = pow(cub->rc.pos_x - \
		cub->sprite[i].coord_x, 2) + pow(cub->rc.pos_y - \
		cub->sprite[i].coord_y, 2);
	}
	sort_sprites(cub);
	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		init_sprite(cub, i);
		x = cub->rs.draw_start_x - 1;
		while (++x < cub->rs.draw_end_x && x < cub->map.width)
		{
			cub->rs.tex_x = (int)(256 * (x - (-cub->rs.width / 2 + \
			cub->rs.screen_x)) * cub->sprite[i].width / cub->rs.width) / 256;
			if (cub->rs.transform_y > 0)
				draw_xray_sprite(cub, x, i);
		}
	}
}
