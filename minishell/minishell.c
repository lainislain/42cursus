/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:09:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/09/17 14:22:41 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_env.child_flag == 0)
		{
			ft_putchar_fd('\n', 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
		if (g_env.child_flag == 0)
			set_env("?", "1");
	}
	else if (sig == SIGQUIT)
	{
		ft_putchar_fd('\r', 1);
		rl_on_new_line();
	}
}

void	terminal_view(void)
{
	static int	first_time = 1;
	char		*line;

	while (1)
	{
		g_env.child_flag = 0;
		if (first_time)
		{
			clear_window();
			first_time = 0;
		}
		line = read_line();
		if (empty_line(line) == 0)
		{
			extract_semicolon_line(line);
		}
		else
			free(line);
	}
}

void	free_env(void)
{
	int		i;

	i = -1;
	while (g_env.env[++i])
	{
		free(g_env.env[i]);
		free(g_env.sorted[i]);
		g_env.env[i] = NULL;
		g_env.sorted[i] = NULL;
	}
	free(g_env.env);
	free(g_env.sorted);
	g_env.env = NULL;
	g_env.sorted = NULL;
}

void	minishell(int argc, char *argv[], char *envp[])
{	
	if (argv[1] != NULL || argc != 1)
	{
		ft_error("Arguments", 1);
	}
	init_env(envp);
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
	terminal_view();
	free_env();
}
