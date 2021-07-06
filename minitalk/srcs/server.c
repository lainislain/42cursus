/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:51:58 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/05 18:05:38 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_state	state;

void	signal_handler(int sig)
{	
	state.current_bit++;
	state.current_char = state.current_char << 1;
	if (sig == SIGUSR1)
		state.current_char = state.current_char | 1;
	else if (sig == SIGUSR2)
		state.current_char = state.current_char | 0;
	if (state.current_bit == 8)
	{
		write (1, &state.current_char, 1);
		state.current_bit = 0;
		state.current_char = 0;
	}
}

int	main(void)
{
	state.current_bit = 0;
	state.current_char = 0;
	signal (SIGUSR1, signal_handler);
	signal (SIGUSR2, signal_handler);
	ft_putstr_fd("=> Server PID is ", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}