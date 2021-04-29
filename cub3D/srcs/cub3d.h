/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:10:34 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/27 13:11:44 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx_linux/mlx.h"
//# include <mlx.h>

/*
# define W 13
# define S 1
# define D 2
# define A 0
# define RIGHT 124
# define LEFT 123
# define ESC 53
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440
*/

# define W 119
# define S 115
# define D 100
# define A 97
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307
# define MAX_WIDTH 1440
# define MAX_HEIGHT 900

typedef struct s_bmp
{
	unsigned char	header[54];
	unsigned char	zero[3];
	int				size;
	int				padding;
	int				fd;
	int				color;
}					t_bmp;

typedef struct s_identifiers
{
	int				r;
	int				no;
	int				so;
	int				ea;
	int				we;
	int				s;
	int				f;
	int				c;
	int				m;
	int				player;
}					t_identifiers;

typedef struct s_sprite
{
	double			distance;
	double			coord_x;
	double			coord_y;
	void			*img_ptr;
	int				*get_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				color;
}					t_sprite;

typedef struct s_texture
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				width;
	int				height;
}					t_texture;

typedef struct s_colors
{
	int				roof;
	int				floor;
	int				north;
	int				south;
	int				east;
	int				west;
	int				wall;
}					t_colors;

typedef struct s_movement
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	double			olddir_x;
	double			oldplane_x;
	double			rot_speed;
}					t_movement;

typedef struct s_raysprite
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				height;
	int				width;
	double			*dist_wall;
}					t_raysprite;

typedef struct s_raycasting
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plan_x;
	double			plan_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				nbr_sprites;
}					t_raycasting;

typedef struct s_map
{
	char			**map;
	char			*tmp;
	int				rows;
	int				columns;
	int				width;
	int				height;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
	int				floor;
	int				ceiling;
	char			orientation;
}					t_map;

typedef struct s_cub
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*new_image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				save;
	t_map			map;
	t_raycasting	rc;
	t_raysprite		rs;
	t_movement		mv;
	t_colors		color;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_sprite		*sprite;
	t_identifiers	id;
}					t_cub;

int					read_file(char **argv, t_cub *cub);
void				check_id(t_cub *cub, char *line);
void				save_res(t_cub *cub, char *line, int i);
char				*save_texture(char *line, int i);
int					save_color(t_cub *cub, char *line, int i);
void				check_rgb(t_cub *cub, char *line, int i);
void				check_file(t_cub *cub);
void				save_map(t_cub *cub);
void				check_map(t_cub *cub);
void				init_textures(t_cub *cub);
void				init_image(t_cub *cub);
void				raycasting(t_cub *cub);
void				draw_texture(t_cub *cub, int x);
void				sprites(t_cub *cub);
void				bmp(t_cub *cub);
int					key_press(int keycode, t_cub *cub);
int					key_release(int keycode, t_cub *cub);
int					key_exit(t_cub *cub);
int					moveplayer(t_cub *cub);
int					end_game(t_cub *cub, char s[]);
void				free_tab(char **tab);
void				*ft_calloc(size_t count, size_t size);
int					mini_gnl(int fd, char **line);
void				check_res(t_cub *cub, char *line, int i);
int					count_columns(char *tmp);
int					red_cross_exit(t_cub *cub);
#endif
