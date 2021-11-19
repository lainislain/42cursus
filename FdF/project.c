#include "fdf.h"

t_vec2	*get_projection(t_vec3 s, t_vec3 e, t_mlx *mlx, unsigned char proj)
{
	if (proj == 0)
		return (get_isometric(s, e));
	else if (proj == 1)
		return (get_perspective(s, e, mlx));
	else
		return (NULL);
}

t_vec2	*get_isometric(t_vec3 start, t_vec3 end)
{
	t_vec2	*screen;

	screen = malloc(sizeof(*screen) * 2);
	screen[0].x = (start.x - start.y) * cos(30 * DEG_2_RAD);
	screen[0].y = (start.x + start.y) * sin(30 * DEG_2_RAD) - start.z;
	screen[0].color = start.color;
	screen[1].x = (end.x - end.y) * cos(30 * DEG_2_RAD);
	screen[1].y = (end.x + end.y) * sin(30 * DEG_2_RAD) - end.z;
	screen[1].color = end.color;
	return (screen);
}

t_vec2	*get_perspective(t_vec3 start, t_vec3 end, t_mlx *mlx)
{
	t_vec2	*screen;
	double	w;
	double	plane;

	rotate_x(&start, &end, 3 * (-45 * DEG_2_RAD));
	screen = malloc(sizeof(*screen) * 2);
	plane = max(max(mlx->map->max_height_y, mlx->map->min_height_y), \
	max(mlx->map->width_x, mlx->map->length_z));
	w = start.z + plane;
	screen[0].x = start.x / w;
	screen[0].y = start.y / w;
	screen[0].color = start.color;
	w = end.z + plane;
	screen[1].x = end.x / w;
	screen[1].y = end.y / w;
	screen[1].color = end.color;
	scale(plane, &screen[0], &screen[1]);
	return (screen);
}
