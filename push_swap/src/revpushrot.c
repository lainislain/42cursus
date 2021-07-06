/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revpushrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:52:14 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/06 15:52:14 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     pile_is_sorted(t_pile* pile)
{
    t_pile  *tmp;

    if (!pile)
        return (0);
    tmp = pile;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int     part_is_sorted(t_pile* pile)
{
    int     part;
    t_pile  *tmp;

    if (!pile)
        return (0);
    tmp = pile;
    part = pile->partition;
    while (tmp->next && tmp->partition == part)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    exit_state(t_state *state)
{
    t_pile  *tmp;
    t_pile  *loop;

    loop = state->pile_a;
    while (loop)
    {
        tmp = loop;
        loop = loop->next;
        free(tmp);
    }
    loop = state->pile_b;
    while (loop)
    {
        tmp = loop;
        loop = loop->next;
        free(tmp);
    }
    exit(0);
}

void    next_state(t_state *state)
{
    t_pile  *tmp;
    int     *array;
    int     midpoint;

    return ;
}