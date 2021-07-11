/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:31 by amaghat           #+#    #+#             */
/*   Updated: 2021/07/11 13:16:11 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_state
{
	char	current_char;
	int		current_bit;
}				t_state;

int			ft_isdigit(int c);
int			ft_isnum(char *str);
void		ft_putnbr(int nb);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_strlen(const char *s);
int			ft_atoi(const char *s);
int			signal_sender(char c, pid_t pid);
void		signal_handler(int sig);
#endif