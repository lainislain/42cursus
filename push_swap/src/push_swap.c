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
    printf("===> Array:\n");
    i = 0;
    while (i < state->size)
    {
        printf("%d\n",state->array[i]);
        i++;
    }
    printf("===> Midpoint is: %d\n", state->array[state->size / 2 ]);
}

int     main(int argc, char **argv)
{
    t_state     state;
    t_pile      *tmp;
    int         i;

    i = 0;
    init_state(&state, argc, argv);
    while(i < 5)
    {
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = i;
        tmp->next = NULL;
        add_back_pile(&(&state)->pile_b, tmp);
        i++;
    }
    //bubble_sort(state.array, state.size);
    mini_sort(&state);
    //print_state(&state);
    return (0);
}