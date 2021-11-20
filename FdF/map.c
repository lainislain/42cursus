#include "fdf.h"

int		count_words(char *line, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if(line[i]==c)
			count++;
		i++;
	}
	return (count + 1);
}

static void	update_map_constants(int x, int y, int z, t_map *map)
{
	if (map->length_z < z)
		map->length_z = z;
	if (map->width_x < x)
		map->width_x = x;
	if (map->max_height_y < y)
		map->max_height_y = y;
	else if (map->min_height_y > y)
		map->min_height_y = y;
}

void	add_vector(char *text, int x, int z, t_map *map)
{
	char		**split;
	int			i;

	i = 0;
	map->coords[x][z].x = x;
	map->coords[x][z].z = z;
	if (ft_strrchr(text, ','))
	{
		split = ft_split(text, ',');
		map->coords[x][z].y = ft_atoi(split[0]);
		map->coords[x][z].color = ft_atoi_base(split[1], "0123456789abcdef");
		while (split[i])
			free(split[i++]);
		free(split);
	}
	else
	{
		map->coords[x][z].y = ft_atoi(text);
		map->coords[x][z].color = create_trgb(0, 255, 255, 255);
	}
	update_map_constants(x, map->coords[x][z].y, z, map);
}

t_map	*alloc_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(*map));
	if (!map)
		return (NULL);
	map->coords = NULL;
	map->length_z = 0;
	map->width_x = 0;
	map->max_height_y = 0;
	map->min_height_y = 0;
	return (map);
}

t_map	*init_map(t_list *prms)
{
	t_map	*map;
	char	**split;
	int		index[2];

	map = alloc_map();
	if (!prms || !map)
		return (NULL);
	map->coords = init_coordinates(get_width(prms), ft_lstsize(prms));
	index[1] = 0;
	while (prms)
	{
		split = ft_split(prms->content, ' ');
		index[0] = 0;
		while (split[index[0]])
		{
			add_vector(split[index[0]], index[0], index[1], map);
			index[0]++;
		}
		free_2d_array(split);
		prms = ft_lstnext(prms);
		index[1]++;
	}
	center_to_origin(map);
	return (map);
}

void	list_params(int fd, t_list **list)
{
	char	*line;
	int		line_length;

	line = get_next_line(fd);
	remove_breakline(line);
	line_length = count_words(line, ' ');
	*list = ft_lstnew(ft_strdup(line));
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_breakline(line);
		if (line_length != count_words(line, ' '))
		{
			ft_lstclear(list, free);
			free(line);
			return ;
		}
		ft_lstadd_back(list, ft_lstnew(ft_strdup(line)));
		free(line);
	}
}
