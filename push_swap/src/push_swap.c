/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:14 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:14 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	state;

	init_state(&state, argc, argv);
	if (state.pile_a)
	{
		ft_midpoint_algo(&state);
		exit_state(&state);
	}
	return (0);
}
