#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		flag;
	char	*line;

	while ((flag = get_next_line(&line)) > 0)
	{
		printf("%d - ", flag);
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%d - ", flag);
	printf("%s", line);
	free(line);
	line = NULL;
	return (0);
}