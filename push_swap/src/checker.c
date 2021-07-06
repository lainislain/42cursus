/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:25:34 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/06 14:25:34 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_state		checker;
	char		*instructs;

	if (ac)
	{
		checker.pile_a = ft_init_state(&checker, ac, av);
		checker.pile_b = NULL;
		instructs = ft_read_instructs(&checker);
		checker.instructs = ft_split(instructs, ' ');
		free(instructs);
		ft_exec_instructs(&checker);
		ft_checker(&checker);
		ft_free(&checker);
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
		if (!ft_strcmp("sa", *instructs))
            sa(checker);
        else if (!ft_strcmp("sb", *instructs))
            sb(checker);
		else if (!ft_strcmp("pa", *instructs))
			pa(checker);
		else if (!ft_strcmp("pb", *instructs))
			pb(checker);
		else if (!ft_strcmp("ra", *instructs))
			ra(checker);
		else if (!ft_strcmp("rb", *instructs))
			rb(checker);
        else if (!ft_strcmp("rra", *instructs))
			rra(checker);
        else if (!ft_strcmp("rrb", *instructs))
			rrb(checker);
        else if (!ft_strcmp("rr", *instructs))
			rr(checker);
        else if (!ft_strcmp("rrr", *instructs))
			rrr(checker);
		instructs++;
	}
}

void	ft_checker(t_state *checker)
{
	if (checker->pile_b || !ft_is_sorted(checker->pile_a))
	{
		ft_putstr("KO\n");
		exit_state(checker);
	}
	ft_putstr("OK\n");
}