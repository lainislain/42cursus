/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:10:42 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/25 17:52:53 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_cub *cub)
{
	cub->new_image = mlx_new_image(cub->mlx_ptr, \
	cub->map.width, cub->map.height);
	if (cub->new_image == NULL)
		end_game(cub, "MlxError: Problem in mlx library execution\n");
	cub->get_data = (int *)mlx_get_data_addr(cub->new_image, \
	&cub->bits_per_pixel, &cub->size_line, &cub->endian);
	if (cub->get_data == NULL)
		end_game(cub, "MlxError: Problem in mlx library execution\n");
	raycasting(cub);
	sprites(cub);
	if (cub->save == 1)
		bmp(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->new_image, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->new_image);
}

static void	init_game(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (cub->mlx_ptr == NULL)
		end_game(cub, "MlxError: Problem in mlx library execution\n");
	if (cub->map.width > MAX_WIDTH)
		cub->map.width = MAX_WIDTH;
	if (cub->map.height > MAX_HEIGHT)
		cub->map.height = MAX_HEIGHT;
	if (cub->save == 0)
	{
		cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->map.width, \
		cub->map.height, "cub3D");
	}
	cub->rs.dist_wall = ft_calloc(sizeof(double), cub->map.width);
	if (cub->rs.dist_wall == NULL)
		end_game(cub, "MemoryError: Allocation problem\n");
	init_textures(cub);
	init_image(cub);
	mlx_hook(cub->win_ptr, 2, 1, &key_press, cub);
	mlx_hook(cub->win_ptr, 3, 2, &key_release, cub);
	mlx_hook(cub->win_ptr, 17, 0L, &red_cross_exit, cub);
	mlx_loop_hook(cub->mlx_ptr, &moveplayer, cub);
	mlx_loop(cub->mlx_ptr);
}

static void	direction(t_cub *cub)
{
	if (cub->map.orientation == 'N')
	{
		cub->rc.dir_x = 0;
		cub->rc.dir_y = -1;
	}
	else if (cub->map.orientation == 'S')
	{
		cub->rc.dir_x = 0;
		cub->rc.dir_y = 1;
	}
	else if (cub->map.orientation == 'W')
	{
		cub->rc.dir_x = -1;
		cub->rc.dir_y = 0;
	}
	else if (cub->map.orientation == 'E')
	{
		cub->rc.dir_x = 1;
		cub->rc.dir_y = 0;
	}
	cub->rc.plan_x = -0.66 * cub->rc.dir_y;
	cub->rc.plan_y = 0.66 * cub->rc.dir_x;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	int		len;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
		end_game(cub, "MemoryError: Allocation problem\n");
	ft_bzero(cub, sizeof(t_cub));
	if (argc < 2 || argc > 3)
		end_game(cub, "ArgError: Incorrect number of arguments\n");
	len = ft_strlen(argv[1]) - 4;
	if (len == 0)
		end_game(cub, "ArgError: The file must have a name\n");
	else if (ft_strncmp(argv[1] + len, ".cub", 4))
		end_game(cub, "ArgError: The file must end with .cub\n");
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
			cub->save = 1;
		else
			end_game(cub, "ArgError: Second argument must be --save\n");
	}
	read_file(argv, cub);
	direction(cub);
	init_game(cub);
	return (0);
}
