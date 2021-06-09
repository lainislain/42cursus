/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:34 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:34 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_state *state)
{
    int     tmp;

    if(state->pile_a && state->pile_a->next)
    {
        tmp = state->pile_a->value;
        state->pile_a->value = state->pile_a->next->value;
        state->pile_a->next->value = tmp;
    }
}

void    sb(t_state *state)
{
    int     tmp;

    if(state->pile_b && state->pile_b->next)
    {
        tmp = state->pile_b->value;
        state->pile_b->value = state->pile_b->next->value;
        state->pile_b->next->value = tmp;
    }
}

void    ss(t_state *state)
{
    sa(state);
    sb(state);
}

void    pa(t_state *state)
{
    t_pile  *tmp;

    if(!state->pile_b)
        return ;
    tmp = state->pile_b;
	state->pile_b = state->pile_b->next;
	tmp->next = state->pile_a;
	state->pile_a = tmp;
}

void    pb(t_state *state)
{
    t_pile  *tmp;

    if(!state->pile_a)
        return ;
    tmp = state->pile_a;
	state->pile_a = state->pile_a->next;
	tmp->next = state->pile_b;
	state->pile_b = tmp;
}