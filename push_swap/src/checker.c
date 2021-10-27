/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:25:34 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/11 14:09:06 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_state		checker;
	char		*instructs;

	if (ac)
	{
		init_state(&checker, ac, av);
		instructs = ft_read_instructs(&checker);
		checker.instructs = ft_split(instructs, ' ');
		free(instructs);
		ft_exec_instructs(&checker);
		ft_checker(&checker);
		exit_state(&checker);
	}
	return (0);
}

char	*ft_read_instructs(t_state *checker)
{
	char	*instruct;
	char	*instructs;
	char	*tmp;

	instructs = ft_strdup("");
	while (1)
	{
		instruct = ft_read_instruct();
		if (!*instruct)
			break ;
		ft_check_instruct(checker, instruct);
		tmp = ft_strjoin(instructs, instruct);
		free(instruct);
		free(instructs);
		instructs = tmp;
		tmp = ft_strjoin(instructs, " ");
		free(instructs);
		instructs = tmp;
	}
	free(instruct);
	return (instructs);
}

char	*ft_read_instruct(void)
{
	int		n;
	char	i;
	char	*instruct;

	i = -1;
	instruct = (char *)malloc(sizeof(char) * 6);
	while (1)
	{
		n = read(0, instruct + (++i), 1);
		if (!*(instruct + i) || *(instruct + i) == '\n' || n < 1 || n > 6)
			break ;
	}
	*(instruct + i) = '\0';
	return (instruct);
}

void	ft_exec_instructs(t_state *checker)
{
	char	**instructs;

	instructs = checker->instructs;
	while (*instructs)
	{
		if (!ft_strncmp("sa", *instructs, 2))
			sa(checker, 1);
		else if (!ft_strncmp("sb", *instructs, 2))
			sb(checker, 1);
		else if (!ft_strncmp("pa", *instructs, 2))
			pa(checker, 1);
		else if (!ft_strncmp("pb", *instructs, 2))
			pb(checker, 1);
		else if (!ft_strncmp("ra", *instructs, 2))
			ra(checker, 1);
		else if (!ft_strncmp("rb", *instructs, 2))
			rb(checker, 1);
		else if (!ft_strncmp("rra", *instructs, 3))
			rra(checker, 1);
		else if (!ft_strncmp("rrb", *instructs, 3))
			rrb(checker, 1);
		instructs++;
	}
}

void	ft_checker(t_state *checker)
{
	if (checker->pile_b || !pile_is_sorted(checker->pile_a))
	{
		ft_putstr_fd("KO\n", 1);
		exit_state(checker);
	}
	ft_putstr_fd("OK\n", 1);
}
