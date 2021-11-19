#include "fdf.h"

void	fdf_init(int fd)
{
	t_map	*map;
	t_list	*list;

	list_params(fd, &list);
	map = init_map(list);
	ft_lstclear(&list, free);
	if (!map)
		write(1, "Bad format or allocation error\n", 32);
	else
		init_mlx(map);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		write(1, "Wrong usage: ./fdf [relative file path]", 40);
	else
	{
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			write(1, "Unexpected file", 16);
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd <= 0)
				write(1, "Failed to open file", 20);
			else
				fdf_init(fd);
			close(fd);
		}
	}
	return (1);
}
