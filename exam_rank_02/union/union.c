/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:10:40 by amaghat           #+#    #+#             */
/*   Updated: 2021/02/25 15:34:49 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int
	main(int argc, char **argv)
{
	int	ascii[255];
	int	i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			ascii[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ascii[(int)argv[i][j]])
				{
					ascii[(int)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
