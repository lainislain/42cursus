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

void    sa(t_state *state, int check)
{
    int     tmp;

    if(state->pile_a && state->pile_a->next)
    {
        tmp = state->pile_a->value;
        state->pile_a->value = state->pile_a->next->value;
        state->pile_a->next->value = tmp;
    }
    if (!check)
        ft_putstr_fd("sa\n", 1);
}

void    sb(t_state *state, int check)
{
    int     tmp;

    if(state->pile_b && state->pile_b->next)
    {
        tmp = state->pile_b->value;
        state->pile_b->value = state->pile_b->next->value;
        state->pile_b->next->value = tmp;
    }
    if (!check)
        ft_putstr_fd("sb\n", 1);
}

void    ss(t_state *state, int check)
{
    sa(state, 1);
    sb(state, 1);
    if (!check)
        ft_putstr_fd("ss\n", 1);
}

void    pa(t_state *state, int check)
{
    t_pile  *tmp;

    if(!state->pile_b)
        return ;
    tmp = state->pile_b;
	state->pile_b = state->pile_b->next;
	tmp->next = state->pile_a;
	state->pile_a = tmp;
    if (!check)
        ft_putstr_fd("pa\n", 1);
}

void    pb(t_state *state, int check)
{
    t_pile  *tmp;

    if(!state->pile_a)
        return ;
    tmp = state->pile_a;
	state->pile_a = state->pile_a->next;
	tmp->next = state->pile_b;
	state->pile_b = tmp;
    if (!check)
        ft_putstr_fd("pb\n", 1);
}