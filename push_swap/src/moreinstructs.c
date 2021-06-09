/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreinstructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:29 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:29 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_state *state)
{
    t_pile	*tmp;
	t_pile	*first;

	if (state->pile_a && state->pile_a->next)
	{
		first = state->pile_a;
		state->pile_a = state->pile_a->next;
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		tmp->next->next = NULL;
	}
}

void    rb(t_state *state)
{
    t_pile	*tmp;
	t_pile	*first;

	if (state->pile_b && state->pile_b->next)
	{
		first = state->pile_b;
		state->pile_b = state->pile_b->next;
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		tmp->next->next = NULL;
	}
}

void    rr(t_state *state)
{
    ra(state);
    rb(state);
}

void    rra(t_state *state)
{
    t_pile	*tmp;
	t_pile	*last;

    if (state->pile_a && state->pile_a->next)
	{
		tmp = state->pile_a;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = state->pile_a;
		state->pile_a = last;
	}
}

void    rrb(t_state *state)
{
    t_pile	*tmp;
	t_pile	*last;

    if (state->pile_b && state->pile_b->next)
	{
		tmp = state->pile_b;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = state->pile_b;
		state->pile_b = last;
	}
}