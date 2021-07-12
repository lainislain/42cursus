/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpointalgo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:52:32 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/12 19:06:56 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *str)
{
	unsigned long long	num;
	int					sign;
	int					i;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == '\n'
		|| str[i] == '\t'
		|| str[i] == '\r'
		|| str[i] == '\v'
		|| str[i] == '\f'
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	return (num * sign);
}

void	ft_midpoint_algo(t_state *state)
{
	if (ft_len_pile(state->pile_a) == 3)
		mini_sort(state);
	while (!pile_is_sorted(state->pile_a)
		|| ft_len_pile(state->pile_a) != state->size)
	{
		if (pile_is_sorted(state->pile_a) && !state->pile_b)
			return ;
		else
		{
			if (!pile_is_sorted(state->pile_a))
				ft_pushrot(state, 1);
			else
				ft_rev_pushrot(state);
		}
	}
}

void	print_state(t_state *state)
{
	t_pile	*tmp;

	tmp = state->pile_a;
	ft_putstr_fd("===> Pile A:\n", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putstr_fd("   ", 1);
		ft_putnbr_fd(tmp->partition, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	tmp = state->pile_b;
	ft_putstr_fd("===> Pile B:\n", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putstr_fd("   ", 1);
		ft_putnbr_fd(tmp->partition, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}

void	ft_check_instruct(t_state *state, char *str)
{
	if (ft_strncmp("sa", str, 2) && ft_strncmp("sb", str, 2) \
	&& ft_strncmp("ss", str, 2) && ft_strncmp("pa", str, 2) \
	&& ft_strncmp("pb", str, 2) && ft_strncmp("ra", str, 2) \
	&& ft_strncmp("rb", str, 2) && ft_strncmp("rr", str, 2) \
	&& ft_strncmp("rra", str, 3) && ft_strncmp("rrb", str, 3) \
	&& ft_strncmp("rrr", str, 3))
	{
		ft_putstr_fd("Error\n", 1);
		exit_state(state);
	}
}

int	check_duplicate(t_state *state, int n)
{
	t_pile	*tmp;

	tmp = state->pile_a;
	while (tmp)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
