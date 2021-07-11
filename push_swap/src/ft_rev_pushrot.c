/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_pushrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:06:24 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/11 14:03:13 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_shunk(t_state *state, t_pile *tmp)
{
	if (tmp->next && tmp->value < tmp->next->value)
		sb(state, 0);
	pa(state, 0);
	pa(state, 0);
	tmp = state->pile_b;
}

void	ft_rev_pushrot(t_state *state)
{
	t_pile	*tmp;
	int		part;

	tmp = state->pile_b;
	part = tmp->partition;
	while (tmp && tmp->partition == part)
	{
		if (ft_len_partition(state->pile_b) == 1)
		{
			pa(state, 0);
			tmp = state->pile_b;
		}
		else if (ft_len_partition(state->pile_b) == 2)
			finish_shunk(state, tmp);

		else
		{
			iter_btoa(state);
			tmp = state->pile_b;
		}
		if (tmp)
			tmp = tmp->next;
	}
}
