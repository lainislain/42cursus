#include "fdf.h"

float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	center_to_origin(t_map *map)
{
	int	x;
	int	z;

	z = 0;
	while (z < map->length_z)
	{
		x = 0;
		while (x < map->width_x)
		{
			map->coords[x][z].x -= map->width_x / 2;
			map->coords[x][z].z -= map->length_z / 2;
			x++;
		}
		z++;
	}
}
