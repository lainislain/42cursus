/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:12:21 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/23 00:13:11 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	choose_texture(t_cub *cub)
{
	if (cub->rc.side == 0 && cub->rc.raydir_x > 0)
		return (cub->east);
	else if (cub->rc.side == 0 && cub->rc.raydir_x < 0)
		return (cub->west);
	else if (cub->rc.side == 1 && cub->rc.raydir_y > 0)
		return (cub->south);
	else
		return (cub->north);
}

void	draw_texture(t_cub *cub, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = choose_texture(cub);
	if (cub->rc.side == 0)
		wall_x = cub->rc.pos_y + cub->rc.perp_wall_dist * cub->rc.raydir_y;
	else
		wall_x = cub->rc.pos_x + cub->rc.perp_wall_dist * cub->rc.raydir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = cub->rc.draw_start;
	while (y++ < cub->rc.draw_end - 1)
	{
		tex_y = (y - cub->map.height / 2 + cub->rc.line_height / 2) \
		* tex_wall.height / cub->rc.line_height;
		if (tex_y < 0)
			return ;
		cub->get_data[x + y * cub->map.width] = \
		tex_wall.get_data[tex_x + tex_y * tex_wall.width];
	}
}

static void	coord_sprites(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < cub->map.rows)
	{
		x = 0;
		while (x < cub->map.columns)
		{
			if (cub->map.map[y][x] == '2')
			{
				cub->sprite[i].coord_x = x + 0.5;
				cub->sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static t_texture	set_texture(char *root_texture, t_cub *cub)
{
	t_texture	texture;

	texture.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, root_texture, \
	&texture.width, &texture.height);
	if (texture.img_ptr == NULL)
		end_game(cub, "FileError: Invalid wall texture\n");
	texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, \
	&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	if (texture.get_data == NULL)
		end_game(cub, "FileError: Invalid wall texture\n");
	return (texture);
}

void	init_textures(t_cub *cub)
{
	int	i;

	cub->north = set_texture(cub->map.north, cub);
	cub->south = set_texture(cub->map.south, cub);
	cub->east = set_texture(cub->map.east, cub);
	cub->west = set_texture(cub->map.west, cub);
	cub->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite), \
	cub->rc.nbr_sprites);
	if (cub->sprite == NULL)
		end_game(cub, "MemoryError: Allocation problem\n");
	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		cub->sprite[i].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->map.sprite, &cub->sprite[i].width, &cub->sprite[i].height);
		if (cub->sprite[i].img_ptr == NULL)
			end_game(cub, "FileError: Invalid sprite texture\n");
		cub->sprite[i].get_data = \
		(int *)mlx_get_data_addr(cub->sprite[i].img_ptr, \
		&cub->sprite[i].bits_per_pixel, &cub->sprite[i].size_line, \
		&cub->sprite[i].endian);
		if (cub->sprite[i].get_data == NULL)
			end_game(cub, "FileError: Invalid sprite texture\n");
	}
	coord_sprites(cub);
}
