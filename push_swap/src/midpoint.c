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
	len = ft_len_partition(pile);
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
	int	part;

    tmp = state->pile_b;
	part = tmp->partition;
	//ft_putstr_fd("=> B to A\n", 1);
	while (tmp && tmp->partition == part)
	{
		if (ft_len_partition(state->pile_b) == 1)
		{
			pa(state, 0);
			tmp = state->pile_b;
		}
		else if (ft_len_partition(state->pile_b) == 2)
		{
			if (tmp->next && tmp->value < tmp->next->value)
				sb(state, 0);
			pa(state, 0);
			pa(state, 0);
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
	//print_state(state);
}

void	ft_pushrot(t_state *state, int rot)
{
	int	midpoint;
	int	part;
    int nra;

	//ft_putstr_fd("=> A to B\n", 1);
	part = state->pile_a->partition;
	while (!pile_is_sorted(state->pile_a) && ft_len_partition(state->pile_a) > 2)
	{
		part++;
		nra = 0;
		midpoint = ft_find_midpoint(state->pile_a);
		while (ft_check_inf(state->pile_a, midpoint))
		{
			if (iter_atob(state, midpoint, part))
			{
				ra(state, 0);
				nra++;
			}
		}
		while (!rot && nra--)
			rra(state, 0);
	}
	if (!part_is_sorted(state->pile_a) && ft_len_partition(state->pile_a) == 2)
	{
		//ft_putstr_fd("===> HELLO\n", 1);	
		sa(state, 0);
	}
	//print_state(state);
}

int     iter_atob(t_state *state, int midpoint, int part)
{
	if (state->pile_a->value < midpoint)
	{
		pb(state, 0);
		state->pile_b->partition = part;
		return (0);
	}
	return (1);
}

void	iter_btoa(t_state *state)
{
	int	midpoint;
	int	nrb;

	nrb = 0;
	midpoint = ft_find_midpoint(state->pile_b);
	//ft_putstr_fd("===> midpoint:\n", 1);
	//ft_putnbr_fd(midpoint, 1);
	//ft_putstr_fd("\n", 1);
	while (ft_check_sup(state->pile_b, midpoint))
	{
		if (state->pile_b->value > midpoint)
		{
				//ft_putstr_fd("===> sup:\n", 1);
				//ft_putnbr_fd(state->pile_b->value, 1);
				//ft_putstr_fd("\n", 1);
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
	//ft_putstr_fd("===> HELLO\n", 1);
}
