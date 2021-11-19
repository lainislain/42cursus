#include "fdf.h"

void	scale(float factor, t_vec2 *start, t_vec2 *end)
{
	start->x *= factor;
	start->y *= factor;
	end->x *= factor;
	end->y *= factor;
}

void	translate(t_vec2 *start, t_vec2 *end, float move_x, float move_y)
{
	start->x += move_x;
	start->y += move_y;
	end->x += move_x;
	end->y += move_y;
}

void	rotate_x(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->z * cos(rad_ang) - start->y * sin(rad_ang);
	b = start->z * sin(rad_ang) + start->y * cos(rad_ang);
	start->y = a;
	start->z = b;
	a = end->z * cos(rad_ang) - end->y * sin(rad_ang);
	b = end->z * sin(rad_ang) + end->y * cos(rad_ang);
	end->y = a;
	end->z = b;
}

void	rotate_y(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->x * cos(rad_ang) - start->z * sin(rad_ang);
	b = start->x * sin(rad_ang) + start->z * cos(rad_ang);
	start->x = a;
	start->z = b;
	a = end->x * cos(rad_ang) - end->z * sin(rad_ang);
	b = end->x * sin(rad_ang) + end->z * cos(rad_ang);
	end->x = a;
	end->z = b;
}

void	rotate_z(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->x * cos(rad_ang) - start->y * sin(rad_ang);
	b = start->x * sin(rad_ang) + start->y * cos(rad_ang);
	start->x = a;
	start->y = b;
	a = end->x * cos(rad_ang) - end->y * sin(rad_ang);
	b = end->x * sin(rad_ang) + end->y * cos(rad_ang);
	end->x = a;
	end->y = b;
}
