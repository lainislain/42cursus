/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:25:24 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/06 13:25:24 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_find_midpoint(t_pile *pile)
{
	int	len;
    int part;
	int	*array;
	int	i;
	int	midpoint;
    t_pile *tmp;

	i = 0;
    tmp = pile;
	part = pile->partition;
	len = ft_len_pile(pile);
	array = (int *)malloc(sizeof(int) * len);
	while (tmp && tmp->partition == part)
	{
		array[i++] = tmp->value;
		tmp = tmp->next;
	}
	bubble_sort(array, len);
	midpoint = array[len / 2];
	free(array);
	return (midpoint);
}

void	ft_rev_pushrot(t_state *state)
{
    t_pile  *tmp;

    tmp = state->pile_b;
	while (tmp)
	{
		if (ft_len_partition(tmp, tmp->partition) == 1)
			pa(state);
		else if (ft_len_partition(tmp, tmp->partition) == 2)
		{
			if (tmp->value <= tmp->next->value)
				sb(state);
			pa(state);
			pa(state);
		}
		else
			ft_revmidpointalgo(state);
	}
}

void	ft_pushrot(t_state *state, int rot)
{
	int	midpoint;
	int	part;
    int nra;

	part = state->pile_a->partition;
	while (!part_is_sorted(state->pile_a) && ft_len_partition(state->pile_a, state->pile_a->partition) > 2)
	{
		part++;
		nra = 0;
		midpoint = ft_find_midpoint(state->pile_a);
		while (ft_check_inf(state->pile_a, midpoint))
		{
			if (ft_midpointalgo(state, midpoint, part))
			{
				ra(state);
				nra++;
			}
		}
		while (!rot && nra--)
			rra(state);
	}
	if (!part_is_sorted(state->pile_a))
		sa(state);
}

int     ft_midpointalgo(t_state *state, int midpoint, int part)
{
	if (state->pile_a->value < midpoint)
	{
		pb(state);
		state->pile_b->partition = part;
		return (0);
	}
	return (1);
}

void	ft_revmidpointalgo(t_state *state)
{
	int	midpoint;
	int	nrb;

	nrb = 0;
	midpoint = ft_find_midpoint(state->pile_b);
	while (ft_check_sup(state->pile_b, midpoint))
	{
		if (state->pile_b->value > midpoint)
		{
			pa(state);
			state->pile_a->partition++;
			state->pile_a->partition++;
		}
		else
		{
			rb(state);
			nrb++;
		}
	}
	while (nrb--)
		rrb(state);
	ft_pushrot(state, 0);
}
