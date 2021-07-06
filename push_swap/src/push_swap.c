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

void	ft_check_instruct(t_state *state, char *str)
{
	if (ft_strcmp("sa", str) && ft_strcmp("sb", str)
		&& ft_strcmp("ss", str) && ft_strcmp("pa", str)
		&& ft_strcmp("pb", str) && ft_strcmp("ra", str)
		&& ft_strcmp("rb", str) && ft_strcmp("rr", str)
		&& ft_strcmp("rra", str) && ft_strcmp("rrb", str)
		&& ft_strcmp("rrr", str))
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

int	ft_len_partition(t_state *state, int part)
{
	int	len;
    t_pile	*tmp;

	len = 0;
    tmp = state->pile_a;
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
	if (x > y && y < x && x < z)
		sa(state);
	else if ((x > y && y > z && x > y) ||
            (x < y && y > z && x < z))
	{
		sa(state);
		rra(state);
	}
	else if (x > y && y < z && x > z)
		ra(state);
	else
		rra(state);
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
    state->n_parts = 1;
    state->array = (int*)malloc(sizeof(int) * argc);
    while(i < argc)
    {
        n = ft_atoi(*argv);
        if(!ft_isnum(*argv) || check_duplicate(state, n))
            exit_state(state);
        state->array[i] = n;
        tmp = (t_pile*)malloc(sizeof(t_pile));
        tmp->value = n;
        tmp->partition = 0;
        tmp->next = NULL;
        add_back_pile(&state->pile_a, tmp);
        argv++;
        i++;
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
    printf("===> Array:\n");
    i = 0;
    while (i < state->size)
    {
        printf("%d\n",state->array[i]);
        i++;
    }
    printf("===> Midpoint is: %d\n", state->array[state->size / 2 ]);
}

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
    write(1, "Error\n", 6);
    exit(0);
}

void    next_state(t_state *state)
{
    t_pile  *tmp;
    int     *array;
    int     midpoint;

    return ;
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
    bubble_sort(state.array, state.size);
    mini_sort(&state);
    print_state(&state);
    return (0);
}