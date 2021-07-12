/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revpushrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:06:24 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/12 19:41:04 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_shunk(t_state *state, t_pile *tmp)
{
	if (tmp->next && tmp->value < tmp->next->value)
		sb(state, 0);
	pa(state, 0);
	pa(state, 0);
}

void	iter_btoa(t_state *state)
{
	int	midpoint;
	int	nrb;

	nrb = 0;
	midpoint = ft_find_midpoint(state->pile_b);
	while (ft_check_sup(state->pile_b, midpoint))
	{
		if (state->pile_b->value > midpoint)
		{
			pa(state, 0);
			state->pile_a->partition++;
			state->pile_a->partition++;
		}
		else
		{
			rb(state, 0);
			nrb++;
		}
	}
	while (nrb--)
		rrb(state, 0);
	ft_pushrot(state, 0);
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
		{
			finish_shunk(state, tmp);
			tmp = state->pile_b;
		}
		else
		{
			iter_btoa(state);
			tmp = state->pile_b;
		}
		if (tmp)
			tmp = tmp->next;
	}
}
