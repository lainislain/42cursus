/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:26:14 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/09 19:26:14 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_pile(t_pile *pile)
{
	int		len;
	t_pile	*tmp;

	tmp = pile;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_len_partition(t_pile *pile)
{
	int		len;
	int		part;
	t_pile	*tmp;

	len = 0;
	tmp = pile;
	part = pile->partition;
	while (tmp && tmp->partition == part)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_check_inf(t_pile *pile, int midpoint)
{
	int		part;
	t_pile	*tmp;

	tmp = pile;
	part = pile->partition;
	while (tmp && tmp->partition == part)
	{
		if (tmp->value < midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_sup(t_pile *pile, int midpoint)
{
	int		part;
	t_pile	*tmp;

	part = pile->partition;
	tmp = pile;
	while (tmp && tmp->partition == part)
	{
		if (tmp->value > midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	mini_sort(t_state *state)
{
	int	x;
	int	y;
	int	z;

	x = state->pile_a->value;
	y = state->pile_a->next->value;
	z = state->pile_a->next->next->value;
	if (x < y && y < z)
		return ;
	else if (x > y && y < x && x < z)
		sa(state, 0);
	else if ((x > y && y > z && x > y)
		|| (x < y && y > z && x < z))
	{
		sa(state, 0);
		rra(state, 0);
	}
	else if (x > y && y < z && x > z)
		ra(state, 0);
	else
		rra(state, 0);
}
