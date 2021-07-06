/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:14 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:14 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_midpoint_algo(t_state *state)
{
	if (!state->pile_a && pile_is_sorted(state->pile_a) && !state->pile_b)
		return ;
	if (ft_len_pile(state->pile_a) == 3)
		mini_sort(state);
	else
	{
		ft_pushrot(state, 1);
		ft_rev_pushrot(state);
	}
}

void    print_state(t_state *state)
{
    t_pile      *tmp;
    int         i;

    tmp = state->pile_a;
    printf("===> Pile A: %d\n", pile_is_sorted(state->pile_a));
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
    tmp = state->pile_b;
    printf("===> Pile B: %d\n", pile_is_sorted(state->pile_b));
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
}

int     main(int argc, char **argv)
{
    t_state     state;
    t_pile      *tmp;
    int         i;

    i = 0;
    init_state(&state, argc, argv);
    if (state.pile_a)
    {
        ft_midpoint_algo(&state);
        exit_state(&state);
    }

    //mini_sort(&state);
    //print_state(&state);
    return (0);
}