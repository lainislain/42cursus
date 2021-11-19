#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "./mlx_linux/mlx.h"

# define BUFFER_SIZE 32
# define DEG_2_RAD (0.01745329252)
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LSHIFT 65505
# define LCTRL 65507
# define Q 113
# define E 101
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define TAB 65289
# define R 114

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
	int		color;
}	t_vec2;

typedef struct s_map
{
	t_vec3		**coords;
	int			width_x;
	int			length_z;
	int			min_height_y;
	int			max_height_y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_data;

typedef struct s_params
{
	double			roll;
	double			pitch;
	double			yaw;
	unsigned char	projection;
	float			scale_factor;
	float			trans_x;
	float			trans_y;

}	t_params;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	int			win_x;
	int			win_y;
	t_data		*i;
	t_map		*map;
	t_params	*params;
}	t_mlx;

char		*remove_spaces(const char *str);
char		*get_next_line(int fd);
t_map		*init_map(t_list *prms);
void		init_mlx(t_map *map);
void		add_vector(char *text, int x, int z, t_map *map);
void		list_params(int fd, t_list **list);
void		center_to_origin(t_map *map);
t_list		*ft_lstnext(t_list *current);
int			ft_atoi_base(char *str, char *base);
t_vec3		**init_coordinates(int width, int depth);
int			get_width(t_list *head);
void		remove_breakline(char *text);
void		put_pixel_in_image(t_data *i, t_vec2 v);
int			create_trgb(int t, int r, int g, int b);
float		factor_fit_screen(t_mlx *mlx);
int			draw(t_mlx *data);
t_vec2		*get_projection(t_vec3 s, t_vec3 e, t_mlx *mlx, unsigned char proj);
t_vec2		*get_isometric(t_vec3 start, t_vec3 end);
t_vec2		*get_perspective(t_vec3 start, t_vec3 end, t_mlx *mlx);
float		absolute(float nbr);
float		max(float a, float b);
float		min(float a, float b);
void		scale(float factor, t_vec2 *start, t_vec2 *end);
void		translate(t_vec2 *start, t_vec2 *end, float move_x, float move_y);
void		rotate_x(t_vec3 *start, t_vec3 *end, double rad_ang);
void		rotate_y(t_vec3 *start, t_vec3 *end, double rad_ang);
void		rotate_z(t_vec3 *start, t_vec3 *end, double rad_ang);
void		free_map(t_map *map, int width);
void		free_mlx(t_mlx *mlx);
int			key_events(int keycode, t_mlx *mlx);
int			lerp_color(int clr_a, int clr_b, float f);
void		free_2d_array(char **split);
void		init_params(t_mlx *mlx);

#endif
