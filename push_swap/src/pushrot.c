/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:52:32 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/06 15:52:32 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_instruct(t_state *state, char *str)
{
	if (ft_strncmp("sa", str, 2) && ft_strncmp("sb", str, 2)
		&& ft_strncmp("ss", str, 2) && ft_strncmp("pa", str, 2)
		&& ft_strncmp("pb", str, 2) && ft_strncmp("ra", str, 2)
		&& ft_strncmp("rb", str, 2) && ft_strncmp("rr", str, 2)
		&& ft_strncmp("rra", str, 3) && ft_strncmp("rrb", str, 3)
		&& ft_strncmp("rrr", str, 3))
		exit_state(state);
}

int	ft_len_pile(t_pile *pile)
{
	int	len;
    t_pile *tmp;

	tmp = pile;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_lastinpile_a(t_state *state)
{
	t_pile	*tmp;

	tmp = state->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	ft_len_partition(t_pile *pile, int part)
{
	int	len;
    t_pile	*tmp;

	len = 0;
    tmp = pile;
	while (tmp && tmp->partition == part)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	ft_check_inf(t_pile *pile, int midpoint)
{
	int		part;
    t_pile	*tmp;

	tmp = pile;
    part = pile->partition;
	while (tmp && tmp->partition == part)
	{
		if (tmp->value < midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_sup(t_pile *pile, int midpoint)
{
	int		part;
	t_pile	*tmp;

	part = pile->partition;
	tmp = pile;
	while (tmp && tmp->partition == part)
	{
		if (tmp->value > midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	mini_sort(t_state *state)
{
	int	x;
	int	y;
	int	z;

	x = state->pile_a->value;
	y = state->pile_a->next->value;
    z = state->pile_a->next->next->value;
    if (x < y && y < z)
        return ;
	else if (x > y && y < x && x < z)
    {
		sa(state, 0);
        ft_putstr_fd("sa\n", 1);
    }
	else if ((x > y && y > z && x > y) ||
            (x < y && y > z && x < z))
	{
		sa(state, 0);
		rra(state, 0);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	else if (x > y && y < z && x > z)
    {
		ra(state, 0);
        ft_putstr_fd("ra\n", 1);
    }
	else
    {
		rra(state, 0);
        ft_putstr_fd("rra\n", 1);
    }
}

int     check_duplicate(t_state *state, int n)
{
    t_pile  *tmp;

    tmp = state->pile_a;
    while (tmp)
    {
        if (tmp->value == n)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    init_state(t_state *state, int argc, char **argv)
{
    int     i;
    int     n;
    t_pile  *tmp;

    i = 0;
    argc--;
    argv++;
    state->size = argc;
    state->pile_b = NULL;
    state->pile_a = NULL;
    while(i < argc)
    {
        n = ft_atoi(*argv);
        if(!ft_isnum(*argv) || check_duplicate(state, n))
        {
            ft_putstr_fd("Error\n", 1);
            exit_state(state);
        }
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = n;
        tmp->partition = 0;
        tmp->next = NULL;
        add_back_pile(&state->pile_a, tmp);
        argv++;
        i++;
    }
}