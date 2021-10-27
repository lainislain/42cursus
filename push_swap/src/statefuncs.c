/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statefuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:52:14 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/12 20:55:58 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_state_condition(t_state *state, long long n, char **argv)
{
	if (!ft_isnum(*argv)
		|| check_duplicate(state, n) || n > INT_MAX || n < INT_MIN)
	{
		ft_putstr_fd("Error\n", 1);
		exit_state(state);
	}
}

void	init_state(t_state *state, int argc, char **argv)
{
	int			i;
	long long	n;
	t_pile		*tmp;

	i = 0;
	argc--;
	argv++;
	state->size = argc;
	state->pile_b = NULL;
	state->pile_a = NULL;
	while (i < argc)
	{
		n = ft_atol(*argv);
		init_state_condition(state, n, argv);
		tmp = (t_pile *)malloc(sizeof(t_pile));
		tmp->value = (int)n;
		tmp->partition = 0;
		tmp->next = NULL;
		add_back_pile(&state->pile_a, tmp);
		argv++;
		i++;
	}
}

int	pile_is_sorted(t_pile *pile)
{
	t_pile	*tmp;

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

int	part_is_sorted(t_pile *pile)
{
	int		part;
	t_pile	*tmp;

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

void	exit_state(t_state *state)
{
	t_pile	*tmp;
	t_pile	*loop;

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
