/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_pushrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:06:24 by aabounak          #+#    #+#             */
/*   Updated: 2021/07/10 13:06:33 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	XXX(t_state *state, t_pile *tmp)
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
		{
			// tRY if this works if it does then the file is normed.
			XXX(state, tmp);
			// if (tmp->next && tmp->value < tmp->next->value)
			// 	sb(state, 0);
			// pa(state, 0);
			// pa(state, 0);
			// tmp = state->pile_b;
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
