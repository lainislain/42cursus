/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:43 by amaghat           #+#    #+#             */
/*   Updated: 2021/06/09 04:01:43 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bubble_sort(int arr[], int n)
{
   int      i;
   int      j;
   int      tmp;
   
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
           {
               tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
           }
}

void    rrr(t_state *state)
{
    rra(state);
    rrb(state);
}

int     ft_issign(char c)
{
    if (c == '+' || c == '-' || ft_isdigit(c))
        return (1);
    else
        return (0);
}

int     ft_isnum(char *str)
{
    int     i;
    int     n;

    if (!str || !str[0] || !ft_issign(str[0]))
        return (0);
    i = 1;
    n = ft_strlen(str);
    while (i < n)
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void    add_back_pile(t_pile **pile, t_pile *stack)
{
    t_pile  *tmp;

    if(!pile)
    {
        pile = (t_pile**)stack;
        return ;
    }
    tmp = (t_pile*)pile;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = stack;
}