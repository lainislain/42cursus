/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 04:01:43 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/11 13:58:54 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	rrr(t_state *state, int check)
{
	rra(state, 1);
	rrb(state, 1);
	if (!check)
		ft_putstr_fd("rrr\n", 1);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	else
		return (0);
}

int	ft_isnum(char *str)
{
	int	i;
	int	n;

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

void	add_back_pile(t_pile **pile, t_pile *stack)
{
	t_pile	*tmp;

	if (!pile)
	{
		pile = (t_pile **)stack;
		return ;
	}
	tmp = (t_pile *)pile;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack;
}
