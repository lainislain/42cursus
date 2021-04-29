/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:10:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/04/25 15:32:49 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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